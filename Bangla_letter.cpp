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

double X1_parallel_x,X2_parallel_x,Y1_parallel_x,Y2_parallel_x;
double X1_parallel_y,X2_parallel_y,Y1_parallel_y,Y2_parallel_y;
double X1_M_1,X2_M_1,Y1_M_1,Y2_M_1;
double X1_M_0,X2_M_0,Y1_M_0,Y2_M_0;
int i;
double m,y,x;

void drawLine();
void drawThick(double X1, double Y1, double X2, double Y2);
void drawThin(double X1, double Y1, double X2, double Y2);

int round(double x);
void init();

int main(int argc, char **argv)
{
	cout << "Enter End points (Line Parallel to X axis)" <<endl;
	cin >> X1_parallel_x >> Y1_parallel_x >> X2_parallel_x >> Y2_parallel_x;
	cout << "Enter End points (Line Parallel to Y axis)" <<endl;
	cin >> X1_parallel_y >> Y1_parallel_y >> X2_parallel_y >> Y2_parallel_y;
	cout << "Enter End points (Line inclined to +X axis)" <<endl;
	cin >> X1_M_1 >> Y1_M_1 >> X2_M_1 >> Y2_M_1;
	cout << "Enter End points (Line inclined to -X axis)" <<endl;
	cin >> X1_M_0 >> Y1_M_0 >> X2_M_0 >> Y2_M_0;

	glutInit(&argc,argv);			
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		 
	glutInitWindowPosition(-700,-400);		 
	glutInitWindowSize(1400,800);			
	glutCreateWindow("DDA_Line");			 
	init();
	glutDisplayFunc(drawLine);			 
	glutMainLoop();		
	return 0;
}

void drawLine()
{
	glClear(GL_COLOR_BUFFER_BIT);	
    glBegin(GL_POINTS);

	for(i=-680;i<=680;i++)
	{
		glVertex2d(i,0);
	}
	for(i=-380;i<=380;i++)
	{
		glVertex2d(0,i);
	}

	drawThick(X1_parallel_x,Y1_parallel_x,X2_parallel_x,Y2_parallel_x);
	drawThick(X1_parallel_y,Y1_parallel_y,X2_parallel_y,Y2_parallel_y);
	drawThick(X1_M_1,Y1_M_1,X2_M_1,Y2_M_1);
	drawThick(X1_M_0,Y1_M_0,X2_M_0,Y2_M_0);

	drawThin(X1_parallel_x,Y1_parallel_x+4,X2_parallel_x,Y2_parallel_x+4);
	drawThin(X1_parallel_y+4,Y1_parallel_y+4,X2_parallel_y+4,Y2_parallel_y);
	drawThin(X1_M_1,Y1_M_1+4,X2_M_1,Y2_M_1+4);
	drawThin(X1_M_0,Y1_M_0+4,X2_M_0+4,Y2_M_0);

	glEnd();

    glFlush();	
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
void drawThick(double X1, double Y1, double X2, double Y2)
{
	if( (X2-X1) == 0)
	{
		if((Y2-Y1) > 0)
		{
			for(i=Y1;i<=Y2;i++)
			{
				glVertex2d(X1,i);
				glVertex2d(X1+1,i);
			}
		}
		else
		{
			for(i=Y1;i>=Y2;i--)
			{
				glVertex2d(X1,i);
				glVertex2d(X1+1,i);
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
					glVertex2d(i,round(y+1));
					y+=m;
				}
			}
			else
			{
				y=Y1;

				for(i=X1;i>=X2;i--)
				{
					glVertex2d(i,round(y));
					glVertex2d(i,round(y+1));
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
					glVertex2d(round(x),i+1);
					x+=(1/m);
				}
			}
			else
			{
				x=X1;

				for(i=Y1;i>=Y2;i--)
				{
					glVertex2d(round(x),i);
					glVertex2d(round(x),i+1);
					x-=(1/m);
				}
			}
		}
	}
}
void drawThin(double X1, double Y1, double X2, double Y2)
{
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

/* Sample input 
(0 100)(100 100)
(80 100)(80 0)
(80 100)(10 50)
(10 50)(80 0)*/