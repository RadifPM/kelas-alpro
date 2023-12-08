/*
 *	baseball.c
 *
 *	calculate the trajectory of a batted ball with air drag
 *	2-08-04
 * 
 *	by N Giordano
 *
 *	parameters are set in init()
 *
 *	these parameters include:
		drag parameters
		initial speed and angle of ball
		altitude
		wind speed
 */

#include <math.h>
#include <stdio.h>

#define	MAX	10000

double a_drag();
double a_drag_2();

double x[MAX],y[MAX],t[MAX];
double v_x[MAX],v_y[MAX];
int n_points;
double mass;
double C_drag;
double area;
double A_drag;
double g;
double dt;

double c_1,c_2,v_d,delta;
double d_1,d_2,v_d_2,delta_2;
double altitude,y_0;
double v_wind;	/* along x	*/

main()
{

	init();
	propagate();
}

propagate()
{
	int i;
	double v;
    FILE *fptr;
    fptr = fopen("baseball.txt", "w");
	i = 0;
	while(y[i] >= 0.0) {
        
		v = (v_x[i]-v_wind) * (v_x[i]-v_wind) + v_y[i] * v_y[i];
		v = pow(v,0.5);
		fprintf(fptr, "%g\t%g\n", x[i],y[i]);
		x[i+1] = x[i] + v_x[i] * dt;
		y[i+1] = y[i] + v_y[i] * dt;
		v_x[i+1] = v_x[i] - a_drag(v) * v * (v_x[i]-v_wind) * dt;
		v_y[i+1] = v_y[i] - a_drag(v) * v * v_y[i] * dt - g * dt;
		++i;
	}

	return;
}

init()
{
	double v_0,theta;

	c_1 = 0.0039;
	c_2 = 0.0058;
	v_d = 35;
	delta = 5;

	d_1 = 0.0050;	/* was 53 */
	d_2 = 0.0044;
	d_1 = 0.0047;	/* was 53 */
	d_2 = 0.0041;
	v_d_2 = 35;
	delta_2 = 5;

	g = 9.8;
	v_0 = 50.0;	/* approx 110 miles per hour	*/
	theta = 35.0;
	theta *= (2 * 3.14 / 360);

	y_0 = 1.0e4;
	altitude = 0;	/* in feet	*/
	altitude /= 3.28;	/* convert to m	*/
	v_wind = 0.0;
	v_wind = -10;		/* in miles per hour	*/
	v_wind *= 0.447;	/* convert to m/s	*/

	n_points = 0;
	dt = 0.01;
	dt = 0.001;
	t[0] = 0.0;
	x[0] = 0.0;
	y[0] = 1.0;
	v_x[0] = v_0 * cos(theta);
	v_y[0] = v_0 * sin(theta);

	return;
}

double
a_drag(v)
double v;
{
	double val;

	val = c_1 + c_2 / (1 + exp((v - v_d)/delta));

	val *= exp(-altitude / y_0);

	return(val);
}

double
a_drag_2(v)
double v;
{
	double val;

	val = d_1 + d_2 / (1 + exp((v - v_d_2)/delta_2));

	val *= exp(-altitude / y_0);

	return(val);
}
