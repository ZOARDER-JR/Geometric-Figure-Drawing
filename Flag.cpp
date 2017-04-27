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
double x0,x1,Y0,Y1,r,x,y;
map<int,vector<int>> Y;
vector<int> X;
map<int,vector<int>>::iterator it;

void init();
void drawFlag();
void circlePoints(double x, double y);

int main(int argc, char **argv)
{
	cout << "Enter the first endpoint of the rectangle (x0,y0)" <<endl;
	cin >> x0 >> Y0;
	cout << "Enter the second endpoint rectangle (x1,y1)" <<endl;
	cin >> x1 >> Y1;
	cout << "Enter the radius of the circle (r)" <<endl;
	cin >> r;
	
	glutInit(&argc,argv);			
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		 
	glutInitWindowPosition(-700,-400);		 
	glutInitWindowSize(1400,800);			
	glutCreateWindow("DDA_Flag");			 
	init();
	glutDisplayFunc(drawFlag);			 
	glutMainLoop();		
	return 0;
}

void init()
{
	glClearColor(1.0,1.0,1.0,0);
	gluOrtho2D(-700 , 700 , -400 , 400);
}
void drawFlag()
{
	glClear(GL_COLOR_BUFFER_BIT);	
    glBegin(GL_POINTS);
	glColor3f(1.0,0.0,0.0);

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
	glColor3f(0.0,1.0,0.0);

	for(i=Y0;i<=Y1;i++)
	{
		it=Y.find(i);
		if(it!=Y.end())
		{
			int s;
			sort(it->second.begin(),it->second.end());
			s=it->second.size();
			
			for(j=x0;j<it->second[0];j++)
			{
				glVertex2d(j,i);
			}

			glColor3f(1.0,0.0,0.0);

			for(j=it->second[0]+1;j<it->second[s-1];j++)
			{
				glVertex2d(j,i);
			}

			glColor3f(0.0,1.0,0.0);
			for(j=it->second[s-1]+1;j<=x1;j++)
			{
				glVertex2d(j,i);
			}
		}
		else
		{
			for(j=x0;j<x1;j++)
			{
				glVertex2d(j,i);
			}
		}
	}


	glEnd();

    glFlush();	
}
void circlePoints(double x, double y)
{
	glVertex2d(x,y);
	it=Y.find(y);
	if(it!=Y.end())
	{
		Y[y].push_back(x);
	}
	else
	{
		Y.insert(pair<int,vector<int>>(y,X));
		Y[y].push_back(x);
	}

	glVertex2d(x,-y);
	it=Y.find(-y);
	if(it!=Y.end())
	{
		Y[-y].push_back(x);
	}
	else
	{
		Y.insert(pair<int,vector<int>>(-y,X));
		Y[-y].push_back(x);
	}

	glVertex2d(-x,y);
	it=Y.find(y);
	if(it!=Y.end())
	{
		Y[y].push_back(-x);
	}
	else
	{
		Y.insert(pair<int,vector<int>>(y,X));
		Y[y].push_back(-x);
	}

	glVertex2d(-x,-y);
	it=Y.find(-y);
	if(it!=Y.end())
	{
		Y[-y].push_back(-x);
	}
	else
	{
		Y.insert(pair<int,vector<int>>(-y,X));
		Y[-y].push_back(-x);
	}

	glVertex2d(y,x);
	it=Y.find(x);
	if(it!=Y.end())
	{
		Y[x].push_back(y);
	}
	else
	{
		Y.insert(pair<int,vector<int>>(x,X));
		Y[x].push_back(y);
	}

	glVertex2d(y,-x);
	it=Y.find(-x);
	if(it!=Y.end())
	{
		Y[-x].push_back(y);
	}
	else
	{
		Y.insert(pair<int,vector<int>>(-x,X));
		Y[-x].push_back(y);
	}

	glVertex2d(-y,x);
	it=Y.find(x);
	if(it!=Y.end())
	{
		Y[x].push_back(-y);
	}
	else
	{
		Y.insert(pair<int,vector<int>>(x,X));
		Y[x].push_back(-y);
	}

	glVertex2d(-y,-x);
	it=Y.find(-x);
	if(it!=Y.end())
	{
		Y[-x].push_back(-y);
	}
	else
	{
		Y.insert(pair<int,vector<int>>(-x,X));
		Y[-x].push_back(-y);
	}
}
/* Sample Input
	-450 -300 (x0,y0)
	550 300 (x1,y1)
	200 (r)  */



