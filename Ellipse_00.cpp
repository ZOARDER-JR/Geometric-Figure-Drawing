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
double a,b,y,x;

void drawEllipse();
void ellipsePoints(double x, double y);

void init();

int main(int argc, char **argv)
{
	cout << "Enter the length value of a and b" <<endl;
	cin >> a >> b;
	
	glutInit(&argc,argv);			
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		 
	glutInitWindowPosition(-700,-400);		 
	glutInitWindowSize(1400,800);			
	glutCreateWindow("DDA_Ellipse");			 
	init();
	glutDisplayFunc(drawEllipse);			 
	glutMainLoop();		
	return 0;
}

void drawEllipse()
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

	x=0; y=b;
	double d1,d2;

	d1=(b*b)-(a*a*b)+(.25*a*a);

	ellipsePoints(x,y);

	while((a*a*(y-.5)) > (b*b*(x+1)))
	{
		if(d1 < 0)
		{
			d1+=b*b*(2*x + 3);
		}
		else
		{
			d1+=(b*b*(2*x+3))-(a*a*(2*y-2));
			y--;
		}
		x++;

		ellipsePoints(x,y);
	}

	d2=(b*b*(x+.5)*(x+.5))+(a*a*(y-1)*(y-1))-(a*a*b*b);
	while(y > 0)
	{
		if(d2 < 0)
		{
			d2+=(b*b*(2*x+2))-(a*a*(2*y-3));
			x++;
		}
		else
		{
			d2+=a*a*(3-2*y);
		}
		y--;

		ellipsePoints(x,y);
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

void ellipsePoints(double x, double y)
{
	glVertex2d(x,y);
	glVertex2d(x,-y);
	glVertex2d(-x,y);
	glVertex2d(-x,-y);
}

/* Sample input 
(0 100)(100 100)
(80 100)(80 0)
(80 100)(10 50)
(10 50)(80 0)*/