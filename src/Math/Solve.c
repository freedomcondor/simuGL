#include "Solve.h"
#include <math.h>

void Linar(double a, double b, int *n, double *x)
{
	if ((a == 0) && (b == 0))
	{
		*n = -1; 
		*x = 0;
		return;
	}
	else if ((a == 0) && (b != 0))
	{
		*n = 0; 
		*x = 0;
		return;
	}

	*n = 1; 
	*x = -b / a;
}

void Quadratic(double a, double b, double c, int *n, double *x1, double *x2)
{
	double delta = b*b - 4*a*c;

	if (a == 0)
	{
		*x2 = 0;
		Linar(b, c, n, x1);
		return;
	}

	if (delta > 0) 
	{
		*n = 2;
		*x1 = (-b + sqrt(delta)) / (2 * a);
		*x2 = (-b - sqrt(delta)) / (2 * a);
	}
	else if (delta == 0)
	{
		*n = 1;
		*x1 = (-b) / (2 * a);
		*x2 = 0;
	}
	else if (delta == 0)
	{
		*n = 0;
		*x1 = 0;
		*x2 = 0;
	}
}
