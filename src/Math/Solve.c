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
	if ((isZERO_SOLVE(a)) && (isZERO_SOLVE(b)))
	{
		*n = -1; 
		*x = 0;
		return;
	}
	else if ((isZERO_SOLVE(a)) && (!isZERO_SOLVE(b)))
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

	if (isZERO_SOLVE(a))
	{
		*x2 = 0;
		Linar(b, c, n, x1);
		return;
	}

	if (delta > ZERO_SOLVE) 
	{
		*n = 2;
		*x1 = (-b + sqrt(delta)) / (2 * a);
		*x2 = (-b - sqrt(delta)) / (2 * a);
	}
	else if (isZERO_SOLVE(delta))
	{
		*n = 1;
		*x1 = (-b) / (2 * a);
		*x2 = 0;
	}
	else if (delta < -ZERO_SOLVE)
	{
		*n = 0;
		*x1 = 0;
		*x2 = 0;
	}
}

void Cubic(double a, double b, double c, double d, 
           int *n, double *x1, double *x2, double *x3)
{
	if (isZERO_SOLVE(a))
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

	if (delta > ZERO_SOLVE)
	{
		*n = 1;
		*x1 = 
			cuberoot(-q/2+sqrt(delta)) + 
			cuberoot(-q/2-sqrt(delta)) - b/(3*a);
		*x2 = 0;
		*x3 = 0;
	}
	else if (isZERO_SOLVE(delta))
	{
		if (isZERO_SOLVE(q))
		{
			*n = 1;
			*x1 = -b/(3*a);
			*x2 = 0;
			*x3 = 0;
		}
		else
		{
			*n = 2;
			*x1 = 2 * cuberoot(-q/2) - b/(3*a);
			*x2 = -cuberoot(-q/2) - b/(3*a);
			*x3 = 0;
		}
	}
	else
	{
		*n = 3;
		*x1 = 3*q/p - b/(3*a);
		*x2 = -3*q/(2*p) + 3*sqrt(3)*sqrt(-delta)/p - b/(3*a);
		*x3 = -3*q/(2*p) - 3*sqrt(3)*sqrt(-delta)/p - b/(3*a);
	}
}

// solve ax4 + bx3 + cx2 + dx + e = 0
void Quartic(double a, double b, double c, double d, double e,
             int *n, double *x1, double *x2, double *x3, double *x4)
{
	if (isZERO_SOLVE(a))
	{
		*x4 = 0;
		Cubic(b, c, d, e, n, x1, x2, x3);
		return;
	}

	// x = y - b/4a
	// y4 + py2 + qy + r = 0
	double p = -3*b*b/(8*a*a) + c/a;
	double q = b*b*b/(8*a*a*a) - b*c/(2*a*a) + d/a;
	double r = -3*b*b*b*b/(256*a*a*a*a) + b*b*c/(16*a*a*a) - b*d/(4*a*a) + e/a;

	// (y2+p/2)^2 + qy + (r-p2/4) = 0
}
