/*
 * $Id: c_ccpils.c,v 1.2 1994-06-21 14:59:27 haley Exp $
 */

#include <stdio.h>
#include <math.h>

#include <ncarg/ncargC.h>
#include <ncarg/gks.h>

#define M  40
#define N  40
#define LRWK  3500
#define LIWK  4000

#define WSTYPE SED_WSTYPE
#define WKID   1

main()
{
	float z[N][M], rwrk[LRWK];
	int iwrk[LIWK];
	extern void getdat();

	getdat (z, M, N);
/*
 * Open GKS
 */
	gopen_gks("stdout",0);
	gopen_ws(WKID, NULL, WSTYPE);
	gactivate_ws(WKID);
	gset_clip_ind(GIND_NO_CLIP);
/*
 * Set label sizes 
 */
	c_cpsetr("HLS - HIGH/LOW LABEL SIZE",.030);
	c_cpsetr("ILS - INFORMATION LABEL SIZE",.005);
/*
 * Initialize Conpack
 */
	c_cprect((float *)z, M, M, N, rwrk, LRWK, iwrk, LIWK);
/*
 * Draw Perimeter
 */
	c_cpback((float *)z, rwrk, iwrk);
/*
 * Draw Labels
 */
	c_cplbdr((float *)z,rwrk,iwrk);
/*
 * Close frame and close GKS
 */
	c_frame();
	gdeactivate_ws(WKID);
	gclose_ws(WKID);
	gclose_gks();
}

void getdat (z, m, n)
float z[N][M];
int m, n;
{
	int i, j;
	FILE *fp;

	fp = fopen("ccpex.dat","r");
	for( i = 0; i < m; i++ ) {
		for( j = 0; j < n; j++ ) {
			fscanf( fp, "%g", &z[j][i] );
		}
	}
	fclose(fp);
	return;
}