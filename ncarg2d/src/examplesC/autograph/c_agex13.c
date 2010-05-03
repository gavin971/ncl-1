/*
 *	$Id: c_agex13.c,v 1.2 1994-06-21 14:58:47 haley Exp $
 */
#include <stdio.h>
#include <math.h>

/*
 * Include function prototypes
 */
#include <ncarg/ncargC.h>

float xycd[226] = {
                 1.8,  2.1,  2.7,  1.6,  4.2,  1.5,  5.7,  1.9,  6.3,  2.9,  
                 6.5,  4.7,  6.0,  6.7,  5.6,  8.6,  5.4, 10.7,  5.6, 13.1,
                 4.8, 11.2,  3.7,  9.7,1.e36,1.e36,  7.0,  8.2,  7.7, 10.6,
                 8.2, 12.6,  8.2, 14.3,  8.0, 15.3,  7.7, 15.6,  7.5, 15.1,
                 7.4, 14.0,  7.6, 12.3,  7.7, 10.7,  7.9,  8.9,  8.2,  7.3,
                 8.5,  4.6,  8.5,  7.3,  8.6,  9.3,  8.8, 10.2,  9.1, 10.5,
                 9.4, 10.1,  9.6,  9.1,  9.9,  7.8, 10.3,  6.9, 11.1,  7.0,
                11.7,  7.8, 12.0,  8.6, 12.3, 10.0, 12.5, 11.5, 12.4, 12.7,
                12.2, 13.0, 11.9, 12.6, 11.7, 11.7, 11.6, 10.5, 11.7,  9.3,
                12.0,  8.6, 12.5,  8.6, 13.0,  9.0, 13.8, 10.1, 14.3, 11.1,
               1.e36,1.e36, 18.5, 23.4, 18.2, 23.5, 17.8, 23.2, 17.2, 22.6,
                16.8, 21.8, 16.0, 20.2, 15.8, 19.5, 16.0, 19.3, 16.6, 19.6,
                17.8, 20.6, 17.3, 19.1, 16.9, 17.3, 16.6, 16.0, 16.6, 14.5,
                16.8, 13.7, 17.1, 13.1, 17.8, 13.2, 18.4, 14.0, 19.2, 15.5,
                19.8, 16.8, 20.3, 18.0, 20.9, 20.1, 21.1, 18.9, 21.1, 17.4,
                21.1, 18.9, 21.2, 19.7, 21.5, 20.5, 21.8, 20.8, 22.0, 20.4,
                22.1, 19.6, 22.3, 18.7, 22.6, 18.4, 23.1, 18.9, 23.6, 20.0,
                24.1, 21.7, 24.7, 22.9, 25.3, 23.9, 24.7, 22.9, 24.4, 21.6,
                24.4, 20.6, 24.7, 20.2, 25.2, 20.7, 25.6, 21.5, 26.0, 22.9,
                26.4, 24.5, 26.7, 25.9, 26.8, 27.9, 26.6, 30.0, 26.4, 30.3,
                26.2, 30.0, 25.7, 28.0, 25.5, 26.1, 25.3, 24.9, 25.3, 23.9,
                25.4, 22.9, 25.9, 22.5, 26.6, 22.4, 27.4, 23.1, 28.2, 24.0,
                29.0, 25.0, 30.1, 26.4,1.e36,1.e36};

#define WSTYPE SED_WSTYPE
#define WKID   1

main()
{

/*
 * Define the data array.
 */
    float yxcd[226];
    int i;
    extern void bndary();
/*
 * initialize gks.
 */
	gopen_gks ("stdout",0);
	gopen_ws (WKID, NULL, WSTYPE);
	gactivate_ws(WKID);
/*
 * fill the data array.
 */
    for( i = 0; i < 226; i++ ) yxcd[i] = xycd[i];
    for( i = 0; i < 226; i++ ) {
        if(xycd[i] >= 9.e35) continue;
        xycd[i]=pow(2.,((xycd[i]-15.)/2.5));
        yxcd[i] = xycd[i];
    }
/*
 * specify log/log plot.
 */
    c_displa(0,0,4);
/*
 * bump the line-maximum parameter past 42.
 */
    c_agseti("LINE/MAXIMUM.",50);
/*
 * specify x- and y-axis labels, grid background.
 */
    c_anotat("LOGARITHMIC, BASE 2, EXPONENTIAL LABELS$","LOGARITHMIC, BASE 2, NO-EXPONENT LABELS$",2,0,0,NULL);
/*
 * specify the graph label.
 */
    c_agsetc("LABEL/NAME.","T");
    c_agseti("LINE/NUMBER.",100);
    c_agsetc("LINE/TEXT.","FINAL EXAMPLE$");
/*
 * specify x-axis ticks and labels.
 */
    c_agseti("BOTTOM/MAJOR/TYPE.",3);
    c_agsetf("BOTTOM/MAJOR/BASE.",2.);
    c_agseti("BOTTOM/NUMERIC/TYPE.",2);
    c_agseti("BOTTOM/MINOR/SPACING.",4);
    c_agseti("BOTTOM/MINOR/PATTERN.",43690);
/*
 * specify y-axis ticks and labels.
 */
    c_agseti("LEFT/MAJOR/TYPE.",3);
    c_agsetf("LEFT/MAJOR/BASE.",2.);
    c_agseti("LEFT/NUMERIC/TYPE.",3);
    c_agseti("LEFT/MINOR/SPACING.",4);
    c_agseti("LEFT/MINOR/PATTERN.",43690);
/*
 * compute secondary control parameters.
 */
    c_agstup(xycd,1,0,113,2,yxcd,1,0,113,2);
/*
 * draw the background.
 */
    c_agback();
/*
 * draw the curve twice to make it darker.
 */
/*
  c_agcurv(xycd[0],2,xycd[1],2,113,1);
  c_agcurv(xycd[0],2,xycd[1],2,113,1);
*/
    for( i = 0; i < 225; i++ ) yxcd[i] = xycd[i+1];
    yxcd[225] = 0;
    c_agcurv(xycd,2,yxcd,2,113,1);
    c_agcurv(xycd,2,yxcd,2,113,1);
/*
 * draw a boundary around the edge of the plotter frame.
 */
    bndary();
/*
 * advance the frame.
 */
    c_frame();
/*
 * close gks.
 */
	gdeactivate_ws(WKID);
	gclose_ws(WKID);
	gclose_gks();
}

void bndary()
{
/*
 * Routine to draw the plotter-frame edge.
 */
    c_plotit(    0,    0,0);
    c_plotit(32767,    0,1);
    c_plotit(32767,32767,1);
    c_plotit(    0,32767,1);
    c_plotit(    0,    0,1);
}
