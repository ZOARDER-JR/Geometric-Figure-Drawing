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
void init();

int main(int argc, char **argv)
{
	cout << "Enter the lower end point" <<endl;
	cin >> X1 >> Y1;
	cout << "Enter the upper end point" <<endl;
	cin >> X2 >> Y2;

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
	int i,j;
	glClear(GL_COLOR_BUFFER_BIT);	
    glBegin(GL_POINTS);

	for(i=X1;i<=X2;i++)
	{
		for(j=Y1;j<=Y2;j++)
		{
			glVertex2d(i,j);
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
	glClearColor(0.0,0.0,0.0,0);
	glColor3f(1.0,1.0,1.0);
	gluOrtho2D(-700 , 700 , -400 , 400);
}