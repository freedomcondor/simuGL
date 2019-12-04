#include "DynamicsEngine.h"
#include <stdio.h>

DynamicsEngine::DynamicsEngine()
{
	nObjects = 0;
}

DynamicsEngine::~DynamicsEngine()
{
}


void DynamicsEngine::registerObject(Object* ob)
{
	objects.push_back(ob);
	nObjects++;
}

void DynamicsEngine::run(double time)
{
	printf("i am run here %d\n", nObjects);

	for (int i = 0; i < nObjects - 1; i++)
		for (int j = i + 1; j < nObjects; j++)
		{
			if ( (objects[i]->type == Object::ObjectType::SphereType) && 
			     (objects[j]->type == Object::ObjectType::SphereType)    )
				detect((Sphere*)objects[i], (Sphere*)objects[j], time);
		}
}


void DynamicsEngine::detect(Object* a, Object* b, double time)
{
	for (int i = 0; i < a->subN; i++)
		for (int j = 0; j < b->subN; j++)
		{
		}
}
void DynamicsEngine::detect(Sphere* a, Sphere* b, double time)
{
	Vector3 aNewLoc = a->l + a->v * time;
	Vector3 bNewLoc = b->l + b->v * time;
	if ((aNewLoc - bNewLoc).len() < a->r + b->r)
		printf("hit!\n");
}
