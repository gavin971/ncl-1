/*
 * $Id: c_cmpgci.c,v 1.2 1994-06-21 14:59:59 haley Exp $
 */

#include <stdio.h>

#include <ncarg/ncargC.h>
#include <ncarg/gks.h>

#define WSTYPE SED_WSTYPE
#define WKID   1

main()
{
    int i, ierr;
    float rlat[100], rlon[100], plm1[2], plm2[2], plm3[2], plm4[2];
/*
 * Open GKS.
 */
	gopen_gks ("stdout",0);
	gopen_ws (WKID, NULL, WSTYPE);
	gactivate_ws(WKID);
/*
 * Draw a map
 */
    plm1[0] = 0.;
    plm2[0] = -80.;
    plm3[0] = 90.;
    plm4[0] = 10.;
    c_supmap(8,0.,-50.,0.,plm1,plm2,plm3,plm4,2,0,0,0,&ierr);
/*
 * Get data values defining a great circle between Washinton DC and
 * London
 */
    c_mapgci(38.,-77.,51.,0.,100,rlat,rlon);
/*
 * Draw the great circle
 */
    c_mapit(38.,-77.,0);
    for( i = 0; i < 100; i++ ) {
        c_mapit(rlat[i],rlon[i],1);
    }
    c_mapit(51.,0.,1);
    c_mapiq();
/*
 * Advance the frame.
 */
    c_frame();
/*
 * Close GKS.
 */
	gdeactivate_ws(WKID);
	gclose_ws(WKID);
	gclose_gks();
}