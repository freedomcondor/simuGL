/*---------------------------------------------------------*/
/*
   	Weixu ZHU (Harry)
   		zhuweixu_harry@126.com
	
	Version 1.0
	Version 1.1 : change opengl debug layout

*/
/*---------------------------------------------------------*/

#include <stdio.h>

#include "Solve.h"

int main()
{
	double x1, x2, x3;
	int n;

	// (x + 1)^2 = 0
	Cubic(0, 1, 2, 1, &n, &x1, &x2, &x3);
	printf("x3 = 0 : n = %d, x1 = %lf, x2 = %lf, x3 = %lf\n", n, x1, x2, x3);

	// x3 = 0
	Cubic(1, 0, 0, 0, &n, &x1, &x2, &x3);
	printf("x3 = 0 : n = %d, x1 = %lf, x2 = %lf, x3 = %lf\n", n, x1, x2, x3);

	// x3 = -1
	Cubic(1, 0, 0, 1, &n, &x1, &x2, &x3);
	printf("x3 = -1 : n = %d, x1 = %lf, x2 = %lf, x3 = %lf\n", n, x1, x2, x3);

	// (x-1)(x-2)(x-3) = 0
	Cubic(1, -6, 11, -6, &n, &x1, &x2, &x3);
	printf("(x-1)(x-2)(x-3) = 0 : n = %d, x1 = %lf, x2 = %lf, x3 = %lf\n", n, x1, x2, x3);

	// (x-1)(x-1)(x-3) = 0
	Cubic(1, -5, 7, -3, &n, &x1, &x2, &x3);
	printf("(x-1)(x-1)(x-3) = 0 : n = %d, x1 = %lf, x2 = %lf, x3 = %lf\n", n, x1, x2, x3);

	return 0;
}

