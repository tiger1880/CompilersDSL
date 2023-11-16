#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <math.h>
#include<cmath>
#include<GL/glut.h>

using namespace std;

double norm(Point p1,Point p2) {
    return 0;
}

class Shapes{

public:
string label;
virtual double  Area()=0;
virtual double Perimeter()=0;

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

    double Area() override {
        // Implementation for Point Area
    }

    double Perimeter() override {
        // Implementation for Point Perimeter
    }

};

class Line:public Shapes{

    double Area() override {
        // Implementation for Line Area
    }

    double Perimeter() override {
        // Implementation for Line Perimeter
    }

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

    Tri(double s1,double s2,double s3) {
        p1 = Point(0,0);
        p2 = Point(s1,0);
        double a = (s2*s2 + s1*s1 - s3*s3)/(2*s1);
        double b = sqrt(s2*s2 - a*a);
        p3 = Point(a,b);

        glColor3b(0,0,0);
        glBegin(GL_TRIANGLES);
            glVertex2d(p1.x,p1.y);
            glVertex2d(p2.x,p2.y);
            glVertex2d(p3.x,p3.y);

        glEnd();
    }

    Tri(double h,double s) {
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

    Point CIRCUMCENTER() {
        double a = (p1.y*p1.y + p2.x*p3.x)*(p2.x - p3.x) + (p2.y*p2.y + p3.x*p1.x)*(p3.x - p1.x) + (p3.y*p3.y + p1.x*p2.x)*(p1.x - p2.x);
        double b = (p1.x*p1.x + p2.y*p3.y)*(p2.y - p3.y) + (p2.x*p2.x + p3.y*p1.y)*(p3.y - p1.y) + (p3.x*p3.x + p1.y*p2.y)*(p1.y - p2.y);
        double c = p2.y*(p3.x-p1.x) - p1.x*(p3.y-p1.y) - (p1.y*p3.x - p3.y*p1.x);
        double k = a/2*c;
        double h = -b/2*c;

        return Point(h,k);

    }

    Point ORTHOCENTER() {
        
    }

    Point CENTROID() {
        Point g = Point((p1.x+p2.x+p3.x)/3,(p1.y+p2.y+p3.y)/3);
        return g;
    }

    Point EXCENTER(Point p) {
        
    }

    Point INCENTER() {
        
    }

    Line MEDIAN(Point p) {
        Point q;
        if(p1.x==p.x && p1.y==p.y) {
            q = Point((p2.x+p3.x)/2,(p2.y+p3.y)/2);
            return Line(p,q);
        }
        else if(p2.x==p.x && p2.y==p.y) {
            q = Point((p1.x+p3.x)/2,(p1.y+p3.y)/2);
            return Line(p,q);
        }
        else if(p3.x==p.x && p3.y==p.y) {
            q = Point((p2.x+p1.x)/2,(p2.y+p1.y)/2);
            return Line(p,q);
        }
        else {
            return Line();
        }
    }

    Line ALTITUDE(Point p) {
        Point q;
        if(p1.x==p.x && p1.y==p.y) {
            double c = (p2.x-p3.x)*(p2.x-p3.x) + (p2.y-p3.y)*(p2.y-p3.y);
            double a = (p2.x-p3.x)*(p2.x-p3.x)*p1.x + (p2.y-p3.y)*(p2.y-p3.y)*p2.x + (p1.y-p2.y)*(p2.y-p3.y)*(p2.x-p3.x);
            double b = (p2.x-p3.x)*(p2.x-p3.x)*p2.y + (p2.y-p3.y)*(p2.y-p3.y)*p1.y + (p1.x-p2.x)*(p2.y-p3.y)*(p2.x-p3.x);
            q = Point(a/c,b/c);
            return Line(p,q);
        }
        else if(p2.x==p.x && p2.y==p.y) {
            double c = (p3.x-p1.x)*(p3.x-p1.x) + (p3.y-p1.y)*(p3.y-p1.y);
            double a = (p3.x-p1.x)*(p3.x-p1.x)*p2.x + (p3.y-p1.y)*(p3.y-p1.y)*p3.x + (p2.y-p3.y)*(p3.y-p1.y)*(p3.x-p1.x);
            double b = (p3.x-p1.x)*(p3.x-p1.x)*p3.y + (p3.y-p1.y)*(p3.y-p1.y)*p2.y + (p2.x-p3.x)*(p3.y-p1.y)*(p3.x-p1.x);
            q = Point(a/c,b/c);
            return Line(p,q);
        }
        else if(p3.x==p.x && p3.y==p.y) {
            double c = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
            double a = (p1.x-p2.x)*(p1.x-p2.x)*p3.x + (p1.y-p2.y)*(p1.y-p2.y)*p1.x + (p3.y-p1.y)*(p1.y-p2.y)*(p1.x-p2.x);
            double b = (p1.x-p2.x)*(p1.x-p2.x)*p1.y + (p1.y-p2.y)*(p1.y-p2.y)*p3.y + (p3.x-p1.x)*(p1.y-p2.y)*(p1.x-p2.x);
            q = Point(a/c,b/c);
            return Line(p,q);
        }
        else {
            return Line();
        }
    }

    double Area() override {
        double area;
        area = abs(p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y))/2;

        return area;
    }

    double Perimeter() override {
       return norm(p1,p2) + norm(p2,p3) + norm(p3,p1);
        
    }

};

class Circle:public Shapes{

};

class Para:public Shapes{

};

class RegPoly:public Shapes{

};