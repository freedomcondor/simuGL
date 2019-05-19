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

#include "Bird.h"

/*------------ Function Control Channels ------------*/
double CH1,CH1_MAX,CH1_MIN,CH1_STEP;
double CH2,CH2_MAX,CH2_MIN,CH2_STEP;
int CMDCH1;

int nBirds = 2;
Bird birds[2];

/* --------------- MainLoop functions --------------------*/
int function_exit()
{
	return 0;
}

int function_init()
{
	birds[0].setl(0,0,0);
	birds[1].setl(0,0,0.01);

	for (int i = 0; i < nBirds; i++)
		birds[i].ctrl.load(&birds[i], "../src/Modules/Flock/ctrl.lua");
	return 0;
}

int function_step(double time)	// time in s
{
	for (int i = 0; i < nBirds; i++)
	{
		birds[i].getNeighbours(nBirds, birds);
		birds[i].run(time);
	}

	return 0;
}

/* --------------- OpenGL draw functions --------------------*/
int function_draw()
{
	for (int i = 0; i < nBirds; i++)
		birds[i].draw();
	return 0;
}

int function_draw2()
{
	return 0;
}

