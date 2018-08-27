#ifndef OBJECT
#define OBJECT

#include "QParticle.h"
#include "Quaternion.h"
#include "Vector3.h"

struct SubObj;

class Object : public QParticle
{
public:
	int subN;
	struct SubObj *subObj[20];

	Object();
	Object(double x,double y,double z);
	Object(const Vector3& _x);
	Object(const Vector3& _x, const Quaternion& _y);
	~Object();

	virtual void structDefine();
	void reLocateSub();

	int run(double time);
	virtual void draw();
};

struct SubObj
{
	Vector3 l;
	Quaternion q;
	Object *obj;
};

#endif
