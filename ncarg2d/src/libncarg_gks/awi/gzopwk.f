C
C	$Id: gzopwk.f,v 1.3 2000-07-12 16:40:05 haley Exp $
C                                                                      
C                Copyright (C)  2000
C        University Corporation for Atmospheric Research
C                All Rights Reserved
C
C This file is free software; you can redistribute it and/or modify
C it under the terms of the GNU Lesser General Public License as
C published by the Free Software Foundation; either version 2.1 of the
C License, or (at your option) any later version.
C
C This software is distributed in the hope that it will be useful, but
C WITHOUT ANY WARRANTY; without even the implied warranty of
C MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
C Lesser General Public License for more details.
C
C You should have received a copy of the GNU Lesser General Public
C License along with this software; if not, write to the Free Software
C Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
C USA.
C
      SUBROUTINE GZOPWK(WKID,CONID,WTYPE)
C
C  OPEN WORKSTATION
C
      INTEGER EOPWK
      PARAMETER (EOPWK=2)
C
      include 'gkscom.h'
C
      INTEGER WKID,CONID,WTYPE
      INTEGER LASF(13)
C
C  Check that GKS is in the proper state.
C
      CALL GZCKST(8,EOPWK,IER)
      IF (IER .NE. 0) RETURN
C
C  Check if the workstation identifier is valid.
C
      CALL GZCKWK(20,EOPWK,WKID,IDUM,IER)
      IF (IER .NE. 0) RETURN
C
C  Check that the connection identifier is valid.
C
      IF (CONID.EQ.5 .OR. CONID.EQ.6) THEN
        ERS = 1
        CALL GERHND(21,EOPWK,ERF)
        ERS = 0
        RETURN
      ENDIF
C
C  Check that the workstation type is valid.
C
      CALL GZCKWK(22,EOPWK,IDUM,WTYPE,IER)
      IF (IER .NE. 0) RETURN
C
C  Check if the workstation is currently open.
C
      CALL GZCKWK(24,EOPWK,WKID,WTYPE,IER)
      IF (IER .NE. 0) RETURN
C
C  Check if there is room for another open workstation.
C
      IF (NOPWK .GE. MOPWK) THEN
        ERS = 1
        CALL GERHND(26,EOPWK,ERF)
        ERS = 0
        RETURN
      ENDIF
C
C  Only one CGM workstation currently allowed.
C
      IF (WTYPE .EQ. GCGM) THEN
        DO 30 I=1,NOPWK
          IF (SWKTP(I) .EQ. GCGM) THEN
            ERS = 1
            CALL GERHND(-112,EOPWK,ERF)
            ERS = 0
            RETURN
          ENDIF
   30   CONTINUE
      ENDIF
C
C  Make sure that WISS is not already open if the workstation
C  type is WISS.
C
      IF (WTYPE .EQ. GWSS) THEN
        DO 40 I=1,NOPWK
          IF (SWKTP(I) .EQ. GWSS) THEN
            ERS = 1
            CALL GERHND(28,EOPWK,ERF)
            ERS = 0
            RETURN
          ENDIF
   40   CONTINUE
      WCONID = CONID
      ENDIF
C
C  Set the operating state to WSOP if in state GKOP.
C
      IF (OPS .EQ. GGKOP) THEN
        OPS = GWSOP
      ENDIF
C
C  Pass information across the workstation interface.
C
        FCODE = -3
        CONT  = 0
        CALL GZROI(0)
        IF (WTYPE.GE.GPSMIN .AND. WTYPE.LE.GPSMAX) THEN
          IL1   = 9
          IL2   = 9
          ID(1) = WKID
          ID(2) = CONID
          ID(3) = WTYPE
C
C  Positioning coordinates for those workstations that can use them.
C
          ID(4) = CLLX
          ID(5) = CLLY
          ID(6) = CURX
          ID(7) = CURY
C
C  Scale factor for PostScript workstations.
C
          ID(8) = CPSCL
