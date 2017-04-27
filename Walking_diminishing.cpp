#include<windows.h>
#include <GL/glut.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<ctime>
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

#define X_MAX 700
#define X_MIN -700
#define Y_MAX 400
#define Y_MIN -400

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
using namespace std;

line H1,H2,L1,L2,B;
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
	glutInitWindowPosition(X_MIN,Y_MIN);		 
	glutInitWindowSize(1400,800);			
	glutCreateWindow("DDA_Line");			 
	init();
	glutDisplayFunc(drawMan);			 
	glutMainLoop();		
	return 0;
}

void drawMan()
{
	double q;
	int i;

	for(i=0,q=1.0;i < 1300 ; i+=5,q=q-0.0018)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POINTS);

		for(int K=X_MIN;K<=X_MAX;K++)
		{
			glVertex2d(K,-150);
		}

		drawCircle(head.r*q,head.X0+i,head.Y0*q+150*q-150);
		drawLine(B.X1+i,B.Y1*q+150*q-150,B.X2+i,B.Y2*q+150*q-150);
		drawLine(H1.X1+i,H1.Y1*q+150*q-150,H1.X2+i,H1.Y2*q+150*q-150);
		drawLine(H2.X1+i,H2.Y1*q+150*q-150,H2.X2+i,H2.Y2*q+150*q-150);
		drawLine(L1.X1+i,L1.Y1*q+150*q-150,L1.X2+i,L1.Y2*q+150*q-150);
		drawLine(L2.X1+i,L2.Y1*q+150*q-150,L2.X2+i,L2.Y2*q+150*q-150);

		Sleep(100);

		glEnd();
		glFlush();
	}

	glEnd();
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
					y+=m;
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
					x+=(1/m);
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
	head.r = 25; head.X0 = X_MIN+50+0; head.Y0 = 125;
	B.X1 = X_MIN+50+0; B.X2 = X_MIN+50+0; B.Y1 = 100; B.Y2 = -50;
	H1.X1 = X_MIN+50-50; H1.X2 = X_MIN+50+0; H1.Y1 = 0; H1.Y2 = 50;
	H2.X1 = X_MIN+50+0; H2.X2 = X_MIN+50+50; H2.Y1 = 50; H2.Y2 = 0;
	L1.X1 = X_MIN+50-50; L1.X2 = X_MIN+50+0; L1.Y1 = -150; L1.Y2 = -50;
	L2.X1 = X_MIN+50+50; L2.X2 = X_MIN+50+0; L2.Y1 = -150; L2.Y2 = -50;
}