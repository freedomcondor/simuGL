#include"GLTools.h"

#include <math.h>

#define pi 3.1415926
#define ZERO 0.0000001

/* --------------- draw obj --------------------*/
#include "Box.h"
void Box::draw()
{
	Vector3 axis = this->q.getAxis();
	double ang = this->q.getAng();

	glPushMatrix();
	glTranslatef(this->l.x, this->l.y, this->l.z);
	glRotatef(ang*180/pi,axis.x,axis.y,axis.z);
	if ((this->x != 0) && (this->y != 0) && (this->z != 0))
	{
		glScalef(this->x, this->y, this->z);
		glutSolidCube(1);
	}
	glPopMatrix();
}

#include "Sphere.h"
void Sphere::draw()
{
	glPushMatrix();
	glTranslatef(this->l.x, this->l.y, this->l.z);
	if (this->r != 0)
		glutSolidSphere(r, 32, 32); 	// slices for longitude and latitude
	glPopMatrix();
}

#include "Cylinder.h"
void Cylinder::draw()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	Vector3 axis = this->q.getAxis();
	double ang = this->q.getAng();
	glPushMatrix();
	glTranslatef(this->l.x, this->l.y, this->l.z);
	glRotatef(ang*180/pi,axis.x,axis.y,axis.z);
	glTranslatef(0, 0, -this->h/2);
	if ((this->r != 0) && (this->h != 0))
	{
		int slices = 32;

		glScalef(this->r, this->r, this->h);
		gluCylinder(quadratic,1,1,1, slices, slices);

		glBegin(GL_POLYGON);
		for (int i = 0; i < slices; i++)
			glVertex3f(cos(2*pi/slices*i),sin(2*pi/slices*i),0);
		glEnd();

		glTranslatef(0, 0, 1);
		glBegin(GL_POLYGON);
		for (int i = 0; i < slices; i++)
			glVertex3f(cos(2*pi/slices*i),sin(2*pi/slices*i),0);
		glEnd();
	}
	glPopMatrix();
}

/* TODO; move to modules
#include "CellularAutomaton.h"	// or delete line Box.cpp (any cpp with #include "CellularAutomaton.h") in CMakeList.txt
int CellularAutomaton::draw(int x, int y, int z, int xl, int yl, int zl)
{
	double length = 0.01;
	for (int i = x; i < x+xl; i++)
		for (int j = y; j < y+yl; j++)
			for (int k = z; k < z+zl; k++)
				if (world->get(i,j,k) > 0.5)
					drawCube(length*0.95, i * length, j*length, k*length,
					                      1,          0,        0,
					                      0,          0,        1);

	return 0;
}
*/

