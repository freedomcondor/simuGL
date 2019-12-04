/*----------------------------------------*/
/*	Weixu ZHU (Harry)
		zhuweixu_harry@126.com
	Version 1.0
	Version 1.1  resub in setl and setq
*/
/*----------------------------------------*/

#ifndef OBJECT
#define OBJECT

#include "QParticle.h"
#include "Quaternion.h"
#include "Vector3.h"

#define MAXSUBN 20


struct SubObj;

class Object : public QParticle
{
public:
	int subN;
	struct SubObj *subObj[MAXSUBN];

	void init();
	Object();
	Object(double x,double y,double z);
	Object(const Vector3& _x);
	Object(const Vector3& _x, const Quaternion& _y);
	~Object();

	void reLocateSub();
	int run(double time);
	virtual void draw();

	enum ObjectType{MultiBodyType, BoxType, SphereType, CylinderType} type;

	Object& setl(const Vector3& _x);
	Object& setl(double x,double y,double z);
	Object& setq(const Quaternion& _x);
	Object& setq(double qx,double qy,double qz,double qw);
};

struct SubObj
{
	Vector3 l;
	Quaternion q;
	Object *obj;
};

#endif
