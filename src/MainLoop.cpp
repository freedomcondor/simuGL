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

#include "Sphere.h"
#include "Cylinder.h"
#include "Convexhull.h"

/*------------ Function Control Channels ------------*/
double CH1,CH1_MAX,CH1_MIN,CH1_STEP;
double CH2,CH2_MAX,CH2_MIN,CH2_STEP;
int CMDCH1;

Sphere a(1,1,0);
Sphere b(0,0,0);
Cylinder c(-1,0,0);
Convexhull d(0.5, 0.5, 0.5);

/* --------------- MainLoop functions --------------------*/
int function_exit()
{
	return 0;
}

int function_init()
{
	a.setSize(0.1);
	b.setSize(0.2);
	c.setSize(0.1,0.3);
	double points[] = {
		0.1, 0.2, 0.3,
		0.2, 0.3, 1.3,
	};
	d.setPoint(2, points);

	a.setv(0.5, -0.5, 0);

	a.setm(1);
	b.setm(1000);
	c.setm(1);

	for (int i = 0; i < d.n; i++)
		printf("%s\n",d.points[i].toStr());

	c.setvq(0,1,0,3.14);
	b.addF(Vector3(0.1, 0, 0));
	return 0;
}

int function_step(double time)	// time in s
{
	a.clearF(); b.clearF(); c.clearF();
	double G = 0.001;
	a.addF( G * a.m * b.m / (a.l - b.l).len() / (a.l - b.l).len() * (b.l - a.l).nor());
	//a.addF( G * a.m * c.m / (a.l - c.l).len() / (a.l - c.l).len() * (c.l - a.l).nor());
	b.addF( G * a.m * b.m / (a.l - b.l).len() / (a.l - b.l).len() * (a.l - b.l).nor());

	a.run(time);
	b.run(time);
	c.run(time);
	return 0;
}

/* --------------- OpenGL draw functions --------------------*/
int function_draw()
{
	a.draw();
	b.draw();
	c.draw();
	return 0;
}

int function_draw2()
{
	return 0;
}

