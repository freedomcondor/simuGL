/*---------------------------------------------------------*/
/*
   	Weixu ZHU (Harry)
   		zhuweixu_harry@126.com
	
	Version 1.0
	Version 1.1 : change opengl debug layout

*/
/*---------------------------------------------------------*/

#include <stdio.h>
#include "GLTools.h"

#include "Vector3.h"
#include "Quaternion.h"

#include "Solve.h"
/*------------ Function Control Channels ------------*/
double CH1,CH1_MAX,CH1_MIN,CH1_STEP;
double CH2,CH2_MAX,CH2_MIN,CH2_STEP;
int CMDCH1;

/* --------------- MainLoop functions --------------------*/
int function_exit()
{
	return 0;
}

int function_init()
{
	printf("src dir %s\n", SRC_DIR);

	double x1, x2, x3;
	int n;

	Cubic(1, -6, 11, -6, &n, &x1, &x2, &x3);
	printf("n = %d, x1 = %lf, x2 = %lf, x3 = %lf\n", n, x1, x2, x3);

	return 0;
}

int function_step(double time)	// time in s
{
	return 0;
}

/* --------------- OpenGL draw functions --------------------*/
int function_draw()
{
	return 0;
}

int function_draw2()
{
	return 0;
}

