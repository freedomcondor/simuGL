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

#include "Vector3.h"
#include "Quaternion.h"

#include "Box.h"
#include "Sphere.h"
#include "Cylinder.h"
//#include "Convexhull.h"

#include "List.h"
#include "LuaCtrl.h"

Box b(0,0,0);

List<int> list;
LuaCtrl ctrl;

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
	b.draw();
	return 0;
}

int simu_draw2()
{
	return 0;
}

