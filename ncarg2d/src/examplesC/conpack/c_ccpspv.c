#include <stdio.h>
#include <math.h>
#include <ncarg/gks.h>
#include <ncarg/ncargC.h>

/*
 ** Define error file, Fortran unit number, and workstation type,
 ** and workstation ID.
 */
#define IERRF  "stdout"
#define LUNIT  "gmeta"
#define IWTYPE SED_WSTYPE
#define IWKID  1
#define ISZDM  0

#define K 40            /* rows of data */
#define N 40            /* columns of data */
#define LRWK 1000       /* size of real work array */
#define LIWK 1000       /* size of integer work array */


int main()
{
    int i,j;        /* counters */
    int iwrk[LIWK];         /* integer work array */

    float rwrk[LRWK];       /* real work array */
    float z[K][N];          /* contour data */

    /* Create contour data */
    extern void getdat(float*);


    getdat (&z[0][0]);

    /* Mark values near the center of the array with a value of -1.0 */
    for(i=(2*K/5-1); i<(3*K/5); ++i)
    {
        for(j=(2*N/7-1); j<(3*N/7); ++j)
        {
            z[j][i] = -1.0;
        }
    }

    /* Open GKS */
    gopen_gks(IERRF, ISZDM);
    gopen_ws(IWKID, LUNIT, IWTYPE);
    gactivate_ws(IWKID);
    gset_clip_ind (0);

    /* Tell Conpack that data points with a value of -1.0 shouldn"t be drawn */
    c_cpsetr("SPV - SPECIAL VALUE",-1.0);

    /* Force Conpack to outline the special value region */
    c_cpseti("PAI - PARAMETER ARRAY INDEX",-2);
    c_cpseti("CLU - CONTOUR LEVEL USE FLAGS",1);

    /* Initialize Conpack */
    c_cprect (&z[0][0], N, N, K, rwrk, LRWK, iwrk, LIWK);

    /* Draw perimeter */
    c_cpback (&z[0][0], rwrk, iwrk);

    /* Draw Contours */
    c_cpcldr (&z[0][0], rwrk, iwrk);

    /* Close frame and close GKS */
    c_frame();
    gdeactivate_ws(IWKID);
    gclose_ws(IWKID);
    gclose_gks();
    return (0);
}


void getdat (float* z)
     /*
      ** Create contour data.
      **
      ** z    - data array
      */
{

    int i,j;        /* counters */

    /* Create contour levels */
    for(i=1; i<=K; ++i)
    {
        for(j=1; j<=N; ++j)
        {
            z[(((j-1)*N)+i-1)] = 10.0e-5*(-16.*(float)(i*i*j) +
                                 34.0*(float)(i*j*j) - (float)(6*i) + 93.);
        }
    }
}