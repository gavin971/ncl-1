C
C $Id: curvp2.f,v 1.2 2000-07-13 02:49:21 haley Exp $
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
      function curvp2 (t,n,x,y,p,yp,sigma)
c
      integer n
      real t,x(n),y(n),p,yp(n),sigma
c
c                                 coded by alan kaylor cline
c                           from fitpack -- january 26, 1987
c                        a curve and surface fitting package
c                      a product of pleasant valley software
c                  8603 altus cove, austin, texas 78759, usa
c
c this function interpolates a curve at a given point using
c a periodic spline under tension. the subroutine curvp1
c should be called earlier to determine certain necessary
c parameters.
c
c on input--
c
c   t contains a real value to be mapped onto the interpo-
c   lating curve.
c
c   n contains the number of points which were specified to
c   determine the curve.
c
c   x and y are arrays containing the abscissae and
c   ordinates, respectively, of the specified points.
c
c   p contains the period.
c
c   yp is an array of second derivative values of the curve
c   at the nodes.
c
c and
c
c   sigma contains the tension factor (its sign is ignored).
c
c the parameters n, x, y, p, yp, and sigma should be input
c unaltered from the output of curvp1.
c
c on output--
c
c   curvp2 contains the interpolated value.
c
c none of the input parameters are altered.
c
c this function references package modules intrvp and
c snhcsh.
c
c-----------------------------------------------------------
c
c determine interval
c
      im1 = intrvp (t,x,n,p,tp)
      i = im1+1
c
c denormalize tension factor
c
      sigmap = abs(sigma)*float(n)/p
c
c set up and perform interpolation
c
      del1 = tp-x(im1)
      if (im1 .eq. n) go to 1
      del2 = x(i)-tp
      dels = x(i)-x(im1)
      go to 2
    1 i = 1
      del2 = x(1)+p-tp
      dels = p-(x(n)-x(1))
    2 sum = (y(i)*del1+y(im1)*del2)/dels
      if (sigmap .ne. 0.) go to 3
      curvp2 = sum-del1*del2*(yp(i)*(del1+dels)+yp(im1)*
     *        (del2+dels))/(6.*dels)
      return
    3 sigdel = sigmap*dels
      call snhcsh (ss,dummy,sigdel,-1)
      call snhcsh (s1,dummy,sigmap*del1,-1)
      call snhcsh (s2,dummy,sigmap*del2,-1)
      curvp2 = sum+(yp(i)*del1*(s1-ss)+yp(im1)*del2*(s2-ss))/
     *            (sigdel*sigmap*(1.+ss))
      return
      end
