/*---------------------------------------------------------*/
/*
   	Weixu ZHU (Harry)
   		zhuweixu_harry@126.com
	
	Version 1.0
	Version 1.1 : change opengl debug layout

*/
/*---------------------------------------------------------*/
#define FORCE

#include <stdio.h>
#include "GLTools.h"

/* --------------- MainLoop functions --------------------*/
int simu_exit()
{
	return 0;
}

int simu_init(int ScreenWidth, int ScreenHeight)
{
	EyeWInit = 45;
	WindowX = ScreenWidth / 4;

	return 0;
}

int simu_step(double time)	// time in s
{
	return 0;
}

/* --------------- OpenGL draw functions --------------------*/
int simu_draw()
{
	return 0;
}

int simu_draw2()
{
	return 0;
}

