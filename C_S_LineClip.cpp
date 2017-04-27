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

#define TOP 8
#define BTM 4
#define RYT 2
#define LFT 1

using namespace std;

double X11,X22,Y11,Y22,x_mx,x_mn,y_mx,y_mn;

void clip();
void drawLine(double X1, double Y1, double X2, double Y2);
int comp_outcode(double x, double y);
int round(double x);
void init();

int main(int argc, char **argv)
{
	cout << "Enter endpoints of the line: (x1,y1) (x2,y2)" <<endl;
	cin >> X11 >> Y11 >> X22 >> Y22;
	cout << "Enter endpoints of the clip rectangle: (x_min,y_min) (x_max,y_max)" <<endl;
	cin >> x_mn >>  y_mn >> x_mx >> y_mx;

	glutInit(&argc,argv);			
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		 
	glutInitWindowPosition(-700,-400);		 
	glutInitWindowSize(1400,800);			
	glutCreateWindow("DDA_clip");			 
	init();
	glutDisplayFunc(clip);			 
	glutMainLoop();		
	return 0;
}

void clip()
{
	int outcode0,outcode1,outcode_out;
	bool accept,done;

	accept=done=false;

	outcode0=comp_outcode(X11,Y11);
	outcode1=comp_outcode(X22,Y22);

	do
	{
		if(!(outcode0|outcode1))
		{
			done=true;
			accept=true;
		}
		else if((outcode0 & outcode1))
		{
			done=true;
		}
		else
		{
			double x,y;

			outcode_out=(outcode0?outcode0:outcode1);

			if((outcode_out & TOP))
			{
				y=y_mx;
				x=((X11*(y-Y22)-X22*(y-Y11))/(Y11-Y22));
			}
			else if((outcode_out & BTM))
			{
				y=y_mn;
				x=((X11*(y-Y22)-X22*(y-Y11))/(Y11-Y22));
			}
			else if((outcode_out & RYT))
			{
				x=x_mx;
				y=((Y11*(x-X22)-Y22*(x-X11))/(X11-X22));
			}
			else
			{
				x=x_mn;
				y=((Y11*(x-X22)-Y22*(x-X11))/(X11-X22));
			}

			if(outcode_out == outcode0)
			{
				X11=x; Y11=y;
				outcode0=comp_outcode(X11,Y11);
			}
			else
			{
				X22=x; Y22=y;
				outcode1=comp_outcode(X22,Y22);
			}


		}
	}while(!done);

	if(accept)
	{
		drawLine(X11,Y11,X22,Y22);
	}
}

void drawLine(double X1, double Y1, double X2, double Y2)
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
	glEnd();

    glFlush();	
}
int comp_outcode(double x, double y)
{
	int code=0;

	if(x > x_mx)
	{
		code|=RYT;
	}
	else if(x < x_mn)
	{
		code|=LFT;
	}
	if(y > y_mx)
	{
		code|=TOP;
	}
	else if(y < y_mn)
	{
		code|=BTM;
	}

	return code;
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