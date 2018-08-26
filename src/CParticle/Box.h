#ifndef BOX
#define BOX

#include "QParticle.h"

class Box : public QParticle
{
public:
	double x,y,z;

	Box();
	Box(double x,double y,double z);
	Box(const Vector3& _x);
	Box(const Vector3& _x, const Quaternion& _y);
	~Box();

	int setSize(double x,double y,double z);
	int draw();	// implement in openGL
};

#endif
