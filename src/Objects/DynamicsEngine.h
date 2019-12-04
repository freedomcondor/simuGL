#include "Object.h"
#include "Sphere.h"
#include <vector>

class DynamicsEngine
{
public:
	DynamicsEngine();
	~DynamicsEngine();

	void registerObject(Object* ob);
	void run(double time);
	void detect(Object* a, Object* b, double time);
	void detect(Sphere* a, Sphere* b, double time);
private:
	std::vector<Object*> objects;
	int nObjects;
};
