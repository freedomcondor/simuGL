#ifndef BIRD 
#define BIRD 

#include "Object.h"
#include "Cylinder.h"
#include "Vector3.h"
#include "Quaternion.h"

#include "BirdCtrl.h"

#define MAXNEIGHBOUR 400

struct neighbour
{
	Vector3 loc;
	Quaternion dir;
	Vector3 speed;
};

class Bird : public Object
{
public:
	Bird();
	Bird(double x,double y,double z);
	Bird(const Vector3& _x);
	Bird(const Vector3& _x, const Quaternion& _y);

	Cylinder body, left, right;
	struct SubObj locBody, locLeft, locRight;
	void structInit();

	int run(double time);
	int setspeed(Vector3& v);
	BirdCtrl ctrl;

	struct neighbour neighbours[MAXNEIGHBOUR];
	int nNeighbours;
	int getNeighbours(int n, Bird allBirds[]);

	double sight = 0.30;
};

#endif
