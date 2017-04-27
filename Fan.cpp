#include<windows.h>
#include <GL/glut.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<iomanip>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
#include<deque>

using namespace std;

struct line
{
	double X1;
	double Y1;
	double X2;
	double Y2;
};
struct circle
{
	double r;
	double X0;
	double Y0;
};

line A1,A2,A3,A4,B1,B2,B3,B4,C1,C2,C3,C4;
circle head;

void drawMan();
void drawLine(double X1, double Y1, double X2, double Y2);
void drawCircle(double r, double sx, double sy);
void circlePoints(double x, double y,double xy, double sx);
int round(double x);
void init();
void init_man();

int main(int argc, char **argv)
{
	init_man();
	glutInit(&argc,argv);			
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		 
	glutInitWindowPosition(-700,-400);		 
	glutInitWindowSize(1400,800);			
	glutCreateWindow("DDA_Line");			 
	init();
	glutDisplayFunc(drawMan);			 
	glutMainLoop();		
	return 0;
}

void drawMan()
{
	long long TT=0;

	while(1)
	{
		glClear(GL_COLOR_BUFFER_BIT);	
		glBegin(GL_POINTS);

		drawCircle(head.r,head.X0,head.Y0);

		drawLine(A1.X1*cos((TT%90)*3.1416/180)-A1.Y1*sin((TT%90)*3.1416/180),A1.Y1*cos((TT%90)*3.1416/180)+A1.X1*sin((TT%90)*3.1416/180),A1.X2*cos((TT%90)*3.1416/180)-A1.Y2*sin((TT%90)*3.1416/180),A1.Y2*cos((TT%90)*3.1416/180)+A1.X2*sin((TT%90)*3.1416/180));
		drawLine(A2.X1*cos((TT%90)*3.1416/180)-A2.Y1*sin((TT%90)*3.1416/180),A2.Y1*cos((TT%90)*3.1416/180)+A2.X1*sin((TT%90)*3.1416/180),A2.X2*cos((TT%90)*3.1416/180)-A2.Y2*sin((TT%90)*3.1416/180),A2.Y2*cos((TT%90)*3.1416/180)+A2.X2*sin((TT%90)*3.1416/180));
		drawLine(A3.X1*cos((TT%90)*3.1416/180)-A3.Y1*sin((TT%90)*3.1416/180),A3.Y1*cos((TT%90)*3.1416/180)+A3.X1*sin((TT%90)*3.1416/180),A3.X2*cos((TT%90)*3.1416/180)-A3.Y2*sin((TT%90)*3.1416/180),A3.Y2*cos((TT%90)*3.1416/180)+A3.X2*sin((TT%90)*3.1416/180));
		drawLine(A4.X1*cos((TT%90)*3.1416/180)-A4.Y1*sin((TT%90)*3.1416/180),A4.Y1*cos((TT%90)*3.1416/180)+A4.X1*sin((TT%90)*3.1416/180),A4.X2*cos((TT%90)*3.1416/180)-A4.Y2*sin((TT%90)*3.1416/180),A4.Y2*cos((TT%90)*3.1416/180)+A4.X2*sin((TT%90)*3.1416/180));

		drawLine(B1.X1*cos((TT%90)*3.1416/180)-B1.Y1*sin((TT%90)*3.1416/180),B1.Y1*cos((TT%90)*3.1416/180)+B1.X1*sin((TT%90)*3.1416/180),B1.X2*cos((TT%90)*3.1416/180)-B1.Y2*sin((TT%90)*3.1416/180),B1.Y2*cos((TT%90)*3.1416/180)+B1.X2*sin((TT%90)*3.1416/180));
		drawLine(B2.X1*cos((TT%90)*3.1416/180)-B2.Y1*sin((TT%90)*3.1416/180),B2.Y1*cos((TT%90)*3.1416/180)+B2.X1*sin((TT%90)*3.1416/180),B2.X2*cos((TT%90)*3.1416/180)-B2.Y2*sin((TT%90)*3.1416/180),B2.Y2*cos((TT%90)*3.1416/180)+B2.X2*sin((TT%90)*3.1416/180));
		drawLine(B3.X1*cos((TT%90)*3.1416/180)-B3.Y1*sin((TT%90)*3.1416/180),B3.Y1*cos((TT%90)*3.1416/180)+B3.X1*sin((TT%90)*3.1416/180),B3.X2*cos((TT%90)*3.1416/180)-B3.Y2*sin((TT%90)*3.1416/180),B3.Y2*cos((TT%90)*3.1416/180)+B3.X2*sin((TT%90)*3.1416/180));
		drawLine(B4.X1*cos((TT%90)*3.1416/180)-B4.Y1*sin((TT%90)*3.1416/180),B4.Y1*cos((TT%90)*3.1416/180)+B4.X1*sin((TT%90)*3.1416/180),B4.X2*cos((TT%90)*3.1416/180)-B4.Y2*sin((TT%90)*3.1416/180),B4.Y2*cos((TT%90)*3.1416/180)+B4.X2*sin((TT%90)*3.1416/180));

		drawLine(C1.X1*cos((TT%90)*3.1416/180)-C1.Y1*sin((TT%90)*3.1416/180),C1.Y1*cos((TT%90)*3.1416/180)+C1.X1*sin((TT%90)*3.1416/180),C1.X2*cos((TT%90)*3.1416/180)-C1.Y2*sin((TT%90)*3.1416/180),C1.Y2*cos((TT%90)*3.1416/180)+C1.X2*sin((TT%90)*3.1416/180));
		drawLine(C2.X1*cos((TT%90)*3.1416/180)-C2.Y1*sin((TT%90)*3.1416/180),C2.Y1*cos((TT%90)*3.1416/180)+C2.X1*sin((TT%90)*3.1416/180),C2.X2*cos((TT%90)*3.1416/180)-C2.Y2*sin((TT%90)*3.1416/180),C2.Y2*cos((TT%90)*3.1416/180)+C2.X2*sin((TT%90)*3.1416/180));
		drawLine(C3.X1*cos((TT%90)*3.1416/180)-C3.Y1*sin((TT%90)*3.1416/180),C3.Y1*cos((TT%90)*3.1416/180)+C3.X1*sin((TT%90)*3.1416/180),C3.X2*cos((TT%90)*3.1416/180)-C3.Y2*sin((TT%90)*3.1416/180),C3.Y2*cos((TT%90)*3.1416/180)+C3.X2*sin((TT%90)*3.1416/180));
		drawLine(C4.X1*cos((TT%90)*3.1416/180)-C4.Y1*sin((TT%90)*3.1416/180),C4.Y1*cos((TT%90)*3.1416/180)+C4.X1*sin((TT%90)*3.1416/180),C4.X2*cos((TT%90)*3.1416/180)-C4.Y2*sin((TT%90)*3.1416/180),C4.Y2*cos((TT%90)*3.1416/180)+C4.X2*sin((TT%90)*3.1416/180));

		Sleep(5);

		glEnd();
		glFlush();

		TT+=10.0;
	}
}

