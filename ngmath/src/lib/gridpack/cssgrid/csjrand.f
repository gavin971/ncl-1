C
C	$Id: csjrand.f,v 1.3 2000-07-13 02:49:11 haley Exp $
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
      INTEGER FUNCTION CSJRAND (N, IX,IY,IZ )
      INTEGER N, IX, IY, IZ
C
C***********************************************************
C
C                                              From STRIPACK
C                                            Robert J. Renka
C                                  Dept. of Computer Science
C                                       Univ. of North Texas
C                                           renka@cs.unt.edu
C                                                   07/28/98
C
C   This function returns a uniformly distributed pseudo-
C random integer in the range 1 to N.
C
C
C On input:
C
C       N = Maximum value to be returned.
C
C N is not altered by this function.
C
C       IX,IY,IZ = Integer seeds initialized to values in
C                  the range 1 to 30,000 before the first
C                  call to CSJRAND, and not altered between
C                  subsequent calls (unless a sequence of
C                  random numbers is to be repeated by
C                  reinitializing the seeds).
C
C On output:
C
C       IX,IY,IZ = Updated integer seeds.
C
C       CSJRAND = Random integer in the range 1 to N.
C
C Reference:  B. A. Wichmann and I. D. Hill, "An Efficient
C             and Portable Pseudo-random Number Generator",
C             Applied Statistics, Vol. 31, No. 2, 1982,
C             pp. 188-190.
C
C Modules required by CSJRAND:  None
C
C Intrinsic functions called by CSJRAND:  INT, MOD, REAL
C
C***********************************************************
C
      REAL U, X
C
C Local parameters:
C
C U = Pseudo-random number uniformly distributed in the
C     interval (0,1).
C X = Pseudo-random number in the range 0 to 3 whose frac-
C       tional part is U.
C
      IX = MOD(171*IX,30269)
      IY = MOD(172*IY,30307)
      IZ = MOD(170*IZ,30323)
      X = (REAL(IX)/30269.) + (REAL(IY)/30307.) +
     .    (REAL(IZ)/30323.)
      U = X - INT(X)
      CSJRAND = REAL(N)*U + 1.0E0
      RETURN
      END
