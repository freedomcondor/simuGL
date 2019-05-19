#include "Bird.h"

#include <stdlib.h>

#define PI 3.1415926
Bird::Bird() : Object() {structInit();}
Bird::Bird(double x,double y,double z) : Object(x,y,z) {structInit();}
Bird::Bird(const Vector3& _x) : Object(_x) {structInit();}
Bird::Bird(const Vector3& _x, const Quaternion& _y) : Object(_x,_y) {structInit();}

void Bird::structInit()
{
	subN = 3;

	subObj[0] = &locBody;
	locBody.l = Vector3(0,0,0);
	locBody.q = Quaternion(0,1,0,PI/2);
	locBody.obj = &body;
	body.setSize(0.005,0.03);

	subObj[1] = &locLeft;
	locLeft.l = Vector3(0,0.010,0);
	locLeft.q = Quaternion(1,1,0,PI/2);
	locLeft.obj = &left;
	left.setSize(0.005,0.01);

	subObj[2] = &locRight;
	locRight.l = Vector3(0,-0.010,0);
	locRight.q = Quaternion(-1,1,0,PI/2);
	locRight.obj = &right;
	right.setSize(0.005,0.01);

	reLocateSub();
}

int Bird::run(double time)
{
	ctrl.step(time);
	return Object::run(time);
}

int Bird::setspeed(Vector3& v)
{
	setv(v);
	return 0;
}

int Bird::getNeighbours(int n, Bird allBirds[])
{
	nNeighbours = 0;
	for (int i = 0; i < n; i++)
	{
		if (&allBirds[i] == this) continue;
		if ((allBirds[i].l - l).len() < sight)
		{
			neighbours[nNeighbours].loc = q.inv().toRotate(
				allBirds[i].l - l
			);
			neighbours[nNeighbours].dir = allBirds[i].q * q.inv();
			neighbours[nNeighbours].speed = q.inv().toRotate(
				allBirds[i].v
			);
			nNeighbours++;
		}
	}
	return 0;
}
