#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <math.h>
#include <cmath>
#include <GL/glut.h>

using namespace std;

const double  PI  = 3.14;
double height = 500, width = 500, axisLength = 50, aspectRatio = 1, xAxis = 10, yAxis = 10;


vector<Shape*> shapeStore;


// OPENGL --------------------------------------

void init(){

    glClearColor(1.0, 1.0, 1.0, 1.0); // sets the background

}

void reshape(int w, int h){

    height = h; // zero height debug
    width = w;

    // viewport => only here inside the window things will be displayed
    glViewport(0, 0, w, h); // 0, 0 is the bottom-left of whole window

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);


    if (h == 0)
        h = 1;

    float aspect = (float)w/h;
    aspectRatio = aspect;

    // projection
    glMatrixMode(GL_PROJECTION); // for setting projection matrices
    glLoadIdentity(); // resets the axes

    // -10 to 10 right now

    // to prevent shape distortion on resizing window => just increases the coordinate axes
    if (w >= h){
        gluOrtho2D(-axisLength*aspect, axisLength*aspect, -axisLength, axisLength); // left right bottom top

        xAxis = axisLength*aspect;
        yAxis = axisLength;
    }
    else {
        gluOrtho2D(-axisLength, axisLength, -axisLength/aspect, axisLength/aspect); // left right bottom top

        xAxis = axisLength;
        yAxis = axisLength/aspect;
    }


    glMatrixMode(GL_MODELVIEW); // always be in this mode
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); 

    glColor3f(0.0, 0.0, 0.0); // black everything

    
    // glPointSize(5); // how to get circular points

    
    // draw

    for (int i = 0;i < shapeStore.size();i++){
        shapeStore[i]->show();
    }

    // switch buffers
    glutSwapBuffers();


}

