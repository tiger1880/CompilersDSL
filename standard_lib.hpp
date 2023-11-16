#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <math.h>
#include<GL/glut.h>

using namespace std;

class Shapes{

public:
string label;
virtual void  Area()=0;
virtual void Perimeter()=0;

};

class Point:public Shapes{
    public:
    double x;
    double y;

    Point() {

    }

    Point(double a,double b) {
        x = a;
        y = b;
    }

    void Area() override {
        // Implementation for Point Area
    }

    void Perimeter() override {
        // Implementation for Point Perimeter
    }

};

class Line:public Shapes{

};

class Tri:public Shapes{
    public:
    Point p1;
    Point p2;
    Point p3;

    Tri() {
        
    }

    Tri(Point point1,Point point2,Point point3) {
        p1 = point1;
        p2 = point2;
        p3 = point3;

        glColor3b(0,0,0);
        glBegin(GL_TRIANGLES);
            glVertex2d(p1.x,p1.y);
            glVertex2d(p2.x,p2.y);
            glVertex2d(p3.x,p3.y);

        glEnd();

    }

    Tri(float s1,float s2,float s3) {
        p1 = Point(0,0);
        p2 = Point(s1,0);
        p3.x = (s2*s2 + s1*s1 - s3*s3)/(2*s1);
        p3.y = sqrt(s2*s2 - p3.x*p3.x);

        glColor3b(0,0,0);
        glBegin(GL_TRIANGLES);
            glVertex2d(p1.x,p1.y);
            glVertex2d(p2.x,p2.y);
            glVertex2d(p3.x,p3.y);

        glEnd();
    }

    Tri(float h,float s) {
        p1 = Point(0,0);
        p2 = Point(s,0);
        p3 = Point(0,sqrt(h*h - s*s));

        glColor3b(0,0,0);
        glBegin(GL_TRIANGLES);
            glVertex2d(p1.x,p1.y);
            glVertex2d(p2.x,p2.y);
            glVertex2d(p3.x,p3.y);

        glEnd();
    }

};

class Circle:public Shapes{

};

class Para:public Shapes{

};

class RegPoly:public Shapes{

};