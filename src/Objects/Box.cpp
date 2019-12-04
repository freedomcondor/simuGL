/*----------------------------------------*/
/*	Weixu ZHU (Harry)
		zhuweixu_harry@126.com
	Version 1.0
	Version 1.1 : add setSize(vector3)
*/
/*----------------------------------------*/

#include "Box.h"

void Box::init()
{
	setSize(1,1,1);
	type = BoxType;
}

Box::Box():Object() { init(); }
Box::Box(double x,double y,double z) :Object(x,y,z) { init(); }
Box::Box(const Vector3& _x) :Object(_x) { init(); }
Box::Box(const Vector3& _x, const Quaternion& _y):Object(_x,_y) { init(); }

int Box::setSize(double _x,double _y,double _z)
{
	x = _x; y = _y; z = _z;
	return 0;
}

int Box::setSize(const Vector3& _x)
{
	x = _x.x; y = _x.y; z = _x.z;
	return 0;
}
