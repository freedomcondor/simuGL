/*----------------------------------------*/
/*	Weixu ZHU (Harry)
		zhuweixu_harry@126.com
	Version 1.0
	Version 1.1  resub in setl and setq
*/
/*----------------------------------------*/

#include "Object.h"

Object::Object() : QParticle() {subN = 0;}
Object::Object(double x,double y,double z) : QParticle(x,y,z) {subN = 0;}
Object::Object(const Vector3& _x) : QParticle(_x) {subN = 0;}
Object::Object(const Vector3& _x, const Quaternion& _y) : QParticle(_x,_y) {subN = 0;}

Object::~Object()
{
	// try not to use dynamic memory
	/*
	for (int i = 0; i < subN; i++)
	{
		delete(subObj[i]->obj);
		delete(subObj[i]);
	}
	*/
}

void Object::reLocateSub()
{
	for (int i = 0; i < subN; i++)
	{
		subObj[i]->obj->l = l + q.toRotate(subObj[i]->l);
		subObj[i]->obj->q = q * subObj[i]->q;
		subObj[i]->obj->reLocateSub();
	}
}

int Object::run(double time)
{
	QParticle::run(time);
	reLocateSub();
	return 0;
}

Object& Object::setl(const Vector3& _x)
{
	QParticle::setl(_x);
	reLocateSub();
	return *this;
}
Object& Object::setl(double x,double y,double z)
{
	QParticle::setl(x, y, z);
	reLocateSub();
	return *this;
}
Object& Object::setq(const Quaternion& _x)
{
	QParticle::setq(_x);
	reLocateSub();
	return *this;
}
Object& Object::setq(double qx,double qy,double qz,double qw)
{
	QParticle::setq(qx, qy, qz, qw);
	reLocateSub();
	return *this;
}

void Object::draw()
{
	for (int i = 0; i < subN; i++)
	{
		subObj[i]->obj->draw();
	}
}
