#include "Object.h"

Object::Object() : QParticle() {this->structDefine();}
Object::Object(double x,double y,double z) : QParticle(x,y,z) {this->structDefine();}
Object::Object(const Vector3& _x) : QParticle(_x) {this->structDefine();}
Object::Object(const Vector3& _x, const Quaternion& _y) : QParticle(_x,_y) {this->structDefine();}

Object::~Object()
{
	for (int i = 0; i < subN; i++)
	{
		delete(subObj[i]->obj);
		delete(subObj[i]);
	}
}

void Object::reLocateSub()
{
	for (int i = 0; i < subN; i++)
	{
		subObj[i]->obj->l = l + q.toRotate(subObj[i]->l);
		//subObj[i]->obj->l = l + subObj[i]->l;
		subObj[i]->obj->q = q * subObj[i]->q;
	}
}

int Object::run(double time)
{
	QParticle::run(time);
	reLocateSub();
}

void Object::structDefine()
{
				printf("i am object's structDefine\n");
	subN = 0;
}

void Object::draw()
{
	for (int i = 0; i < subN; i++)
	{
		subObj[i]->obj->draw();
	}
}
