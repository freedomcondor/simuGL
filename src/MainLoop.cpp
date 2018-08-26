/*---------------------------------------------------------*/
/*
   	Weixu ZHU (Harry)
   		zhuweixu_harry@126.com
	
	Version 1.0
	Version 1.1 : change opengl debug layout

*/
/*---------------------------------------------------------*/

#include <stdio.h>
#include "GLTools/GLTools.h"

#include "CVector/Vector3.h"

/*------------ Function Control Channels ------------*/
double CH1,CH1_MAX,CH1_MIN,CH1_STEP;
double CH2,CH2_MAX,CH2_MIN,CH2_STEP;
int CMDCH1;

/* --------------- main functions --------------------*/
int function_exit()
{
	return 0;
}

int function_init()
{
	printf("i am init\n");
	Vector3 a;
	printf("a = %s\n",a.toStr());
	return 0;
}

int function_step(double time)	// time in ms
{
	printf("i am step\n");
	return 0;
}

/* --------------- draw functions --------------------*/
int function_draw()
{
	return 0;
}

int function_draw2()
{
	return 0;
}
