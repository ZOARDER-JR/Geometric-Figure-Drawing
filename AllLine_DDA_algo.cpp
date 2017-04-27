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

double X1,X2,Y1,Y2;

void drawLine();
int round(double x);
void init();

int main(int argc, char **argv)
{
	cout << "Enter two point: (x1,y1) (x2,y2)" <<endl;
	cin >> X1 >> Y1 >> X2 >> Y2;

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
	int i;
	double m,y,x;
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