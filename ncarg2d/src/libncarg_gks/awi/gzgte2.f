C
C $Id: gzgte2.f,v 1.2 2000-07-12 16:40:04 haley Exp $
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
      SUBROUTINE GZGTE2(NUM,ERMSG)
C
C  Given an NCAR GKS error number in NUM, this subroutine
C  returns the NCAR GKS error message string in ERMSG (the 
C  length of ERMSG will be a maximum of 90 characters). If
C  no error message is found for the given error number, the
C  string ' --UNKNOWN ERROR CODE' is returned in ERMSG.
C
      CHARACTER*(*) ERMSG
C
      include 'gkscom.h'
C
      INTEGER GZNUME
C
C  Determine the index into the error message array.
C
      IGKNER = GZNUME()
      DO 20 I=1,IGKNER
        IF (NUM .EQ. IERNMS(I)) THEN
          NDXER = I
          GO TO 50
        ENDIF
   20 CONTINUE
C
C  Error number is not known.
C
      NDXER = 79
   50 CONTINUE
      ERMSG = ERMSGS(NDXER)
C
      RETURN
      END
