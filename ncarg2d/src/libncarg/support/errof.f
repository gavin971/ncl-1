C
C $Id: errof.f,v 1.2 1993-09-23 17:21:22 kennison Exp $
C
      SUBROUTINE ERROF
C
C This routine just turns off the error flag.
C
C The common blocks SECOMI and SECOMC are used to hold shared variables
C of types INTEGER and CHARACTER, respectively, for the routine SETER
C and associated routines.  For descriptions of these variables and for
C default values of them, see the block data routine SEBLDA.
C
        COMMON /SECOMI/ IERRU,IERRF,IRECF,LOMSG
        SAVE   /SECOMI/
C
        COMMON /SECOMC/ ERMSG
          CHARACTER*113 ERMSG
        SAVE   /SECOMC/
C
C Do it.
C
        IERRF=0
C
C Done.
C
        RETURN
C
      END
