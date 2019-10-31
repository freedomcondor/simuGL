#ifndef SOLVE
#define SOLVE

#ifdef __cplusplus
extern "C" {
#endif

#define ZERO_SOLVE 0.0000001
#define isZERO_SOLVE(X) (X < ZERO_SOLVE) && (X > -ZERO_SOLVE)

// solve ax + b = 0
// n = -1 means infinite number of results
void Linar(double a, double b, int *n, double *x);

// solve ax2 + bx + c = 0
void Quadratic(double a, double b, double c, 
               int *n, double *x1, double *x2);

// solve ax3 + bx2 + cx + d = 0
void Cubic(double a, double b, double c, double d, 
           int *n, double *x1, double *x2, double *x3);

// solve ax4 + bx3 + cx2 + dx + e = 0
void Quartic(double a, double b, double c, double d, double e,
             int *n, double *x1, double *x2, double *x3, double *x4);

#ifdef __cplusplus
}
#endif

#endif
