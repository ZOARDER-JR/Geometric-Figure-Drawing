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

int i,j;
double x0,x1,Y0,Y1;

void Fill_H();
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
	glutCreateWindow("DDA_Filling");			 
	init();
	glutDisplayFunc(Fill_H);			 
	glutMainLoop();		
	return 0;
}

void Fill_H()
{
	glClear(GL_COLOR_BUFFER_BIT);	
    glBegin(GL_POINTS);

	for(i=Y0;i<=Y1;i++)
	{
		for(j=x0;j<=x1;j++)
		{
			glVertex2d(j,i);
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
