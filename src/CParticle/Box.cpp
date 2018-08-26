#include "Box.h"

Box::Box():QParticle()
{
	setSize(1,1,1);
}

Box::Box(double x,double y,double z)
	:QParticle(x,y,z)
{
	setSize(1,1,1);
}

Box::Box(const Vector3& _x)
	:QParticle(_x)
{
	setSize(1,1,1);
}

Box::Box(const Vector3& _x, const Quaternion& _y)
	:QParticle(_x,_y)
{
	setSize(1,1,1);
}

Box::~Box()
{
}

int Box::setSize(double _x,double _y,double _z)
{
	x = _x; y = _y; z = _z;
	return 0;
}
