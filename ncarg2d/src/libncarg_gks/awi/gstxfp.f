C
C	$Id: gstxfp.f,v 1.3 2000-07-12 16:40:00 haley Exp $
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
      SUBROUTINE GSTXFP (FONT,PREC)
C
C  SET TEXT FONT AND PRECISION
C
      INTEGER ESTXFP
      PARAMETER (ESTXFP=27)
C
      include 'gkscom.h'
C
      INTEGER FONT,PREC
C
C  Check if GKS is in the proper state.
C
      CALL GZCKST(8,ESTXFP,IER)
      IF (IER .NE. 0) RETURN
C
C  Check that the font is not zero.
C
      IF (FONT .EQ. 0) THEN
        ERS = 1
        CALL GERHND(75,ESTXFP,ERF)
        ERS = 0
        RETURN
      ENDIF
C
C  Check that the precision is valid.
C
      IF (PREC.LT.0 .OR. PREC.GT.2) THEN
        ERS = 1
        CALL GERHND(2000,ESTXFP,ERF)
        ERS = 0
        RETURN
      ENDIF
C
C  Set the current font and precision variables in the GKS state list.
C
      CTXFP(1) = FONT
      CTXFP(2) = PREC
C
C  Invoke the workstation interface.
C
      FCODE = 30
      CONT  = 0
      CALL GZROI(0)
      IL1   = 2
      IL2   = 2
      ID(1) = FONT
      ID(2) = PREC
      CALL GZTOWK
      IF (RERR .NE. 0) THEN
        ERS = 1
        CALL GERHND(RERR,ESTXFP,ERF)
        ERS = 0
      ENDIF
C
      RETURN
      END