C
C  Color model for PostScript workstations.
C
          ID(9) = CCMDL
	ELSE IF (WTYPE.EQ.GXWE .OR. WTYPE.EQ.GXWC) THEN
	  IL1   = 4
	  IL2   = 4
          ID(1) = WKID
          ID(2) = CONID
          ID(3) = WTYPE
C
C  Color model for X workstations.
C
	  ID(4) = COLMOD
        ELSE
          IL1   = 3
          IL2   = 3
          ID(1) = WKID
          ID(2) = CONID
          ID(3) = WTYPE
        ENDIF
C
        CALL GZTOWK
        IF (RERR.NE.0) THEN
          ERS = 1
          CALL GERHND(RERR,EOPWK,ERF)
          ERS = 0
          RETURN
        ENDIF
C
C  Add the workstation identifier to the set of open workstations.
C
      NOPWK = NOPWK+1
      SOPWK(NOPWK) = WKID
      SWKTP(NOPWK) = WTYPE
C
C  Set the file name for an MO workstation back to default; set the
C  positioning coordinates back to defaults; set the PostScript 
C  coordinate scale factor back to the default; set the X color model
C  back to default.
C
        GFNAME = 'DEFAULT'
        CLLX = -9999
        CLLY = -9999
        CURX = -9999
        CURY = -9999
        CPSCL = -1
        COLMOD = -1
C
C  For an X window that does not currently exist, obtain the local 
C  window ID for all future calls; for an X window that already exists
C  the connection ID is the window ID.  In the case of an X window
C  that does not exist, the window ID is returned from the interface
C  call in IL2 (non-standard usage of this parameter).  The
C  PostScript drivers are treated the same as X windows for this
C  purpose.
C
        IF (WTYPE.EQ.GXWC  .OR. WTYPE.EQ.GDMP  .OR. 
     +      WTYPE.EQ.GXWE  .OR. 
     +        (WTYPE.GE.GPSMIN .AND. WTYPE.LE.GPSMAX)) THEN
          LXWKID(NOPWK) = IL2
        ENDIF
C
C  Establish the current attribute settings (temporerily turn off
C  processing of error -109 [non-implementation of certain functions
C  on output only workstations] by setting CUFLAG non-zero).
C
        CUFLAG = WKID
        CALL GSCLIP (CCLIP)
C       CALL GSPLI  (CPLI )
        CALL GSLN   (CLN  )
        CALL GSLWSC (CLWSC)
        CALL GSPLCI (CPLCI)
C       CALL GSPMI  (CPMI )
        CALL GSMK   (CMK  )
        CALL GSMKSC (CMKS )
        CALL GSPMCI (CPMCI)
C       CALL GSTXI  (CTXI )
        CALL GSTXFP (CTXFP(1),CTXFP(2))
        CALL GSCHXP (CCHXP)
        CALL GSCHSP (CCHSP)
        CALL GSTXCI (CTXCI)
        CALL GSCHH  (CCHH )
        CALL GSCHUP (CCHUP(1),CCHUP(2))
        CALL GSTXP  (CTXP )
        CALL GSTXAL (CTXAL(1),CTXAL(2))
C       CALL GSFAI  (CFAI )
        CALL GSFAIS (CFAIS)
        CALL GSFASI (CFASI)
        CALL GSFACI (CFACI)
C       CALL GSPA   (CPA  (1),CPA  (2))
C       CALL GSPARF (CPARF(1),CPARF(2))
        LASF( 1) = CLNA
        LASF( 2) = CLWSCA
        LASF( 3) = CPLCIA
        LASF( 4) = CMKA
        LASF( 5) = CMKSA
        LASF( 6) = CPMCIA
        LASF( 7) = CTXFPA
        LASF( 8) = CCHXPA
        LASF( 9) = CCHSPA
        LASF(10) = CTXCIA
        LASF(11) = CFAISA
        LASF(12) = CFASIA
        LASF(13) = CFACIA
        CALL GSASF (LASF)
        CUFLAG = -1
C
      RETURN
      END
