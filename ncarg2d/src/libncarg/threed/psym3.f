C
C $Id: psym3.f,v 1.2 1993-03-14 19:01:23 kennison Exp $
C
      SUBROUTINE PSYM3 (U,V,W,ICHAR,SIZE,IDIR,ITOP,IUP)
      IF (IUP .EQ. 2) CALL VECT3 (U,V,W)
      CALL PWRZ (U,V,W,ICHAR,1,SIZE,IDIR,ITOP,0)
      RETURN
      END
