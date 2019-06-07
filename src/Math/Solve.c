#include "Solve.h"
#include <math.h>

#include <stdio.h>

double cuberoot(double x)
{
	if (x < 0)
		return -pow(-x, 1.0/3);
	return pow(x, 1.0/3);
}

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

void Quadratic(double a, double b, double c, 
               int *n, double *x1, double *x2)
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

void Cubic(double a, double b, double c, double d, 
           int *n, double *x1, double *x2, double *x3)
{
	if (a == 0)
	{
		*x3 = 0;
		Quadratic(b, c, d, n, x1, x2);
		return;
	}

	// x = y - b/3
	// y3 + py + q = 0
	double p = -b*b/(3*a*a) + c/a;
	double q = 2*b*b*b/(27*a*a*a) - b*c/(3*a*a) + d/a;
	double delta = q*q/4 + p*p*p/27;

	if (delta >= 0)
	{
		*n = 1;
		*x1 = 
			cuberoot(-q/2+sqrt(delta)) + 
			cuberoot(-q/2-sqrt(delta)) - b/(3*a);
		*x2 = 0;
		*x3 = 0;
	}
	else
	{
		*n = 3;
		*x1 = -3*q/p - b/(3*a);
		*x2 = 3*q/(2*p) + 3*sqrt(3)*sqrt(-delta)/p - b/(3*a);
		*x2 = 3*q/(2*p) - 3*sqrt(3)*sqrt(-delta)/p - b/(3*a);
	}
}
