#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <math.h>
#include <cmath>
#include <GL/glut.h>

using namespace std;

//Everyone add bool show to indicate show/hide.

double norm(Point p1,Point p2) {
    return 0;
}

double angleBetweenPoints(Point p1,Point p2,Point p3,bool sh = true) {
    double m1 = (p2.y - p1.y) / (p2.x - p1.x);
    double m2 = (p3.y - p2.y) / (p3.x - p2.x);

    double theta = atan((m2-m1)/(1 + m1*m2));

    theta = theta * 180.0 / M_PI;

    return theta;

}

bool isParallel(Line l1,Line l2) {
    return true;
}

bool isPerpendicular(Line l1,Line l2) {
    return true;
}

class Shapes{

public:
string tag;
virtual double  Area() = 0;
virtual double Perimeter() = 0;

};

class Point:public Shapes{
    public:
    double x;
    double y;
    bool show;
    

    Point() {
    
    }

    Point(double a,double b) {
        x = a;
        y = b;
        show = true;
    }

    Point(double a,double b,bool sh) {
        x = a;
        y = b;
        show = sh;
    }

    double Area() override {
        return 0;
    }

    double Perimeter() override {
        return 0;
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
    bool show;

    Tri() {
        
    }

    Tri(Point point1,Point point2,Point point3) {
        p1 = point1;
        p2 = point2;
        p3 = point3;
        show = true;

        glColor3b(0,0,0);
        glBegin(GL_TRIANGLES);
            glVertex2d(p1.x,p1.y);
            glVertex2d(p2.x,p2.y);
            glVertex2d(p3.x,p3.y);

        glEnd();

    }

    Tri(Point point1,Point point2,Point point3,bool sh) {
        p1 = point1;
        p2 = point2;
        p3 = point3;
        show = sh;

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
        show = true;

        glColor3b(0,0,0);
        glBegin(GL_TRIANGLES);
            glVertex2d(p1.x,p1.y);
            glVertex2d(p2.x,p2.y);
            glVertex2d(p3.x,p3.y);

        glEnd();
    }

    Tri(double s1,double s2,double s3,bool sh) {
        p1 = Point(0,0);
        p2 = Point(s1,0);
        double a = (s2*s2 + s1*s1 - s3*s3)/(2*s1);
        double b = sqrt(s2*s2 - a*a);
        p3 = Point(a,b);
        show = sh;

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
        show = true;

        glColor3b(0,0,0);
        glBegin(GL_TRIANGLES);
            glVertex2d(p1.x,p1.y);
            glVertex2d(p2.x,p2.y);
            glVertex2d(p3.x,p3.y);

        glEnd();
    }

    Tri(double h,double s,bool sh) {
        p1 = Point(0,0);
        p2 = Point(s,0);
        p3 = Point(0,sqrt(h*h - s*s));
        show = sh;

        glColor3b(0,0,0);
        glBegin(GL_TRIANGLES);
            glVertex2d(p1.x,p1.y);
            glVertex2d(p2.x,p2.y);
            glVertex2d(p3.x,p3.y);

        glEnd();
    }

    Point CIRCUMCENTER() {  //Check once again
        double a = (p1.y*p1.y + p2.x*p3.x)*(p2.x - p3.x) + (p2.y*p2.y + p3.x*p1.x)*(p3.x - p1.x) + (p3.y*p3.y + p1.x*p2.x)*(p1.x - p2.x);
        double b = (p1.x*p1.x + p2.y*p3.y)*(p2.y - p3.y) + (p2.x*p2.x + p3.y*p1.y)*(p3.y - p1.y) + (p3.x*p3.x + p1.y*p2.y)*(p1.y - p2.y);
        double c = p2.y*(p3.x-p1.x) - p1.x*(p3.y-p1.y) - (p1.y*p3.x - p3.y*p1.x);
        double k = a/2*c;
        double h = -b/2*c;

        return Point(h,k);

    }

    Point CENTROID() {
        Point g = Point((p1.x+p2.x+p3.x)/3,(p1.y+p2.y+p3.y)/3);
        return g;
    }

    Point ORTHOCENTER() {
        Point o = CIRCUMCENTER();
        Point g = CENTROID();

        Point h = Point(3*g.x - 2*o.x,3*g.y - 2*o.y);

        return h;
    }

    Point EXCENTER(Point p) {
        Line a = Line(p1,p2,false);
        Line b = Line(p2,p3,false);
        Line c = Line(p3,p1,false);

        vector<Line> l1;
        vector<Line> l2;
        vector<Line> l3;

        l1 = ANGLE_BISECTOR(a,b);
        l2 = ANGLE_BISECTOR(b,c);
        l3 = ANGLE_BISECTOR(c,a);
        
        Point q;
        
        if(p1.x==p.x && p1.y==p.y) {
            return INTERSECTION(l2[1],l3[1]);   //Assuming 1st index will give external angle bisector
        }
        else if(p2.x==p.x && p2.y==p.y) {
            return INTERSECTION(l3[1],l1[1]);
        }
        else if(p3.x==p.x && p3.y==p.y) {
            return INTERSECTION(l1[1],l2[1]);
        }
        else {
            return q;
        }
    }

    Point INCENTER() {
        Line a = Line(p1,p2,false);
        Line b = Line(p2,p3,false);
        Line c = Line(p3,p1,false);

        vector<Line> l1;
        vector<Line> l2;
        l1 = ANGLE_BISECTOR(a,b);
        l2 = ANGLE_BISECTOR(b,c);
        Point i = INTERSECTION(l1[0],l2[0]);   //Assuming 1st angle bisector is internal angle bisector

        return i;
    }

    class Line MEDIAN(Point p) {
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

    Line ALTITUDE(Point p) {   //Check once again
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

class Circle:public Shapes {
    float radius;
    class Point center ;

    Circle(float radius, class Point center) {
        this->radius = radius;
        this->center = center;
    }

    
    class Line  TANGENT(class Point q){
        double m;
        m = (center.y - q.y)/(center.x-q.x);
        class Point p;
        p.y = q.y - m*q.x ;
        p.x = 0;
        class Line l;
        l = Line(p,q);
        return l;
    }
    
    
    void tangents (class Point c, double r1, double r2, vector<class Line> & ans) {
        double r = r2 - r1;
        double z = sqrt(c.x) + sqrt(c.y);
        double d = z - sqrt(r);
        if (d < -EPS)  return;
        d = sqrt (abs (d));
        Line l;
        l.a = (c.x * r + c.y * d) / z;
        l.b = (c.y * r - c.x * d) / z;
        l.c = r1;
        ans.push_back (l);
    }
    
    vector<class Point> INTERSECTION(class Circle c1, class Circle c2){
        vector<class Point> p;
        //Finding quadratic equation and then sove it.
        double d = sqrt(pow((c1.center.x-c2.center.x),2) + pow((c1.center.y-c2.center.y),2));
        if(d > c1.radius+ c2.radius)
            return  p;
        if(d < abs(c1.radius - c2.radius))
            return p;
        if(d == 0 &&c1.radius - c2.radius )
            return p;
        double c,k;
        c = (c1.radius*c1.radius- (c2.radius*c2.radius) + (c2.center.x*c2.center.x + c2.center.y*c2.center.y) - (c1.center.x*c1.center.x+ c1.center.x*c1.center.x))/(2*(c2.center.x-c1.center.x)) ;
        k =  (c1.center.y-c2.center.y)/(c2.center.x-c1.center.x);
        double D = (pow((2*c*k - 2*c1.center.x*k-2*c1.center.y),2)) - 4*(k*k+1)*(c1.center.x*c1.center.x+c1.center.y*c1.center.y+c*c-c1.radius*c1.radius-2*c*c1.radius);
        if(D == 0) {
            p[0].y = -1*(pow((2*c*k - 2*c1.center.x*k-2*c1.center.y),2)/2*(k*k+1));
            p[0].x = k*p[0].y + c;
        }
        else {
            p[0].y = -1*(pow((2*c*k - 2*c1.center.x*k-2*c1.center.y),2)/2*(k*k+1)) + sqrt(D);
            p[1].y = -1*(pow((2*c*k - 2*c1.center.x*k-2*c1.center.y),2)/2*(k*k+1)) + sqrt(D);
            p[0].x = k*p[0].y + c ;
            p[0].x = k*p[1].y + c ;
        }

        return p;
    }


    vector<class Line> COMMON_TANGENT(class Circle c1, class Circle c2){
        
        double d = sqrt(pow((c1.center.x-c2.center.x),2) + pow((c1.center.y-c2.center.y),2));
        vector<class Line> ans;
        // for (int i=-1; i<=1; i+=2)
        // {   for (int j=-1; j<=1; j+=2)
        //         tangents (c2-c1, c1.radius*i, c2.radius*j, ans);
        // }
        // for (size_t i=0; i<ans.size(); ++i)
        //     ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
        // return ans;
        class Point p,q,r,s;

        if(c1.radius + c2.radius < d)
        {
            p.x = (c1.radius*c2.center.x +  c2.radius*c1.center.x)/c1.radius+c2.radius;
            p.y = (c1.radius*c2.center.y +  c2.radius*c1.center.y)/c1.radius+c2.radius;
            q.x = (c2.radius*c1.center.x - c1.radius*c2.center.x )/c2.radius-c1.radius;
            q.y = (c2.radius*c1.center.y - c1.radius*c2.center.y  )/c2.radius-c1.radius;

            double D1, D2 ;
            vector<double> m;
            D1 = pow((c1.center.x - p.x),2) - 4*(c1.radius)*(c1.radius)*(pow((c1.radius),2) + c1.center.y - p.y);

            if(D1==0){
                m.push_back((c1.center.x - p.x)/2*(c1.radius)*c1.radius);
                double y;
            }
            else if(D1>0){
                m.push_back((c1.center.x - p.x+ D1)/2*(c1.radius)*c1.radius);
                m.push_back((c1.center.x - p.x- D1)/2*(c1.radius)*c1.radius);
            }

            for(int i=0;i<m.size();i++){
                r.x =0;
                r.y = p.y - m[0]*p.x;
                class Line l;
                l = Line(p,r);
                ans.push_back(l);
            }
            m.clear();

            D2 = pow((c1.center.x - q.x),2) - 4*(c1.radius)*(c1.radius)*(pow((c1.radius),2) + c1.center.y - q.y);
            if(D2 == 0){
                m.push_back((c1.center.x - q.x)/2*(c1.radius)*c1.radius);
            }
            else if( D2 > 0){
                m.push_back((c1.center.x - q.x+ D2)/2*(c1.radius)*c1.radius);
                m.push_back((c1.center.x - q.x- D2)/2*(c1.radius)*c1.radius);
            }

            for(int i=0;i<m.size();i++){
                r.x =0;
                r.y = q.y - m[0]*q.x;
                class Line l;
                l = Line(q,r);
                ans.push_back(l);
            }
            
            return ans;
        }
        else if (c1.radius + c2.radius == d)
        {
        //3
            return l;
        }
        else if (abs(c1.radius - c2.radius) < d < c1.radius + c2.radius)
        {
        //2
            return l;

        }
        else if(abs(c1.radius - c2.radius) == d)
        {
        //1
            return l;
        }
        else if(d <abs(c1.radius - c2.radius) )
        {
            return l;
        }
    }

        
    

    double Area(){
        return 3.14*radius*radius;

    }
    double Perimeter(){
       //Here perimeter means circumference
        return 2*3.14*radius;
    }

};

class Para:public Shapes{
    public:
        Point s1;
        double angle;
        Point s2;
    
    Para(Point point1, double ang, Point point2){
        s1 = point1;
        angle = ang;
        s2 = point2;

        Point p1,p2,p3,p4;
        p1 = Point(0,0);
        p2 = Point(s1,0);
        p3 = Point(s2*cos(angle)+s1,s2*sin(angle));
        p4 = Point(s2*cos(angle),s2*sin(angle));

        glColor3b(0,0,0);
        glBegin(GL_QUADS);
            glVertex2d(p1.x,p1.y);
            glVertex2d(p2.x,p2.y);
            glVertex2d(p3.x,p3.y);
            glVertex2d(p4.x,p4.y);
        glEnd();
    }

    vector<class Line> DIAGONAL(){
        vector<Line> l;
        l.push_back(Line((0,0),(s2*cos(angle)+s1,s2*sin(angle))));
        l.push_back(Line((s2*cos(angle),s2*sin(angle)),(s1,0)));
        
        glColor3b(0,0,0);
        glBegin(GL_LINES);
            glVertex2d(l[0].p1.x,l[0].p1.y);
            glVertex2d(l[0].p2.x,l[0].p2.y);
            glVertex2d(l[1].p1.x,l[1].p1.y);
            glVertex2d(l[1].p2.x,l[1].p2.y);
        glEnd();
        return l;
    }

    double Area() override {
        return s1*s2*sin(angle);
    }

    double Perimeter() override {
        return 2*(s1+s2);
    }
};

class RegPoly:public Shapes{
    class Point center;
    int numOfSides;
    float sideLength;

    RegPoly(int numOfSides, float sideLength, class Point center){
        this->numOfSides = numOfSides;
        this->sideLength = sideLength;
        this->center = center;
    }

    double Area(){
        return ((numOfSides*sideLength*sideLength)/(4*tan(3.14/numOfSides)));
    }

    double Perimeter(){
        return numOfSides*sideLength;
    }

    

};