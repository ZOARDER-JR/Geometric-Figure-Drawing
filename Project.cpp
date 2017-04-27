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

struct line
{
	double X1;
	double Y1;
	double X2;
	double Y2;
};
struct circle
{
	double r;
	double X0;
	double Y0;
};

line A1,A2,A3,A4,B1,B2,B3,B4,C1,C2,C3,C4;
circle head;

void drawPicture();
void drawLine(double X1, double Y1, double X2, double Y2);
void drawCircle(double r, double sx, double sy);
void circlePoints(double x, double y,double xy, double sx);
int round(double x);
void init();

int main(int argc, char **argv)
{
	glutInit(&argc,argv);			
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		 
	glutInitWindowPosition(-700,-400);		 
	glutInitWindowSize(1400,800);			
	glutCreateWindow("DDA_Line");			 
	init();
	glutDisplayFunc(drawPicture);			 
	glutMainLoop();		
	return 0;
}

void drawPicture()
{
	int I,J;
	double S;
	I=J=0;
	S=1;
	while(I < 470 && J < 210)
	{
		glClear(GL_COLOR_BUFFER_BIT);	
		glBegin(GL_POINTS);

		drawLine(-700,100,700,100);

		for(int i=0 ;i < 1400; i+=60)				//
		{
			drawLine(-660+i,160,-660+i,100);			//drawing tree ( transilation applied)
			drawLine(-680+i,140,-640+i,180);
			drawLine(-640+i,140,-680+i,180);		//
		}

		drawLine(-620,-80,-540,0);		//
		drawLine(-460,-80,-540,0);
		drawLine(-460,-80,-280,-80);
		drawLine(-360,0,-540,0);				
		drawLine(-360,0,-280,-80);				//Drawing house 1
		drawLine(-600,-60,-600,-200);
		drawLine(-300,-200,-600,-200);
		drawLine(-300,-200,-300,-80);
		drawLine(-480,-200,-480,-60);		//

		drawLine(-620*0.5+225,-80*0.5+50,-540*0.5+225,0*0.5+50);		//
		drawLine(-460*0.5+225,-80*0.5+50,-540*0.5+225,0*0.5+50);
		drawLine(-460*0.5+225,-80*0.5+50,-280*0.5+225,-80*0.5+50);
		drawLine(-360*0.5+225,0*0.5+50,-540*0.5+225,0*0.5+50);
		drawLine(-360*0.5+225,0*0.5+50,-280*0.5+225,-80*0.5+50);			// Drawing house 2 (Transilation and scaling applied)
		drawLine(-600*0.5+225,-60*0.5+50,-600*0.5+225,-200*0.5+50);
		drawLine(-300*0.5+225,-200*0.5+50,-600*0.5+225,-200*0.5+50);
		drawLine(-300*0.5+225,-200*0.5+50,-300*0.5+225,-80*0.5+50);
		drawLine(-480*0.5+225,-200*0.5+50,-480*0.5+225,-60*0.5+50);		//

		drawCircle(60,500,300);			// drawing sun (mid point circle drawing algorithm)

		drawLine(300,100,200,0);		//	
		drawLine(200,0,300,0);
		drawLine(300,0,100,-200);
		drawLine(100,-200,200,-200);
		drawLine(200,-200,0,-400);				// drawing river bank (DDA applied)
		drawLine(340,100,240,0);
		drawLine(300,0,300,-40);
		drawLine(300,-40,140,-200);
		drawLine(200,-200,200,-240);
		drawLine(200,-240,40,-400);		//

		drawLine(-500+I*2,320,-460+I*2,340);	//
		drawLine(-500+I*2,320,-520+I*2,340);
		drawLine(-620+I*2,340,-640+I*2,360);		// drawing birds (DDA applied, transfprmation along X axis applied)
		drawLine(-620+I*2,340,-580+I*2,360);
		drawLine(-540+I*2,360,-560+I*2,380);
		drawLine(-540+I*2,360,-500+I*2,380);	//

		drawCircle(30*S,-400*S+I,-160*S+J);					//
		drawLine(-400*S+I,-190*S+J,-400*S+I,-300*S+J);
		drawLine(-400*S+I,-220*S+J,-360*S+I,-260*S+J);
		drawLine(-400*S+I,-220*S+J,-440*S+I,-260*S+J);			// Drawing man (scaling and transformation applied)
		drawLine(-400*S+I,-300*S+J,-360*S+I,-360*S+J);
		drawLine(-400*S+I,-300*S+J,-440*S+I,-360*S+J);		//

		glEnd();
		glFlush();

		I+=8;
		J+=3;
		S-=.008;
		Sleep(500);
	}
}

void drawLine(double X1, double Y1, double X2, double Y2)
{
	int i;
	double m,y,x;
	
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

void drawCircle(double r, double sx, double sy)
{
	double x,y;
	x=0; y=r;
	double d=1-r;

	circlePoints(x,y,sx,sy);

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

		circlePoints(x,y,sx,sy);
	}	
}

void circlePoints(double x, double y,double sx, double sy)
{
	glVertex2d(x+sx,y+sy);
	glVertex2d(x+sx,-y+sy);
	glVertex2d(-x+sx,y+sy);
	glVertex2d(-x+sx,-y+sy);
	glVertex2d(y+sx,x+sy);
	glVertex2d(y+sx,-x+sy);
	glVertex2d(-y+sx,x+sy);
	glVertex2d(-y+sx,-x+sy);
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