C
C $Id: gzgte1.f,v 1.3 2000-07-12 16:40:04 haley Exp $
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
      SUBROUTINE GZGTE1(INDEX,NUM,ERMSG)
C
C  Given an index INDEX into the error table, this subroutine
C  returns the NCAR GKS error number in NUM and the error
C  message string in ERMSG (the length of ERMSG will be a
C  maximum of 90 characters).
C
      CHARACTER*(*) ERMSG
C
      include 'gkscom.h'
C
      IF (INDEX.LE.NUMERS .AND. INDEX.GE.1) THEN
        NUM = IERNMS(INDEX)
        ERMSG = ERMSGS(INDEX)
      ELSE
        NUM = -100
        ERMSG = ERMSGS(79)
      ENDIF
C
      RETURN
      END
