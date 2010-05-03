C
C	$Id: cezmap3.f,v 1.1 1992-09-29 16:09:44 ncargd Exp $
C
	REAL PLIM1(2), PLIM2(2), PLIM3(2), PLIM4(2)

	DATA PLIM1 /0.,0./
	DATA PLIM2 /0.,0./
	DATA PLIM3 /0.,0./
	DATA PLIM4 /0.,0./
C
C Open GKS, Turn Clipping off
C
      CALL OPNGKS 
C
C INVOKE DEMO DRIVER
C
      CALL CEZMAP('SV',40.,-50.,0.,'PO','MA',PLIM1,PLIM2,PLIM3,PLIM4)
C
C     DEACTIVATE AND CLOSE WORKSTATION, CLOSE GKS.
C
      CALL CLSGKS

	STOP
	END

      SUBROUTINE CEZMAP(PROJ, PLAT, PLON, ROTA, OUTLN,
     +	JLIM, PLIM1, PLIM2, PLIM3, PLIM4)

	CHARACTER*2 PROJ, OUTLN, JLIM
	REAL PLIM1(2), PLIM2(2), PLIM3(2), PLIM4(2)
C
C CMPLOT demonstrates MAPLOT drawing continental and political outlines
C
C Set up Maps.
C
C
C Draw Continental, political outlines 
C
        CALL MAPSTC ('OU - OUTLINE DATASET SELECTOR',OUTLN)
C
C Set up projection
C
	CALL MAPROJ (PROJ,PLAT,PLON,ROTA)
C
C If it's a satellite projection, choose a satellite distance
C
	IF (PROJ.EQ.'SV') CALL MAPSTR ('SA - SATELLITE DISTANCE',5.)
C
C Set limits of map
C
        CALL MAPSET (JLIM,PLIM1,PLIM2,PLIM3,PLIM4)
C
C Draw map
C
	CALL MAPDRW
C
C Advance the frame.
C
        CALL FRAME
C
C Done.
C
        RETURN
	END