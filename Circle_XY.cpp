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
double m,y,x,r,o1,o2;

void drawCircle();
void circlePoints(double x, double y);

int round(double x);
void init();

int main(int argc, char **argv)
{
	cout << "Enter the radius of the circle" <<endl;
	cin >> r;
	cout << "Enter the origine of the circle" <<endl;
	cin >> o1 >> o2;
	
	glutInit(&argc,argv);			
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		 
	glutInitWindowPosition(-700,-400);		 
	glutInitWindowSize(1400,800);			
	glutCreateWindow("DDA_Circle");			 
	init();
	glutDisplayFunc(drawCircle);			 
	glutMainLoop();		
	return 0;
}

void drawCircle()
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

	x=0; y=r;
	double d=1-r;

	circlePoints(x,y);

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

		circlePoints(x,y);
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

void circlePoints(double x, double y)
{
	glVertex2d(x+o1,y+o2);
	glVertex2d(x+o1,-y+o2);
	glVertex2d(-x+o1,y+o2);
	glVertex2d(-x+o1,-y+o2);
	glVertex2d(y+o1,x+o2);
	glVertex2d(y+o1,-x+o2);
	glVertex2d(-y+o1,x+o2);
	glVertex2d(-y+o1,-x+o2);
}
