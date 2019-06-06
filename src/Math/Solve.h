#ifndef SOLVE
#define SOLVE

#ifdef __cplusplus
extern "C" {
#endif

// solve ax + b = 0
void Linar(double a, double b, int *n, double *x);

// solve ax2 + bx + c = 0
void Quadratic(double a, double b, double c, int *n, double *x1, double *x2);
//void Quadratic_i(double a, double b, double c, int *n, double *x1, double *x2);


#ifdef __cplusplus
}
#endif

#endif
