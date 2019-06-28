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

#include "List.h"

List<Vector3> a;

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
	Vector3 v(11,11,11);
	printf("v address = %p\n", &v);
	a.pushHead(Vector3(1,2,3));
	a.pushHead(Vector3(4,5,6));
	a.pushHead(v);
 	for (a.firstFocal(); !a.focalAtTail(); a.nextFocal())
		printf("%s, %p\n", a.getFocal().toStr(), &a.getFocal());
	printf("\n");

	a.firstFocal();
	a.put(1,2,3);
 	for (a.firstFocal(); !a.focalAtTail(); a.nextFocal())
		printf("%s\n", a.getFocal().toStr());
	printf("\n");

	a.pushHead(Vector3(4,5,6));
 	for (a.firstFocal(); !a.focalAtTail(); a.nextFocal())
		printf("%s\n", a.getFocal().toStr());
	printf("\n");

	printf("%s\n", a[0].toStr());
	printf("%s\n", a[1].toStr());
	printf("%s\n", a[2].toStr());
	printf("\n");

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

