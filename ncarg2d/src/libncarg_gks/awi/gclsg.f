C
C	$Id: gclsg.f,v 1.3 2000-07-12 16:39:39 haley Exp $
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
      SUBROUTINE GCLSG
C
C  CLOSE SEGMENT
C
      INTEGER ECLSG
      PARAMETER (ECLSG=57)
C
      include 'gkscom.h'
C
C  This subroutine is here solely as support for the SPPS GFLASn
C  entries.  Full segmentation is not a part of the NCAR GKS
C  package at this time.  The NCAR package is non-standard to the
C  extent that certain segmentation functions are supported, but
C  not all level 1 functions are supported.  This subroutine should
C  be considered a user entry point only by way of the GFLASn
C  calls--it should never be called directly be the user.
C
C
C  Check if GKS is in the proper state.
C
      CALL GZCKST(4,ECLSG,IER)
      IF (IER .NE. 0) RETURN
C
C  Get the workstation ID for WISS.
C
      DO 10 I=1,NACWK
        CALL GQWKC(SACWK(I),IER,ICONID,ITYP)
        IF (ITYP .EQ. GWSS) THEN
          IWKIDX = I
          GO TO 20
        ENDIF
   10 CONTINUE
      ERS = 1
      CALL GERHND(-103,ECLSG,ERF)
      ERS = 0
      RETURN
   20 CONTINUE
C
C  Invoke workstation interface.
C
      CUFLAG = SACWK(IWKIDX)
      FCODE = 81
      CONT  = 0
      CALL GZROI(0)
      CALL GZTOWK
      IF (RERR .NE. 0) THEN
        ERS = 1
        CALL GERHND(RERR,ECLSG,ERF)
        ERS = 0
      ENDIF
C
C  Store the segment length.
C
      DO 30 I=1,NUMSEG
        IF (SEGS(I) .EQ. CURSEG) THEN
          SEGLEN(I) = ID(1)
          GO TO 40
        ENDIF
   30 CONTINUE
   40 CONTINUE
C
C  Set GKS state to workstation active.
C
      OPS = GWSAC
      CURSEG = -1
      CUFLAG = -1
C
      RETURN
      END