void renderBitmapString(float x, float y, const char *string) {
    glRasterPos2f(x, y);
    
    for (const char *c = string; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

// OPENGL --------------------------------------

double norm(Point p1, Point p2)
{
    double res = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    return res;
}

double norm(Point p1)
{
    double res = sqrt(pow((p1.x), 2) + pow((p1.y), 2));
    return res;
}

double angleBetweenPoints(Point p1, Point p2, Point p3, bool sh = true)
{
    double m1 = (p2.y - p1.y) / (p2.x - p1.x);
    double m2 = (p3.y - p2.y) / (p3.x - p2.x);

    double theta = atan((m2 - m1) / (1 + m1 * m2));

    theta = theta * 180.0 / M_PI;

    return theta;
}


class Shape
{

public:
    virtual double Area() = 0;
    virtual double Perimeter() = 0;
    Shape(){
       ;
    }
    virtual void show(){}
};

class Point : public Shape
{
public:
    double x;
    double y;
    string tag;
    bool show;
    double scale;
    double center_x;
    double center_y;

    Point()
    {

    }

    // store globally center aswell
    Point(double a, double b, string s, bool sh = true, double Scale = 1.0, double cx = 0, double cy = 0)
    {
        scale = Scale;
        center_x = cx;
        center_y = cy;
        x = a;
        y = b;
        tag = s;
        show = sh;
        shapeStore.push_back(this);
    }
    
    Point(double a, double b, bool sh = true, double Scale = 1.0, double cx = 0, double cy = 0)
    {
        scale = Scale;
        center_x = cx;
        center_y = cy;
        x = a;
        y = b;
        show = sh;
        shapeStore.push_back(this);
    }

    void show() {

        glTranslatef(center_x, center_y, 0.0f);
        glScalef(scale, scale, 0.0f);
        glColor3b(0, 0, 0);

        glBegin(GL_POINTS);
        glVertex2d(x,y);
        glEnd();

        renderBitmapString(x + 0.01,y + 0.01, tag.c_str());
        glLoadIdentity();


    }

    double Area() override
    {
        return 0;
    }

    double Perimeter() override
    {
        return 0;
    }


};

/*
class Line : public Shape
{
    double scale;
    class Point center;
    double Area() override
    {
        // Implementation for Line Area
    }

    double Perimeter() override
    {
        // Implementation for Line Perimeter
    }
};


Ignore 
    1) testing some parts is left in Line
    2) replace with loop and check .. Maybe should start properly => angle bisector
    3) Test the extension fo 6 cases => change so that if initial points are outofRange update Range, => Depends on our set Range
    4) Have to display midpoint ? 
    5) we will have to use new update constructors properly and delete in main after MainLoop



class Point : public Shape{

    public:
    double x;
    double y;
    bool isDisplayed;

    Point(double x1 = 0, double x2 = 0, bool h = false):
    x(x1),
    y(x2), 
    isDisplayed(h)
    {
        if (isDisplayed){
            cout << "Point: " << x << " " << y << " pushed back\n";
            d.push_back(this);
        }

    }

    // copy constructor
    Point(const Point& t){

        x = t.x;
        y = t.y;
        isDisplayed = t.isDisplayed;

    }

    // copy assignment operator
    Point& operator=(const Point& p){

        x = p.x;
        y = p.y;
        isDisplayed = p.isDisplayed;

        return *this;

    }


    void show() {

        glBegin(GL_POINTS);
        // glColor3f(1.0, 0.0, 0.0); // color of the point
        // specify in anti-clockwise direction
        glVertex2f(x, y); // expects float check double overflow

        glEnd();
       
    }
};


*/

enum lineType {
    SEGMENT, 
    RAY,
    LINE
};


class Line : public Shape {

    // if both points are same then shows a point
    Point a;
    Point b;
    bool show;

    // y = mx+c
    double m;
    double c;

    lineType t; // RAY, LINE, SEGMENT
    double angle; // clockwise angle in degrees

    // figures
    double scale;
    Point center;

    double R(bool positive, Point initial, Point final){

        double r, r1, r2;
        if (positive){

            r1 = (yAxis - abs(final.y))/sin(angle*PI/180);       
            r2 = (xAxis - abs(final.x))/cos(angle*PI/180);

            r1 = abs(r1);
            r2 = abs(r2);
            r = min(r1, r2)-1;

            return r;

        }
        else {

            r1 = (abs(b.y) - yAxis)/sin(angle*PI/180);       
            r2 = (abs(b.x) - xAxis)/cos(angle*PI/180);

            r1 = abs(r1);
            r2 = abs(r2);

            
            r = min(r1, r2)-1;

            return r;
            

        }

    }

    public:

    Line(Point x1, Point x2, lineType type = SEGMENT, double Scale = 1.0, Point Center = Point(0, 0, false), bool sh = true):
    a(x1),
    b(x2),
    t(type),
    show(sh),
    m(0),
    c(0),
    scale(Scale),
    center(Center)
    {
        // if (x1 != x2){
            // cout << "Line: " << a.x << ", " << a.y << " " << b.x << ", " << b.y << " pushed back\n";
        // }

        shapeStore.push_back(this);
        
        if (x1.x == x2.x){
            angle = 90.0;
        }
        else {
            angle = atan((x2.y - x1.y)/(x2.x - x1.x))*180/PI;
        }

        if (angle < 0)
            angle += 180;

        if (angle != 90){
            m = (b.y - a.y)/(b.x-a.x);
            c = b.y - m*b.x;
        }

    }

    // m, c constructor
    // y = mx + c
    Line(double m1, double c1, double Scale = 1.0, Point Center = Point(0, 0, false), bool sh = false):
    m(m1),
    c(c1),
    show(sh),
    scale(Scale),
    center(Center)
    {

        // (0, c), (1, m+c) taken as points

        a.x = 0;
        a.y = c;

        b.x = 1;
        b.y = m+c;

        angle = atan(m1)*180/PI;
        show = true;
        t = LINE;

        shapeStore.push_back(this);

    }

    // Copy Constructor
    Line(const Line& l){
        a = l.a;
        b = l.b;
        show = l.show; // if its true already pushed
        angle =  l.angle;
        c = l.c;
        m = l.m;
        t = l.t;
        
        // cout << "copy called\n";
    }

    // copy assignment operator
    Line& operator=(const Line& l){

        a = l.a;
        b = l.b;
        show = l.show; // if its true already pushed
        angle =  l.angle;
        c = l.c;
        m = l.m;
        t = l.t;
        
        // cout << "assignment called\n";

        return *this;

    }

    void printEquation(){

        cout << "m: " << m << endl;
        cout << "c: " << c << endl;
        cout << "angle: " << angle << endl;

    }

    void setDisplay(bool d){

        show = d;
        return;
    }

    void showSegment(){


        glTranslatef(center.x, center.y, 0.0f);
        glScalef(scale, scale, 0.0f);
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex2d(a.x, a.y);
        glVertex2d(b.x, b.y);
        glEnd();
        glLoadIdentity();
    }

    void showRay(){

        // 1/2 diagnol of unit length box
        double arrowLength = width/(2*(1.14)*xAxis);

        double xFinal, yFinal;

        double r, r1, r2;   

         if (a == b){
            xFinal = b.x;
            yFinal = b.y;
        }
        else {

            // positive
            r = R(true, a, b);

            xFinal = b.x + r*cos(angle*PI/180);
            yFinal = b.y + r*sin(angle*PI/180); 

            double flag = 0;

            // check same side
            if (a.x != b.x)
                flag = (xFinal - a.x)/(b.x - a.x);
            else 
                flag = (yFinal - a.y)/(b.y - a.y);

            if (flag < 0){
                
                // negative
                r = R(false, a, b);
                xFinal = b.x - r*cos(angle*PI/180);
                yFinal = b.y - r*sin(angle*PI/180); 
                
            }
        
        }

        glTranslatef(center.x, center.y, 0.0f);
        glScalef(scale, scale, 0.0f);
        glColor3f(0.0, 0.0, 0.0);

        glBegin(GL_LINES);
        glVertex2f(a.x, a.y); 
        glVertex2f(b.x, b.y);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(a.x, a.y);
        glVertex2f(xFinal, yFinal);
        glEnd();


        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        glVertex2f(xFinal, yFinal);
        glEnd();

        glLoadIdentity();
        glColor3f(0.0, 0.0, 0.0);

        // arrow

        // glTranslatef(xFinal, yFinal, 0.0);
        // glRotatef(angle, 0, 0, 1.0);

        // glBegin(GL_LINE_STRIP)
        // glVertex2f(cos(45), sin(45));
        // glVertex2f(0, 0);
        // glVertex2f(, );
        // glEnd();

    }

    void showLine(){


        showRay();

        swap(a.x, b.x);
        swap(a.y, b.y);

        showRay();
        
        swap(a.x, b.x);
        swap(a.y, b.y);

    }

    void show(){
        
        switch (t)
        {
        case SEGMENT:
            showSegment();
            break;
        case RAY:
            showRay();
            break;
        case LINE:
            showLine();
            break;
        default:
            break;
        }
    }

    friend Point INTERSECTION(Line l1, Line l2);
    friend Line& LINE_AT_ANGLE(double a, Line& l, Point p);
    friend vector<Line> ANGLE_BISECTOR(Line a, Line b); 
    friend bool isPerpendicular(Line l1, Line l2);
    friend bool isParallel(Line l1, Line l2);
   
    Point MIDPOINT(){

        if (t != SEGMENT)
            return b;
        
        Point p = new Point((a.x+b.x)/2, (a.y+b.y)/2); 

        return p;

    }

    bool passesThrough(Point p){


        if (angle == 90){
            
            if (p.x == a.x)
                return true;
            return false;

        }

        if (p.y == (m*p.x + c))
            return true;
        
        return false;

        
    }

    double Area() override
    {
        return 0;
    }

    double Perimeter() override
    {
        return 0;
    }

};


Point rotatePoint(const Point& point, const Point& center, double theta) {
    double x = center.x + (point.x - center.x) * std::cos(theta) - (point.y - center.y) * std::sin(theta);
    double y = center.y + (point.x - center.x) * std::sin(theta) + (point.y - center.y) * std::cos(theta);
    return {x, y};
}

Line& LINE_AT_ANGLE(double a, Line& l, Point p){


    if (!l.passesThrough(p)){

        cout << "LINE_AT_ANGLE: p doesn't pass through l\n";
        return l;
    }

    Point rotatePoint1(0, 0, false);
    Point rotatePoint2(0, 0, false);

    while (a >= 180)
        a -= 180;

    rotatePoint1 = rotatePoint(l.a, p, a*PI/180);
    rotatePoint2 = rotatePoint(l.b, p, a*PI/180);

    Line* l1 = new Line(rotatePoint1, rotatePoint2, LINE); // defaulting it LINE for now

    return *l1; // delete ??

}

// add test cases
Point INTERSECTION(Line l1, Line l2){


    if (l1.t != LINE || l2.t != LINE){

        cout << "Define intersection for the rest" << "\n";

        return l1.a;
    }

    if (l1.m == l2.m){
        cout << "Do not intersect" << "\n";
        return l1.a;
    }

    Point p = new Point(0.0, 0.0);  // WTH
    
    if (l1.angle == 90){
        p.x = l1.a.x;
        p.y = l2.m*p.x + l2.c;


        return p;
    }

    if (l2.angle == 90){
        p.x = l2.a.x;
        p.y = l1.m*p.x + l1.c;
        cout << l1.m << " " << l1.c << "\n";


        return p;
    }


    p.x = (l2.c - l1.c)/(l1.m - l2.m);
    p.y = l1.m*p.x + l1.c;
    
    return p;

}

vector<Line> ANGLE_BISECTOR(Line a, Line b){

    vector<Line>* x = new vector<Line>();

    if (a.angle == 90 && b.angle == 90){

        cout << "Parallel lines cannot have angle bisectors\n";
        return *x;
    }

    if (a.m == b.m){

        cout << "Parallel lines cannot have angle bisectors\n";
        return *x;
    }

    double d1 = pow(1 + a.m*a.m, 0.5);
    double d2 = pow(1 + b.m*b.m, 0.5);

    Line* l1 = new Line((a.m*d2 - b.m*d1)/(d2 - d1), (a.c*d2 - b.c*d1)/(d2-d1), true);
    Line* l2 = new Line((a.m*d2 + b.m*d1)/(d2 + d1), (a.c*d2 + b.c*d1)/(d2+d1), true);

    x->push_back(*l1);
    x->push_back(*l2);

    return *x;

}


bool isPerpendicular(Line l1, Line l2)
{
    if (l1.m*l2.m == -1)
        return true;
    return false;
}

// upgrade 
bool isParallel(Line l1, Line l2)
{   
    if (l1.m == l2.m)
        return true;

    return false;
}

class Tri : public Shape
{
public:
    Point p1;
    Point p2;
    Point p3;
    bool show;
    double scale;
    Point center; 

    Tri()
    {
        ;
    }

    Tri(Point point1, Point point2, Point point3, bool sh = true, Point Center = Point(0, 0, false),double Scale = 1.0)
    {
        p1 = point1;
        p2 = point2;
        p3 = point3;
        show = sh;
        scale = Scale;
        center = Center;
        shapeStore.push_back(this);

    }


    Tri(double s1, double s2, double s3, bool sh = true, Point center = Point(0, 0, false),double scale = 1.0)
    {
        p1 = Point(0, 0);
        p2 = Point(s1, 0);
        double a = (s2 * s2 + s1 * s1 - s3 * s3) / (2 * s1);
        double b = sqrt(s2 * s2 - a * a);
        p3 = Point(a, b);
        show = sh;
        shapeStore.push_back(this);

       
    }

    Tri(double h, double s, bool sh = true, class Point center = Point(0, 0, false),double scale = 1.0)
    {
        p1 = Point(0, 0);
        p2 = Point(s, 0);
        p3 = Point(0, sqrt(h * h - s * s));
        show = sh;
        shapeStore.push_back(this);

    }

    void show()
    {   
        glTranslatef(center.x, center.y, 0.0f);
        glScalef(scale, scale, 0.0f);
        glColor3b(0, 0, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(p1.x, p1.y);
        glVertex2d(p2.x, p2.y);
        glVertex2d(p3.x, p3.y);

        glEnd();
        // glLoadIdentity();
        glTranslatef(-center.x, -center.y, 0.0f);
        glScalef((1.0/scale), (1.0/scale), 0.0f);

    }

    Point CIRCUMCENTER() // SEGFAULT
    { // Check once again
        double a = (p1.y * p1.y + p2.x * p3.x) * (p2.x - p3.x) + (p2.y * p2.y + p3.x * p1.x) * (p3.x - p1.x) + (p3.y * p3.y + p1.x * p2.x) * (p1.x - p2.x);
        double b = (p1.x * p1.x + p2.y * p3.y) * (p2.y - p3.y) + (p2.x * p2.x + p3.y * p1.y) * (p3.y - p1.y) + (p3.x * p3.x + p1.y * p2.y) * (p1.y - p2.y);
        double c = p2.y * (p3.x - p1.x) - p1.x * (p3.y - p1.y) - (p1.y * p3.x - p3.y * p1.x);
        double k = a / 2 * c;
        double h = -b / 2 * c;

        return Point(h, k);
    }

    Point CENTROID()
    {
        Point g = Point((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3);
        return g;
    }

    Point ORTHOCENTER()
    {
        Point o = CIRCUMCENTER();
        Point g = CENTROID();
        Point h = Point(3 * g.x - 2 * o.x, 3 * g.y - 2 * o.y);

        return h;
    }

    Point EXCENTER(Point p)
    {
        Line a = Line(p1, p2, false);
        Line b = Line(p2, p3, false);
        Line c = Line(p3, p1, false);

        vector<Line> l1;
        vector<Line> l2;
        vector<Line> l3;

        l1 = ANGLE_BISECTOR(a, b);
        l2 = ANGLE_BISECTOR(b, c);
        l3 = ANGLE_BISECTOR(c, a);

        Point q;

        if (p1.x == p.x && p1.y == p.y)
        {
            return INTERSECTION(l2[1], l3[1]); // Assuming 1st index will give external angle bisector
        }
        else if (p2.x == p.x && p2.y == p.y)
        {
            return INTERSECTION(l3[1], l1[1]);
        }
        else if (p3.x == p.x && p3.y == p.y)
        {
            return INTERSECTION(l1[1], l2[1]);
        }
        else
        {
            return q;
        }
    }

    Point INCENTER() // SEGFAULT
    {
        Line a = Line(p1, p2, false);
        Line b = Line(p2, p3, false);
        Line c = Line(p3, p1, false);

        vector<Line> l1;
        vector<Line> l2;
        l1 = ANGLE_BISECTOR(a, b);
        l2 = ANGLE_BISECTOR(b, c);
        Point i = INTERSECTION(l1[0], l2[0]); // Assuming 1st angle bisector is internal angle bisector

        return i;
    }

    class Line MEDIAN(Point p) // will SEGFAULT
    {
        Point q;
        if (p1.x == p.x && p1.y == p.y)
        {
            q = Point((p2.x + p3.x) / 2, (p2.y + p3.y) / 2);
            return Line(p, q);
        }
        else if (p2.x == p.x && p2.y == p.y)
        {
            q = Point((p1.x + p3.x) / 2, (p1.y + p3.y) / 2);
            return Line(p, q);
        }
        else if (p3.x == p.x && p3.y == p.y)
        {
            q = Point((p2.x + p1.x) / 2, (p2.y + p1.y) / 2);
            return Line(p, q);
        }
        else
        {
            return Line();
        }
    }

    Line
    ALTITUDE(Point p)
    { // Check once again // will SEGFAULT
        Point q;
        if (p1.x == p.x && p1.y == p.y)
        {
            double c = (p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y);
            double a = (p2.x - p3.x) * (p2.x - p3.x) * p1.x + (p2.y - p3.y) * (p2.y - p3.y) * p2.x + (p1.y - p2.y) * (p2.y - p3.y) * (p2.x - p3.x);
            double b = (p2.x - p3.x) * (p2.x - p3.x) * p2.y + (p2.y - p3.y) * (p2.y - p3.y) * p1.y + (p1.x - p2.x) * (p2.y - p3.y) * (p2.x - p3.x);
            q = Point(a / c, b / c);
            return Line(p, q);
        }
        else if (p2.x == p.x && p2.y == p.y)
        {
            double c = (p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y);
            double a = (p3.x - p1.x) * (p3.x - p1.x) * p2.x + (p3.y - p1.y) * (p3.y - p1.y) * p3.x + (p2.y - p3.y) * (p3.y - p1.y) * (p3.x - p1.x);
            double b = (p3.x - p1.x) * (p3.x - p1.x) * p3.y + (p3.y - p1.y) * (p3.y - p1.y) * p2.y + (p2.x - p3.x) * (p3.y - p1.y) * (p3.x - p1.x);
            q = Point(a / c, b / c);
            return Line(p, q);
        }
        else if (p3.x == p.x && p3.y == p.y)
        {
            double c = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
            double a = (p1.x - p2.x) * (p1.x - p2.x) * p3.x + (p1.y - p2.y) * (p1.y - p2.y) * p1.x + (p3.y - p1.y) * (p1.y - p2.y) * (p1.x - p2.x);
            double b = (p1.x - p2.x) * (p1.x - p2.x) * p1.y + (p1.y - p2.y) * (p1.y - p2.y) * p3.y + (p3.x - p1.x) * (p1.y - p2.y) * (p1.x - p2.x);
            q = Point(a / c, b / c);
            return Line(p, q);
        }
        else
        {
            return Line();
        }
    }

    double Area() override
    {
        double area;
        area = abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2;

        return area;
    }

    double Perimeter() override
    {
        return norm(p1, p2) + norm(p2, p3) + norm(p3, p1);
    }
};

class Circle : public Shape
{
    public:
    float radius;
    Point center;
    double scale;
    bool show;

    Circle(float radius, Point Center = Point(0,0),bool sh = true, double scale = 1.0)
    {   
        this->radius = radius;
        this->center = center;
        scale = Scale;
        center = Center;
        show = sh;
        shapeStore.push_back(this);
        
    }

    void show()
    {   
        glScalef(scale, scale, 0.0f);
        glTranslatef(center.x, center.y, 0.0f);

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 1.0f, 1.0f); // Blue
        GLfloat angle;
        for (int i = 0; i <= 360; i++)
        {
            angle = i * PI / 180; // 360 deg for all segments
            glVertex2f(cos(angle) * radius, sin(angle) * radius);
        }
        glEnd();

        // glLoadIdentity();
        glTranslatef(-center.x, -center.y, 0.0f);
        glScalef((1.0/scale), (1.0/scale), 0.0f);

    }

    Line TANGENT(Point q)
    {
        double m;
        m = (center.y - q.y) / (center.x - q.x);
        Point p;
        p.y = q.y - m * q.x;
        p.x = 0;
        Line l;
        l = Line(p, q); // will SEGFAULT
        return l;
    }

    double Area()
    {
        return 3.14 * radius * radius;
    }

    // Here perimeter means circumference
    double Perimeter()
    {
        return 2 * 3.14 * radius;
    }
};

class Para : public Shape
{
public:
    Point p1;    //p1,p2,p3,p4 are attributes 
    Point p2;
    Point p3;
    Point p4;
    double scale;
    Point center; 
    bool show;

    Para(double s1, double ang, double s2, bool sh = true,class Point center = Point(0, 0, false), double scale = 1.0)
    {
        
        p1 = Point(0, 0);
        p2 = Point(s1, 0);
        p3 = Point(s2 * cos(ang) + s1, s2 * sin(ang));
        p4 = Point(s2 * cos(ang), s2 * sin(ang));
        show = sh;
        shapeStore.push_back(this);

    }

    void show(){
        
        glTranslatef(center.x, center.y, 0.0f);
        glScalef(scale, scale, 0.0f);
        glColor3b(0, 0, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(p1.x, p1.y);
        glVertex2d(p2.x, p2.y);
        glVertex2d(p3.x, p3.y);
        glVertex2d(p4.x, p4.y);
        glEnd();
        // glLoadIdentity();
        glTranslatef(-center.x, -center.y, 0.0f);
        glScalef((1.0/scale), (1.0/scale), 0.0f);
    }

    vector<Line> DIAGONAL() {
        vector<Line> diagonals;

        diagonals.push_back(Line(p1,p3));
        diagonals.push_back(Line(p2,p4));

        return diagonals;
    }

    // vector<class Line> DIAGONAL(){
    //     vector<Line> l;
    //     l.push_back(Line((0,0),(s2*cos(angle)+s1,s2*sin(angle))));
    //     l.push_back(Line((s2*cos(angle),s2*sin(angle)),(s1,0)));

    //     glColor3b(0,0,0);
    //     glBegin(GL_LINES);
    //         glVertex2d(l[0].p1.x,l[0].p1.y);
    //         glVertex2d(l[0].p2.x,l[0].p2.y);
    //         glVertex2d(l[1].p1.x,l[1].p1.y);
    //         glVertex2d(l[1].p2.x,l[1].p2.y);
    //     glEnd();
    //     return l;
    // }

    double Area() override
    {
        double s1 = norm(p1,p2);
        double s2 = norm(p2,p3);
        double angle = angleBetweenPoints(p1,p2,p3);
        return s1 * s2 * sin(angle);
    }

    double Perimeter() override
    {
        double s1 = norm(p1,p2);
        double s2 = norm(p2,p3);
        return 2 * (s1 + s2);
    }
};

class RegPoly : public Shape
{
    int numOfSides;
    double sideLength;
    double scale;
    Point center;
    bool show; 

    RegPoly(int numOfSides, double sideLength, Point Center = Point(0, 0, false), double Scale = 1.0)
    {
        scale = Scale;
        center = Center;
        this->numOfSides = numOfSides;
        this->sideLength = sideLength;
        shapeStore.push_back(this);
        
    }

    void show()
    {
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color
        
        glTranslatef(center.x, center.y, 0.0f);
        glScalef(scale, scale, 0.0f);
        glColor3f(0.0, 0.0, 0.0);

        glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 0.0f, 1.0f); // Yellow

        GLfloat angle = 0;
        for (int i = 0; i < numOfSides; i++)
        {
            glVertex2f(sideLength * cos(angle), sideLength * sin(angle));
            angle += (PI / 180) *(360 / numOfSides);
        }
        glEnd();

        // glLoadIdentity();
        glTranslatef(-center.x, -center.y, 0.0f);
        glScalef((1.0/scale), (1.0/scale), 0.0f);

    }

    double Area()
    {
        return ((numOfSides * sideLength * sideLength) / (4 * tan(PI / numOfSides)));
    }

    double Perimeter()
    {
        return numOfSides * sideLength;
    }
};


//Non-memeber functions
vector<class Point>
    INTERSECTION_CIRCLE(class Circle c1, class Circle c2)
    {
        vector<class Point> p;
        // Finding quadratic equation and then sove it.
        double d = sqrt(pow((c1.center.x - c2.center.x), 2) + pow((c1.center.y - c2.center.y), 2));
        if (d > c1.radius + c2.radius)
            return p;
        if (d < abs(c1.radius - c2.radius))
            return p;
        if (d == 0 && (c1.radius - c2.radius) == 0)
            return p;
        double c, k;
        c = (c1.radius * c1.radius - (c2.radius * c2.radius) + (c2.center.x * c2.center.x + c2.center.y * c2.center.y) - (c1.center.x * c1.center.x + c1.center.x * c1.center.x)) / (2 * (c2.center.x - c1.center.x));
        k = (c1.center.y - c2.center.y) / (c2.center.x - c1.center.x);
        double D = (pow((2 * c * k - 2 * c1.center.x * k - 2 * c1.center.y), 2)) - 4 * (k * k + 1) * (c1.center.x * c1.center.x + c1.center.y * c1.center.y + c * c - c1.radius * c1.radius - 2 * c * c1.radius);
        if (D == 0)
        {
            p[0].y = -1 * (pow((2 * c * k - 2 * c1.center.x * k - 2 * c1.center.y), 2) / 2 * (k * k + 1));
            p[0].x = k * p[0].y + c;
        }
        else
        {
            p[0].y = -1 * (pow((2 * c * k - 2 * c1.center.x * k - 2 * c1.center.y), 2) / 2 * (k * k + 1)) + sqrt(D);
            p[1].y = -1 * (pow((2 * c * k - 2 * c1.center.x * k - 2 * c1.center.y), 2) / 2 * (k * k + 1)) + sqrt(D);
            p[0].x = k * p[0].y + c;
            p[0].x = k * p[1].y + c;
        }

        return p;
    }

    vector<class Line> COMMON_TANGENT(class Circle c1, class Circle c2) {
        vector<Line> tangents;
        double c1c2 = norm(c1.center,c2.center);

        if(c1c2 < abs(c1.radius - c2.radius)) {
            return tangents;
        }
        
        else if( c1c2 == abs(c1.radius - c2.radius)) {
            vector<Point> intersect;
            intersect = INTERSECTION_CIRCLE(c1,c2);
            Line l = c1.TANGENT(intersect[0]);
            tangents.push_back(l);
            return tangents;
        }
        
        else if(c1c2 > abs(c1.radius - c2.radius) && c1c2 < c1.radius + c2.radius) {
            Point p;
            p.x = (c2.radius*c1.center.x - c1.radius*c2.center.x) / (c2.radius - c1.radius);
            p.y = (c2.radius*c1.center.y - c1.radius*c2.center.y) / (c2.radius - c1.radius);
            double d1 = norm(p,c1.center);
            Circle c = Circle(sqrt(d1*d1 - c1.radius*c1.radius),p,false);
            vector<Point> intersect;
            intersect = INTERSECTION_CIRCLE(c1,c);
            tangents.push_back(Line(p,intersect[0]));
            tangents.push_back(Line(p,intersect[1]));
            return tangents;
        }
        
        else if(c1c2 == c1.radius + c2.radius) {
            vector<Point> intersect;
            intersect = INTERSECTION_CIRCLE(c1,c2);
            Line l = c1.TANGENT(intersect[0]);
            tangents.push_back(l);

            Point p;
            p.x = (c2.radius*c1.center.x - c1.radius*c2.center.x) / (c2.radius - c1.radius);
            p.y = (c2.radius*c1.center.y - c1.radius*c2.center.y) / (c2.radius - c1.radius);
            double d1 = norm(p,c1.center);
            Circle c = Circle(sqrt(d1*d1 - c1.radius*c1.radius),p,false);
            vector<Point> intersect2;
            intersect2 = INTERSECTION_CIRCLE(c1,c);
            tangents.push_back(Line(p,intersect2[0]));
            tangents.push_back(Line(p,intersect2[1]));
            return tangents;
        }
        
        else if(c1c2 > c1.radius + c2.radius) {
            Point p;
            p.x = (c2.radius*c1.center.x - c1.radius*c2.center.x) / (c2.radius - c1.radius);
            p.y = (c2.radius*c1.center.y - c1.radius*c2.center.y) / (c2.radius - c1.radius);
            double d1 = norm(p,c1.center);
            Circle c = Circle(sqrt(d1*d1 - c1.radius*c1.radius),p,false);
            vector<Point> intersect;
            intersect = INTERSECTION_CIRCLE(c1,c);
            tangents.push_back(Line(p,intersect[0]));
            tangents.push_back(Line(p,intersect[1]));

            Point q;
            q.x = (c2.radius*c1.center.x + c1.radius*c2.center.x) / (c2.radius + c1.radius);
            q.y = (c2.radius*c1.center.y + c1.radius*c2.center.y) / (c2.radius + c1.radius);
            double d2 = norm(q,c1.center);
            Circle c = Circle(sqrt(d2*d2 - c1.radius*c1.radius),p,false);
            vector<Point> intersect2;
            intersect2 = INTERSECTION_CIRCLE(c1,c);
            tangents.push_back(Line(q,intersect2[0]));
            tangents.push_back(Line(q,intersect2[1]));
            return tangents;
        }

    }




// Old common tangent func
    // vector<class Line> COMMON_TANGENT(class Circle c1, class Circle c2)
    // {
    //    //Implement common tangents again..
    //     double d = sqrt(pow((c1.center.x - c2.center.x), 2) + pow((c1.center.y - c2.center.y), 2));
    //     vector<class Line> ans;

    //     class Point p, q, r, s;
    //     int flag = 0;

    //     p.x = (c1.radius * c2.center.x + c2.radius * c1.center.x) / (c1.radius + c2.radius);
    //     p.y = (c1.radius * c2.center.y + c2.radius * c1.center.y) / (c1.radius + c2.radius);
    //     if (c2.radius == c1.radius)
    //     {
    //         q.x = (c2.radius * c1.center.x - c1.radius * c2.center.x) / (c2.radius - c1.radius);
    //         q.y = (c2.radius * c1.center.y - c1.radius * c2.center.y) / (c2.radius - c1.radius);
    //         flag = 1;
    //     }

    //     double D1, D2;
    //     vector<double> m;
    //     D1 = pow((c1.center.x - p.x), 2) - 4 * (c1.radius) * (c1.radius) * (pow((c1.radius), 2) + c1.center.y - p.y);

    //     if (D1 == 0)
    //     {
    //         m.push_back((c1.center.x - p.x) / 2 * (c1.radius) * c1.radius);
    //         double y;
    //     }
    //     else if (D1 > 0)
    //     {
    //         m.push_back((c1.center.x - p.x + D1) / 2 * (c1.radius) * c1.radius);
    //         m.push_back((c1.center.x - p.x - D1) / 2 * (c1.radius) * c1.radius);
    //     }

    //     for (int i = 0; i < m.size(); i++)
    //     {
    //         r.x = 0;
    //         r.y = p.y - m[0] * p.x;
    //         class Line l;
    //         l = Line(p, r);
    //         ans.push_back(l);
    //     }
    //     m.clear();
    //     if (flag == 0)
    //     {
    //         D2 = pow((c1.center.x - q.x), 2) - 4 * (c1.radius) * (c1.radius) * (pow((c1.radius), 2) + c1.center.y - q.y);
    //         if (D2 == 0)
    //         {
    //             m.push_back((c1.center.x - q.x) / 2 * (c1.radius) * c1.radius);
    //         }
    //         else if (D2 > 0)
    //         {
    //             m.push_back((c1.center.x - q.x + D2) / 2 * (c1.radius) * c1.radius);
    //             m.push_back((c1.center.x - q.x - D2) / 2 * (c1.radius) * c1.radius);
    //         }

    //         for (int i = 0; i < m.size(); i++)
    //         {
    //             r.x = 0;
    //             r.y = q.y - m[0] * q.x;
    //             class Line l;
    //             l = Line(q, r);
    //             ans.push_back(l);

    //             return ans;
    //         }
    //     }
    //     else{
    //         double slope ;
    //         slope = (c2.center.y - c1.center.y)/(c2.center.x - c1.center.x);
    //         if( d == abs(c1.radius - c2.radius)){
    //            slope = -1/slope;
               
    //         }

    //     }
    // }