C
C	$Id: gzclwk.f,v 1.2 2000-07-12 16:40:03 haley Exp $
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
      SUBROUTINE GZCLWK(WKID)
C
C  CLOSE WORKSTATION
C
      INTEGER ECLWK
      PARAMETER (ECLWK=3)
C
      include 'gkscom.h'
C
      INTEGER WKID
C
C  Check that GKS is in the proper state.
C
      CALL GZCKST(7,ECLWK,IER)
      IF (IER .NE. 0) RETURN
C
C  Check if the workstation identifier is valid.
C
      CALL GZCKWK(20,ECLWK,WKID,IDUM,IER)
      IF (IER .NE. 0) RETURN
C
C  Check if the specified workstation is open.
C
      CALL GZCKWK(25,ECLWK,WKID,IDUM,IER)
      IF (IER .NE. 0) RETURN
C
C  Check if the workstation is currently active.
C
      CALL GZCKWK(29,ECLWK,WKID,IDUM,IER)
      IF (IER .NE. 0) RETURN
C
C  Invoke the workstation interface (do this before flagging
C  the workstation as closed).
C
C  Determine the workstation type.
C
      DO 200 I=1,NOPWK
        IF (SOPWK(I) .EQ. WKID) THEN
          NWKTP = SWKTP(I)
          GO TO 10
        ENDIF
  200 CONTINUE
   10 CONTINUE
C
C  Invoke the workstation interface for non-WISS workstations.
C
C  Set the flag CUFLAG to indicate that the interface call should go
C  only to the specifically designated workstation.
C
      IF (NWKTP .NE. GWSS) THEN
        CUFLAG = WKID
        FCODE = 0
        CONT  = 0
        CALL GZROI(0)
        IL1  = 1
        IL2  = 1
        ID(1) = WKID
        CALL GZTOWK
        IF (RERR.NE.0) THEN
          ERS = 1
          CALL GERHND(RERR,ECLWK,ERF)
          ERS = 0
        ENDIF
        CUFLAG = -1
      ELSE
C
C  Delete all segments in WISS, unless requested not to.
C
        IF (SEGDEL .NE. 0) THEN
  210     CONTINUE
          CALL GQSGUS(1,IER,NUMS,ISGNM)
          IF (NUMS .LE. 0) GO TO 215
          CALL GDSG(ISGNM)
          GO TO 210
        ENDIF
  215   CONTINUE
      ENDIF
C
C  Remove the workstation identifier from the set of open 
C  workstations in the GKS state list and delete it from
C  the X workstation list.
C
      IF (NOPWK .EQ. 1) THEN
        SOPWK(1) = -1
        SWKTP(1) = -1
        LXWKID(1) = -1
        NOPWK = 0
      ELSE
        DO 201 I=1,NOPWK
          IF (SOPWK(I) .EQ. WKID) THEN
            IF (I .EQ. NOPWK) THEN
              SOPWK(NOPWK) = -1
              SWKTP(NOPWK) = -1
              LXWKID(I) = -1
              NOPWK = NOPWK-1
            ELSE
              NM1 = NOPWK-1
              DO 202 J=I,NM1
                SOPWK(J) = SOPWK(J+1)
                SWKTP(J) = SWKTP(J+1)
                LXWKID(J) = LXWKID(J+1)
  202         CONTINUE
              SOPWK(NOPWK) = -1
              SWKTP(NOPWK) = -1
              LXWKID(NOPWK) = -1
              NOPWK = NOPWK-1
            ENDIF
          ENDIF
  201   CONTINUE
      ENDIF
C
C  Set GKS to state GKOP if no workstations remain open.
C
      IF (SOPWK(1) .EQ. -1) THEN
        OPS = GGKOP
      ENDIF
C
C  Indicate that the metafile picture is empty.
C
      IF (NWKTP .EQ. GCGM) THEN
        NOPICT = 0
      ENDIF
C
      RETURN
      END