void drawLine(double X1, double Y1, double X2, double Y2)
{
	int i;
	double m,y,x;
	
	if( (X2-X1) == 0)
	{
		if((Y2-Y1) > 0)
		{
			for(i=Y1;i<=Y2;i++)
			{
				glVertex2d(X1,i);
			}
		}
		else
		{
			for(i=Y1;i>=Y2;i--)
			{
				glVertex2d(X1,i);
			}
		}
	}
	else
	{
		m=(Y2-Y1)/(X2-X1);

		if(m <=1 && m >= -1)
		{
			if( (X2-X1) > 0 )
			{
				y=Y1;

				for(i=X1;i<=X2;i++)
				{
					glVertex2d(i,round(y));
					y+=m;
				}
			}
			else
			{
				y=Y1;

				for(i=X1;i>=X2;i--)
				{
					glVertex2d(i,round(y));
					y-=m;
				}
			}
		}
		else
		{
			if( (Y2-Y1) > 0 )
			{
				x=X1;

				for(i=Y1;i<=Y2;i++)
				{
					glVertex2d(round(x),i);
					x+=(1/m);
				}
			}
			else
			{
				x=X1;

				for(i=Y1;i>=Y2;i--)
				{
					glVertex2d(round(x),i);
					x-=(1/m);
				}
			}
		}
	}	
}

void circlePoints(double x, double y,double sx, double sy)
{
	glVertex2d(x+sx,y+sy);
	glVertex2d(x+sx,-y+sy);
	glVertex2d(-x+sx,y+sy);
	glVertex2d(-x+sx,-y+sy);
	glVertex2d(y+sx,x+sy);
	glVertex2d(y+sx,-x+sy);
	glVertex2d(-y+sx,x+sy);
	glVertex2d(-y+sx,-x+sy);
}

void drawCircle(double r, double sx, double sy)
{
	double x,y;
	x=0; y=r;
	double d=1-r;

	circlePoints(x,y,sx,sy);

	while(y > x)
	{
		if(d < 0)
		{
			d+=(2*x + 3);
		}
		else
		{
			d+=(2*(x-y) + 5);
			y--;
		}
		x++;

		circlePoints(x,y,sx,sy);
	}	
}

int round(double x)
{
	return (floor(x+.5)) ;
}
void init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(-700 , 700 , -400 , 400);
}

void init_man()
{
	head.r = 50; head.X0 = 0; head.Y0 = 0;

	A1.X1 = -10;	A1.X2 = -10;	A1.Y1 = 45;		A1.Y2 = 170;
	A2.X1 = 10;		A2.X2 = 10;		A2.Y1 = 45;		A2.Y2 = 170;
	A3.X1 = -10;	A3.X2 = 10;		A3.Y1 = 45;		A3.Y2 = 45;
	A4.X1 = -10;	A4.X2 = 10;		A4.Y1 = 170;	A4.Y2 = 170;

	B1.X1 = -50;	B1.X2 = -150;	B1.Y1 = 0;		B1.Y2 = -100;
	B2.X1 = -40;	B2.X2 = -140;	B2.Y1 = -20;	B2.Y2 = -120;
	B3.X1 = -150;	B3.X2 = -140;	B3.Y1 = -100;	B3.Y2 = -120;
	B4.X1 = -50;	B4.X2 = -40;	B4.Y1 = 0;		B4.Y2 = -20;

	C1.X1 = 50;		C1.X2 = 150;	C1.Y1 = 0;		C1.Y2 = -100;
	C2.X1 = 40;		C2.X2 = 140;	C2.Y1 = -20;	C2.Y2 = -120;
	C3.X1 = 150;	C3.X2 = 140;	C3.Y1 = -100;	C3.Y2 = -120;
	C4.X1 = 50;		C4.X2 = 40;		C4.Y1 = 0;		C4.Y2 = -20;
}