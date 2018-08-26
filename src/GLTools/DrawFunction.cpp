/*---------------------------------------------------------*/
/*
   	Weixu ZHU (Harry)
   		zhuweixu_harry@126.com
	
	Version 1.0
	Version 1.1 : change OpenGl layout

*/
/*---------------------------------------------------------*/

#include"GLTools.h"

#include <math.h>
#include <string.h>

#define pi 3.1415926
#define ZERO 0.0000001

/*
#define Max_plot 10000
double buffer_draw2 = 0;
double plot_y_max = 0;
double plot_x_max = 0;
double datalog[Max_plot];
*/

	/*
int function_draw2()
{
	for (int i = 1; i <= herd.time; i++)
	{
		if (herd.time < plot_x_max)
		{
		glBegin(GL_LINES);
			glVertex3f( (i-1)/plot_x_max,	datalog[i-1]/plot_y_max,0.0f);
			glVertex3f(  i/plot_x_max,		datalog[i] / plot_y_max,0.0f);
		glEnd();
		}
		else
		{
		glBegin(GL_LINES);
			glVertex3f( 1.0*(i-1)/herd.time,	datalog[i-1]/plot_y_max,0.0f);
			glVertex3f( 1.0* i/herd.time,		datalog[i] / plot_y_max,0.0f);
		glEnd();
		}
	}
		
	return 0;
}
	*/

/*------------ Draw Functions -----------------------*/
int drawSphere(double x, double y, double z, double r)
{
	glTranslatef(x,y,z);
	glutSolidSphere(r,10,10);
	glTranslatef(-x,-y,-z);

	return 0;
}

int drawCube(double half, double x, double y, double z, 
						  double fx,double fy,double fz,
						  double ux,double uy,double uz)
{
	drawCube(half,x,y,z,fx,fy,fz,ux,uy,uz,"0");
	return 0;
}

int drawCube(double half, double x, double y, double z, 
						  double fx,double fy,double fz,
						  double ux,double uy,double uz, char command[])
	// f is front, u is up
{
	double xaxis,yaxis,zaxis,axis,angleaxis;
	double fxbase,fybase,fzbase;
	double uxbase,uybase,uzbase;
	double fe,ue;
	double fxdiff,fydiff,fzdiff;
	double uxdiff,uydiff,uzdiff;
	double rf,xrf, yrf, zrf;  // rotation from
	double rt,xrt, yrt, zrt;  // rotation to
	double temp;
	double cos;

	int rotateflag = 1;

	if (((fx-0)*(fx-0)<ZERO) && ((fy-0)*(fy-0)<ZERO) && ((fz-0)*(fz-0)<ZERO))
		rotateflag = 0;
	if (((ux-0)*(ux-0)<ZERO) && ((uy-0)*(uy-0)<ZERO) && ((uz-0)*(uz-0)<ZERO))
		rotateflag = 0;
	if ((fx == 1) && (fy == 0) && (fz == 0))
	{
		drawCube(half, x,y,z,  ux,uy,uz,  fx,fy,fz, command);
		return 0;
	}

	//  some problem for specific situation
	// 		only general case and
	// 		only work for right angle and u = 0,0,1
	if (rotateflag == 1)
	{
		fe = sqrt(fx * fx + fy * fy + fz * fz);
		if (fe == 0) return -1;
		ue = sqrt(ux * ux + uy * uy + uz * uz);
		if (ue == 0) return -1;
		fx /= fe; fy /= fe; fz /= fe;
		ux /= ue; uy /= ue; uz /= ue;

		// fbase = (1,0,0), ubase = (0,0,1)
		fxbase = 1; fybase = 0; fzbase = 0;
		uxbase = 0; uybase = 0; uzbase = 1;

		//  fdiff = f - fbase,  udiff = u - ubase
		fxdiff=fx-fxbase; fydiff=fy-fybase; fzdiff=fz-fzbase;
		uxdiff=ux-uxbase; uydiff=uy-uybase; uzdiff=uz-uzbase;

		// xaxis = fdiff * udiff
		xaxis = fydiff * uzdiff - uzdiff * fydiff;
		yaxis = fzdiff * uxdiff - uxdiff * fzdiff;
		zaxis = fxdiff * uydiff - uydiff * fxdiff;

		axis = sqrt(xaxis * xaxis + yaxis * yaxis + zaxis * zaxis);
		if (!(axis*axis < ZERO))
			{xaxis /= axis; yaxis /= axis; zaxis /= axis;}

		// rot_from = base - axis .* f * axis
		temp = xaxis * fx + yaxis * fy + zaxis * fz;
		xrf = fxbase - temp * xaxis;
		yrf = fybase - temp * yaxis;
		zrf = fzbase - temp * zaxis;
		xrt = fx - temp * xaxis;
		yrt = fy - temp * yaxis;
		zrt = fz - temp * zaxis;
		rf = sqrt(xrf*xrf + yrf*yrf + zrf*zrf);
		if (!(rf*rf < ZERO))
			{xrf /= rf; yrf /= rf; zrf /= rf;}
		rt = sqrt(xrt*xrt + yrt*yrt + zrt*zrt);
		if (!(rt*rt < ZERO))
			{xrt /= rt; yrt /= rt; zrt /= rt;}

		cos = xrf * xrt + yrf * yrt + zrf * zrt;
		angleaxis = acos(cos);
		xaxis = yrf * zrt - zrf * yrt;
		yaxis = zrf * xrt - xrf * zrt;
		zaxis = xrf * yrt - yrf * xrt;

		//angleaxis = acos((xbase*ex+ybase*ey+zbase*ez)/e) + pi;
		//printf("%lf %lf %lf %lf\n",angleaxis,xaxis,yaxis,zaxis);
	}

	///*
	glTranslatef(x,y,z);
	if (rotateflag == 1)
		glRotatef(angleaxis*180/pi,xaxis,yaxis,zaxis);

	if (strcmp(command,"wire") == 0)
		glutWireCube(half);
	else
		glutSolidCube(half);

	if (rotateflag == 1)
		glRotatef(-angleaxis*180/pi,xaxis,yaxis,zaxis);
	glTranslatef(-x,-y,-z);
	//*/

	return 0;
}

