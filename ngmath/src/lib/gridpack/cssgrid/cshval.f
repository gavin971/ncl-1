C
C	$Id: cshval.f,v 1.3 2000-07-13 02:49:10 haley Exp $
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
      DOUBLE PRECISION FUNCTION CSHVAL (B,H1,H2,HP1,HP2,SIGMA)
      DOUBLE PRECISION B, H1, H2, HP1, HP2, SIGMA
C
C***********************************************************
C
C                                              From SSRFPACK
C                                            Robert J. Renka
C                                  Dept. of Computer Science
C                                       Univ. of North Texas
C                                           renka@cs.unt.edu
C                                                   11/21/96
C
C   Given a line segment P1-P2 containing a point P, along
C with values and derivatives at the endpoints, this func-
C tion returns the value H(P), where H is the Hermite inter-
C polatory tension spline defined by the endpoint data.
C
C On input:
C
C       B = Local coordinate of P with respect to P1-P2:
C           P = B*P1 + (1-B)*P2, and thus B = d(P,P2)/
C           d(P1,P2), where d(P1,P2) is the distance between
C           P1 and P2.  B < 0 or B > 1 results in extrapola-
C           tion.
C
C       H1,H2 = Values interpolated at P1 and P2, respec-
C               tively.
C
C       HP1,HP2 = Products of d(P1,P2) with first order der-
C                 ivatives at P1 and P2, respectively.  HP1
C                 may, for example, be the scalar product of
C                 P2-P1 with a gradient at P1.
C
C       SIGMA = Nonnegative tension factor associated with
C               the spline.  SIGMA = 0 corresponds to a
C               cubic spline, and H approaches the linear
C               interpolant of H1 and H2 as SIGMA increases.
C
C Input parameters are not altered by this function.
C
C On output:
C
C       CSHVAL = Interpolated value H(P).
C
C SSRFPACK module required by CSHVAL:  CSSNHCSH
C
C Intrinsic functions called by CSHVAL:  ABS, EXP
C
C***********************************************************
C
      DOUBLE PRECISION B1, B2, CM, CM2, CMM, D1, D2, DUMMY,
     .                 E, E1, E2, EMS, S, SB1, SB2, SIG, SM,
     .                 SM2, TM, TM1, TM2, TS
      B1 = B
      B2 = 1. - B1
C
C Compute slope S and second differences D1 and D2 scaled
C   by the separation between P1 and P2.
C
      S = H2 - H1
      D1 = S - HP1
      D2 = HP2 - S
C
C Test the range of SIGMA.
C
      SIG = ABS(SIGMA)
      IF (SIG .LT. 1.D-9) THEN
C
C Hermite cubic interpolation:
C
        CSHVAL = H1 + B2*(HP1 + B2*(D1 + B1*(D1 - D2)))
      ELSEIF (SIG .LE. .5) THEN
C
C 0 < SIG .LE. .5.  Use approximations designed to avoid
C   cancellation error in the hyperbolic functions.
C
        SB2 = SIG*B2
        CALL CSSNHCSH (SIG, SM,CM,CMM)
        CALL CSSNHCSH (SB2, SM2,CM2,DUMMY)
        E = SIG*SM - CMM - CMM
        CSHVAL = H1 + B2*HP1 + ((CM*SM2-SM*CM2)*(D1+D2) + SIG*
     .                     (CM*CM2-(SM+SIG)*SM2)*D1)/(SIG*E)
      ELSE
C
C SIG > .5.  Use negative exponentials in order to avoid
C   overflow.  Note that EMS = EXP(-SIG).
C
        SB1 = SIG*B1
        SB2 = SIG - SB1
        E1 = EXP(-SB1)
        E2 = EXP(-SB2)
        EMS = E1*E2
        TM = 1. - EMS
        TS = TM*TM
        TM1 = 1. - E1
        TM2 = 1. - E2
        E = TM*(SIG*(1.+EMS) - TM - TM)
        CSHVAL = H1 + B2*S + (TM*TM1*TM2*(D1+D2) + SIG*
     .                      ((E2*TM1*TM1-B1*TS)*D1 +
     .                       (E1*TM2*TM2-B2*TS)*D2))/(SIG*E)
      ENDIF
      RETURN
      END
