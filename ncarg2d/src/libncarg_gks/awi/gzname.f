C
C	$Id: gzname.f,v 1.3 2000-07-12 16:40:05 haley Exp $
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
      SUBROUTINE GZNAME(FCTID,FNAME)
C
C  This subroutine takes the GKS function id in the integer variable
C  FCTID (as per the codes assigned in the Fortran binding) and returns 
C  the function name in the CHARACTER*6 variable FNAME.  The name in 
C  FNAME is left justiifed and blank padded.
C
      include 'gkscom.h'
C
      CHARACTER*6 FNAME
      INTEGER FCTID
C
      FNAME = GNAM(FCTID+1)
      RETURN
      END
