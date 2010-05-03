C
C	$Id: cmpsat.f,v 1.1 1992-09-29 16:10:18 ncargd Exp $
C
	PROGRAM CMPSAT
C
C Open GKS.
C
	CALL OPNGKS
C
C Turn off the clipping indicator.
C
	CALL GSCLIP (0)
C
C International outlines
C
	CALL MAPSTC ('OU - OUTLINE DATASET SELECTOR','PO')
C
C Satellite-view.
C
	CALL MAPROJ ('SV',40.,10.,0.)
	CALL MAPSTR ('SA - SATELLITE DISTANCE',2.)
	CALL MAPSTR ('S1 - SATELLITE ANGLE 1',10.)
	CALL MAPSTR ('S2 - SATELLITE ANGLE 2',15.)
	CALL MAPDRW

	CALL FRAME
	CALL CLSGKS

	STOP
	END