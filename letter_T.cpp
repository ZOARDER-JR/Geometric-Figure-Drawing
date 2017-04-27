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

double X1,X2,Y1,Y2,Z1,Z2;

void drawLine();
int round(double x);
void init();

int main(int argc, char **argv)
{
	cout << "Enter end points of linr parallel to X axis" <<endl;
	cin >> X1 >> Y1 >> X2 >> Y2;
	cout << "Enter the 2nd co ordinate of line parallel to Y axix" <<endl;
	cin >> Z1 >> Z2;

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
	double y;
	glClear(GL_COLOR_BUFFER_BIT);	
    glBegin(GL_POINTS);

	if( (X2-X1) > 0 )
	{
		for(i=X1;i<=X2;i++)
		{
			glVertex2d(i,Y1);
		}
	}
	else
	{
		for(i=X1;i>=X2;i--)
		{
			glVertex2d(i,Y1);
		}
	}

	y=(Y1+Y2)/2;

	if( (Z2-y) > 0 )
	{
		for(i=y;i<=Z2;i++)
		{
			glVertex2d(Z1,i);
		}
	}
	else
	{
		for(i=y;i>=Z2;i--)
		{
			glVertex2d(Z1,i);
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