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
//
#include "DynamicsEngine.h"

DynamicsEngine dynamicsEngine;

Sphere a(1,1,0);
Box b(0,0,0);
Cylinder c(-1,0,0);
Sphere d(-1, -1, 0);
//Convexhull d(0.5, 0.5, 0.5);

/* --------------- MainLoop functions --------------------*/
int simu_exit()
{
	return 0;
}

int simu_init(int ScreenWidth, int ScreenHeight)
{
	EyeWInit = 45;
	WindowX = ScreenWidth / 4;

	dynamicsEngine.registerObject(&a);
	dynamicsEngine.registerObject(&b);
	dynamicsEngine.registerObject(&c);
	dynamicsEngine.registerObject(&d);

	printf("a.type = %d", a.type);
	printf("b.type = %d", b.type);
	printf("c.type = %d", c.type);

	a.setSize(0.1);
	b.setSize(0.2, 0.2, 0.2);
	b.setq(0, 0, 1, 3.1415926/4);
	c.setSize(0.1,0.3);
	d.setSize(0.1);

	/*
	double points[] = {
		0.1, 0.2, 0.3,
		0.2, 0.3, 1.3,
	};
	d.setPoint(2, points);
	for (int i = 0; i < d.n; i++)
		printf("%s\n",d.points[i].toStr());
	*/

	a.setv(0.61, -0.61, 0);
	c.setv(0.0, -0.6 * 1.42, 0);

	a.setm(1);
	b.setm(1000);
	c.setm(1);


	c.setvq(0,1,0,3.14);
	b.addF(Vector3(0.1, 0, 0));
	return 0;
}

int simu_step(double time)	// time in s
{
	a.clearF(); b.clearF(); c.clearF();

	/*
	double G = 0.001;
	a.addF( G * a.m * b.m / (a.l - b.l).len() / (a.l - b.l).len() * (b.l - a.l).nor());
	a.addF( G * a.m * c.m / (a.l - c.l).len() / (a.l - c.l).len() * (c.l - a.l).nor());

	b.addF( G * a.m * b.m / (a.l - b.l).len() / (a.l - b.l).len() * (a.l - b.l).nor());
	b.addF( G * c.m * b.m / (b.l - c.l).len() / (b.l - c.l).len() * (c.l - b.l).nor());

	c.addF( G * a.m * c.m / (a.l - c.l).len() / (a.l - c.l).len() * (a.l - c.l).nor());
	c.addF( G * c.m * b.m / (b.l - c.l).len() / (b.l - c.l).len() * (b.l - c.l).nor());

	a.addF( -a.v*0.04);
	b.addF( -b.v*0.04);
	c.addF( -c.v*0.04);
	*/
	
	a.addF( (a.l - b.l).len() * (b.l - a.l).nor());
	c.addF( (c.l - b.l).len() * (b.l - c.l).nor());

	a.addF( -a.v * 0.04);
	c.addF( -c.v * 0.04);

	dynamicsEngine.run(time);

	a.run(time);
	b.run(time);
	c.run(time);
	return 0;
}

/* --------------- OpenGL draw functions --------------------*/
int simu_draw()
{
	a.draw();
	b.draw();
	c.draw();
	d.draw();
	return 0;
}

int simu_draw2()
{
	return 0;
}

