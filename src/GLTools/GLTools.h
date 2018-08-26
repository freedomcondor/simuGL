/*---------------------------------------------------------*/
/*
   	Weixu ZHU (Harry)
   		zhuweixu_harry@126.com
	
	Version 1.0
	Version 1.1 : change OpenGl layout

*/
/*---------------------------------------------------------*/

//#define mac
#ifdef mac
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

/*------------ Function Control Channels ------------*/
extern double CH1,CH1_MAX,CH1_MIN,CH1_STEP;
extern double CH2,CH2_MAX,CH2_MIN,CH2_STEP;
extern int CMDCH1;

/*------------ Draw Functions -----------------------*/
int drawSphere(double x, double y, double z, double r);
//int drawCube(double half, double x, double y, double z,
//						  double ex,double ey,double ez);

int drawCube(double half, double x, double y, double z, 
						  double fx,double fy,double fz,
						  double ux,double uy,double uz);

int drawCube(double half, double x, double y, double z, 
						  double fx,double fy,double fz,
						  double ux,double uy,double uz, char command[]);

int drawCylinder(	double base, double top, double height,
				double lx,	double ly, double lz,
				double ex,	double ey, double ez
			);

/*------------- MainLoop Functions -------------------*/
int function_init();
int function_draw();
int function_draw2();
int function_step(double time);
int function_exit();
