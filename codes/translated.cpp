#include<iostream>
#include<vector>
#include<GL/glut.h>
#include<string>
#include<cstdlib>
#include<cmath>
#include<deque>
#include "standard_lib.hpp" 


void figure(double scale = 2 , Point center = new Point(1,1,1,0,0)){
Point  *p=new Point(3,4,2,new Point(1,1,1,0,0).x,new Point(1,1,1,0,0).y);Point  *q=new Point(4,5,2,new Point(1,1,1,0,0).x,new Point(1,1,1,0,0).y);Point  *r=new Point(6.5,3.4,2,new Point(1,1,1,0,0).x,new Point(1,1,1,0,0).y);Point  *s=new Point(1,4,2,new Point(1,1,1,0,0).x,new Point(1,1,1,0,0).y);Line l[4]={ Line(p, r, LINE), Line(r, q, SEGMENT), Line(q, s, RAY)  };
{
int arr[][4]={{1,2,3,4},{5,6,7,8}};
{
double arr=angleBetweenPoints(new Point(1,2,2,new Point(1,1,1,0,0).x,new Point(1,1,1,0,0).y),new Point(2,2,2,new Point(1,1,1,0,0).x,new Point(1,1,1,0,0).y),new Point(0,0,2,new Point(1,1,1,0,0).x,new Point(1,1,1,0,0).y));}

int x=arr[0][6];}

}

int main(int argc,char** argv){




glutInit(&argc, argv);
glutInitWindowSize(640, 480);
glutInitWindowPosition(50, 50);
glutCreateWindow("Figure");
glutDisplayFunc(display);
 glutReshapeFunc(reshape);init();
glutMainLoop();

 return 0;
}
