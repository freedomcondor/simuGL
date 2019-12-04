/*----------------------------------------*/
/*	Weixu ZHU (Harry)
		zhuweixu_harry@126.com
	Version 1.0
*/
/*----------------------------------------*/

#include "Cylinder.h"

void Cylinder::init()
{
	setSize(1,1);
	type = CylinderType;
}

Cylinder::Cylinder():Object() { init(); }

Cylinder::Cylinder(double x,double y,double z):Object(x,y,z) { init(); }

Cylinder::Cylinder(const Vector3& _x):Object(_x) { init(); }

Cylinder::Cylinder(const Vector3& _x, const Quaternion& _y):Object(_x,_y) { init(); }

int Cylinder::setSize(double _r,double _h)
{
	r = _r; h = _h;
	return 0;
}