int drawCylinder(	double base, double top, double height,
				double lx,	double ly, double lz,
				double ex,	double ey, double ez
			)
{
	double xaxis,yaxis,zaxis,angleaxis;
	double xbase,ybase,zbase;
	double e;
	int rotateflag = 1;
	GLUquadricObj *quadratic;

	quadratic = gluNewQuadric();

	//printf("l: %lf %lf %lf\n",lx,ly,lz);
	//printf("e: %lf %lf %lf\n",ex,ey,ez);

	if (((ex-0)*(ex-0)<ZERO) && ((ey-0)*(ey-0)<ZERO) && ((ez-1)*(ez-1)<ZERO))
		rotateflag = 0;

	if (rotateflag == 1)
	{
		e = sqrt(ex * ex + ey * ey + ez * ez);
		if (e == 0) return -1;

		xbase = 0; ybase = 0; zbase = 1;
		xaxis = ybase * ez - zbase * ey;
		yaxis = zbase * ex - xbase * ez;
		zaxis = xbase * ey - ybase * ex;
		//angleaxis = acos((xbase*ex+ybase*ey+zbase*ez)/e) + pi;
		angleaxis = acos((xbase*ex+ybase*ey+zbase*ez)/e);

		//printf("%lf %lf %lf %lf\n",angleaxis,xaxis,yaxis,zaxis);

	}
	if (((ex-0)*(ex-0)<ZERO) && ((ey-0)*(ey-0)<ZERO) && ((ez+1)*(ez+1)<ZERO))
	{
		xaxis = 1; yaxis = 0; zaxis = 0;
		angleaxis = pi;
	}

	glTranslatef(lx,ly,lz);

	if (rotateflag == 1)
		glRotatef(angleaxis*180/pi,xaxis,yaxis,zaxis);

	gluCylinder(quadratic,base,top,height,32,32);//»­Ô²Öù	base top height
	if (rotateflag == 1)
		glRotatef(-angleaxis*180/pi,xaxis,yaxis,zaxis);

	glTranslatef(-lx,-ly,-lz);
	return 0;
}
