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

int i;
double x0,x1,Y0,Y1,y,x;

void drawLine();
void init();

int main(int argc, char **argv)
{
	cout << "Enter the first endpoint (x0,y0)" <<endl;
	cin >> x0 >> Y0;
	cout << "Enter the second endpoint (x1,y1)" <<endl;
	cin >> x1 >> Y1;
	
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

	double dx,dy,incE,incNE,d;

	if((x1-x0) == 0)
	{
		for(i=Y0;i<=Y1;i++)
		{
			glVertex2d(x0,i);
		}
	}
	else if((Y1-Y0) == 0)
	{
		for(i=x0;i<=x1;i++)
		{
			glVertex2d(i,Y0);
		}
	}
	else
	{
		dx=x1-x0;
		dy=Y1-Y0;
		incE=2*dy;
		incNE=2*(dy-dx);
		d=2*dy - dx;
		x=x0; y=Y0;

		glVertex2d(x,y);

		while(x < x1)
		{
			if(d <= 0)
			{
				d+=incE;
				x++;
			}
			else
			{
				d+=incNE;
				x++;
				y++;
			}
			glVertex2d(x,y);
		}
	}

	glEnd();

    glFlush();	
}

void init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(-700 , 700 , -400 , 400);
}
