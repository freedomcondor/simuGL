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
#include "List.h"

#include "string.h"

/*------------ Function Control Channels ------------*/
#define NBIRD 50
int nBirds = NBIRD;
//Bird birds[NBIRD];
List<Bird> birds;

/* --------------- MainLoop functions --------------------*/
int simu_exit()
{
	return 0;
}

int simu_init(int ScreenWidth, int ScreenHeight)
{
	PAUSE = 1;

	char ctrl_dir[300];
	printf("Flock dir %s\n", FLOCK_DIR);
	strcpy(ctrl_dir, FLOCK_DIR);
	strcat(ctrl_dir, "/ctrl.lua");
	printf("flock dir %s\n", FLOCK_DIR);

	for (int i = 0; i < nBirds; i++)
		birds.put(0,0,0);

	double range = 0.8;
	for (int i = 0; i < nBirds; i++)
		birds[i].setl(range*rand()/RAND_MAX-range/2,
		              range*rand()/RAND_MAX-range/2,
		              range*rand()/RAND_MAX-range/2);

	for (int i = 0; i < nBirds; i++)
		birds[i].ctrl.load(&birds[i], ctrl_dir);

	return 0;
}

int simu_step(double time)	// time in s
{
	for (int i = 0; i < nBirds; i++)
		birds[i].getNeighbours(nBirds, birds);

	for (int i = 0; i < nBirds; i++)
		birds[i].run(time);

	return 0;
}

/* --------------- OpenGL draw functions --------------------*/
int simu_draw()
{
	for (int i = 0; i < nBirds; i++)
		birds[i].draw();
	return 0;
}

int simu_draw2()
{
	return 0;
}

