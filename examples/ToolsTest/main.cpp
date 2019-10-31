/*---------------------------------------------------------*/
/*
   	Weixu ZHU (Harry)
   		zhuweixu_harry@126.com
	
	Version 1.0
	Version 1.1 : change opengl debug layout

*/
/*---------------------------------------------------------*/

#include <stdio.h>

#include "Vector3.h"
#include "Quaternion.h"

#include "List.h"

List<Vector3> a;

List<List<Vector3>> b;

int main()
{
	Vector3 v(11,11,11);
	printf("v address = %p\n", &v);
	a.pushHead(Vector3(1,2,3));
	a.pushHead(Vector3(4,5,6));
	a.pushHead(v);
 	for (a.firstFocal(); !a.focalAtTail(); a.nextFocal())
		printf("%s, %p\n", a.getFocal().toStr(), &a.getFocal());
	printf("\n");

	a.firstFocal();
	a.put(1,2,3);
 	for (a.firstFocal(); !a.focalAtTail(); a.nextFocal())
		printf("%s\n", a.getFocal().toStr());
	printf("\n");

	a.pushHead(Vector3(4,5,6));
 	for (a.firstFocal(); !a.focalAtTail(); a.nextFocal())
		printf("%s\n", a.getFocal().toStr());
	printf("\n");

	printf("%s\n", a[0].toStr());
	printf("%s\n", a[1].toStr());
	printf("%s\n", a[2].toStr());
	printf("\n");

	printf("-----------------------------------\n");
	a.pushHead(Vector3(1,2,3));
	a.pushHead(Vector3(4,5,6));
	printf("List a = \n");
 	for (a.firstFocal(); !a.focalAtTail(); a.nextFocal())
		printf("%s, %p\n", a.getFocal().toStr(), &a.getFocal());
	printf("\n");

	b.pushHead(a);
	b.pushHead(a);
	printf("List b = \n");
 	for (b.firstFocal(); !b.focalAtTail(); b.nextFocal())
	{
		printf("\tList b child = \n");
 		for (a.firstFocal(); !a.focalAtTail(); a.nextFocal())
			printf("\t%s, %p\n", a.getFocal().toStr(), &a.getFocal());
		printf("\t-------\n");
	}
	printf("\n");

	return 0;
}

