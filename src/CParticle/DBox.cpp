#include "DBox.h"

#include <stdlib.h>

#define PI 3.1415926
DBox::DBox() : Object() {}
DBox::DBox(double x,double y,double z) : Object(x,y,z) {}
DBox::DBox(const Vector3& _x) : Object(_x) {}
DBox::DBox(const Vector3& _x, const Quaternion& _y) : Object(_x,_y) {}

void DBox::structDefine()
{
				printf("i am DBox's structDefine\n");
	subN = 2;

	subObj[0] = (struct SubObj *)malloc(sizeof(struct SubObj));
	subObj[0]->l = Vector3(0,0.2,0);
	subObj[0]->q = Quaternion(0,0,1,-PI/4);
	subObj[1] = (struct SubObj *)malloc(sizeof(struct SubObj));
	subObj[1]->l = Vector3(0,-0.2,0);
	subObj[1]->q = Quaternion(0,0,1,PI/4);

	Box *a = new Box;
	Box *b = new Box;
	a->setSize(0.1,0.2,0.3);
	b->setSize(0.1,0.2,0.3);
	subObj[0]->obj = a;
	subObj[1]->obj = b;

	reLocateSub();
}
