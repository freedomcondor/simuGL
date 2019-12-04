/*----------------------------------------*/
/*	Weixu ZHU (Harry)
		zhuweixu_harry@126.com
	Version 1.0
*/
/*----------------------------------------*/

#include "Sphere.h"

void Sphere::init()
{
	setSize(1);
	type = SphereType;
}

Sphere::Sphere():Object() { init(); }
Sphere::Sphere(double x,double y,double z):Object(x,y,z) { init(); }
Sphere::Sphere(const Vector3& _x):Object(_x) { init(); }
Sphere::Sphere(const Vector3& _x, const Quaternion& _y) :Object(_x,_y) { init(); }

int Sphere::setSize(double _x)
{
	r = _x;
	return 0;
}
