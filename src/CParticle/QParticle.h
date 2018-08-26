/*----------------------------------------*/
/*	Weixu ZHU (Harry)
		zhuweixu_harry@126.com
	Version 2.0
		combine Particle and QParticle
*/
/*----------------------------------------*/

#ifndef QPARTICLE
#define QPARTICLE

#include "Vector3.h"
#include "Quaternion.h"

class QParticle
{
public:
	Vector3 l,v,a;
	Quaternion q, vq, aq;

	QParticle();
	QParticle(double x,double y,double z);
	QParticle(const Vector3& _x);
	QParticle(double x,double y,double z, 
				double qx,double qy,double qz,double qw);
	QParticle(const Vector3& _x, const Quaternion& _y);
	~QParticle();

	QParticle& setl(const Vector3& _x);
	QParticle& setl(double x,double y,double z);
	QParticle& setv(const Vector3& _x);
	QParticle& setv(double x,double y,double z);
	QParticle& seta(const Vector3& _x);
	QParticle& seta(double x,double y,double z);

	QParticle& setq(const Quaternion& _x);
	QParticle& setq(double qx,double qy,double qz,double qw);
	QParticle& setvq(const Quaternion& _x);
	QParticle& setvq(double qx,double qy,double qz,double qw);
	QParticle& setaq(const Quaternion& _x);
	QParticle& setaq(double qx,double qy,double qz,double qw);

	Vector3 getFront() const;
	Vector3 getUp() const;

	int run(double time);
};

#endif
