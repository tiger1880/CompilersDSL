#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

const double PI = 3.14;
double height = 640, width = 480, axisLength = 11, aspectRatio = 1, xAxis = 10, yAxis = 10;

class Shape;

vector<Shape *> shapeStore;

class Shape
{

public:
    virtual bool getIs_show() = 0;
    virtual double AREA() = 0;
    virtual double PERIMETER() = 0;
    Shape()
    {
        ;
    }
    virtual void show() {}
};

// OPENGL --------------------------------------

void init()
{

    glClearColor(1.0, 1.0, 1.0, 1.0); // sets the background
    glPointSize(3);
}

void reshape(int w, int h)
{

    height = h; // zero height debug
    width = w;

    // viewport => only here inside the window things will be displayed
    glViewport(0, 0, w, h); // 0, 0 is the bottom-left of whole window

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    if (h == 0)
        h = 1;

    float aspect = (float)w / h;
    aspectRatio = aspect;

    // projection
    glMatrixMode(GL_PROJECTION); // for setting projection matrices
    glLoadIdentity();            // resets the axes

    // -10 to 10 right now

    // to prevent shape distortion on resizing window => just increases the coordinate axes
    if (w >= h)
    {
        gluOrtho2D(-axisLength * aspect, axisLength * aspect, -axisLength, axisLength); // left right bottom top

        xAxis = axisLength * aspect;
        yAxis = axisLength;
    }
    else
    {
        gluOrtho2D(-axisLength, axisLength, -axisLength / aspect, axisLength / aspect); // left right bottom top

        xAxis = axisLength;
        yAxis = axisLength / aspect;
    }

    glMatrixMode(GL_MODELVIEW); // always be in this mode
}

void renderBitmapString(float x, float y, const char *string)
{
    glRasterPos2f(x, y);

    for (const char *c = string; *c != '\0'; ++c)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

// OPENGL --------------------------------------

class Point : public Shape
{
public:
    double x;
    double y;
    string tag;
    bool is_show;
    double scale;
    double center_x;
    double center_y;

    Point()
    {
        scale = 1;
        center_x = 0;
        center_y = 0;
        tag = "";
        // cerr<< "constr 1: "<< shapeStore.size()<<" "<<this<<endl;
        // cerr<<x<<" "<<y<<endl;
        shapeStore.push_back(this);
    }

    Point(double a, double b, string s, double Scale, double cx, double cy)
    {
        scale = Scale;
        center_x = cx;
        center_y = cy;
        x = a;
        y = b;
        tag = s;
        is_show = true;
        // cerr<< "constr 2: "<< shapeStore.size()<<" "<<this<<endl;
        // cerr<<x<<" "<<y<<endl;
        shapeStore.push_back(this);
    }

    Point(double a, double b)
    {
        scale = 1;
        center_x = 0;
        center_y = 0;
        x = a;
        y = b;
        tag = "";
        is_show = true;
        // cerr<< "constr 3: "<< shapeStore.size()<<" "<<this<<endl;
        // cerr<<x<<" "<<y<<endl;
        shapeStore.push_back(this);
    }

    Point(double a, double b, bool sh)
    {
        scale = 1;
        center_x = 0;
        center_y = 0;
        x = a;
        y = b;
        tag = "";
        is_show = sh;
        // cerr<< "constr 4: "<< shapeStore.size()<<" "<<this<<endl;
        // cerr<<x<<" "<<y<<endl;
        shapeStore.push_back(this);
    }

    Point(double a, double b, string s, bool sh, double Scale, double cx, double cy)
    {
        scale = Scale;
        center_x = cx;
        center_y = cy;
        x = a;
        y = b;
        tag = s;
        is_show = sh;
        // cerr<< "constr 5: "<< shapeStore.size()<<" "<<this<<endl;
        // cerr<<x<<" "<<y<<endl;
        shapeStore.push_back(this);
    }

    Point(double a, double b, bool sh, double Scale, double cx, double cy)
    {
        scale = Scale;
        center_x = cx;
        center_y = cy;
        x = a;
        y = b;
        tag = "";
        is_show = sh;
        // cerr<< "constr 6: "<< shapeStore.size()<<" "<<this<<endl;
        // cerr<<x<<" "<<y<<endl;
        shapeStore.push_back(this);
    }

    Point(double a, double b, double Scale, double cx, double cy)
    {
        scale = Scale;
        center_x = cx;
        center_y = cy;
        x = a;
        y = b;
        tag = "";
        is_show = true;
        // cerr<< "constr 7: "<< shapeStore.size()<<" "<<this<<endl;
        // cerr << x << " " << y << endl;
        shapeStore.push_back(this);
    }

    void show()
    {

        glLoadIdentity();
        glTranslatef(center_x, center_y, 0.0f);
        glScalef(scale, scale, 0.0f);
        glColor3f(0.0, 0.0, 0.0);

        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
        renderBitmapString(x + 0.01, y + 0.01, tag.c_str());
        glLoadIdentity();
    }

    void printPoint()
    {

        cout << "--------------------------------------------------\n";
        cout << "x: " << x << "\n";
        cout << "y: " << y << "\n";
        cout << "tag: " << tag << "\n";
        cout << "scale: " << scale << "\n";
        cout << "center_x: " << center_x << "\n";
        cout << "center_y: " << center_y << "\n";
        cout << "is_show: " << is_show << "\n";
        cout << "--------------------------------------------------\n";
    }

    bool getIs_show()
    {
        return is_show;
    }

    double AREA() override
    {
        return 0;
    }

    double PERIMETER() override
    {
        return 0;
    }

    bool operator==(const Point &r)
    {

        if (r.x == x && r.y == y)
            return true;

        return false;
    }

    Point(const Point &p)
    {

        scale = p.scale;
        center_x = p.center_x;
        center_y = p.center_y;
        x = p.x;
        y = p.y;
        tag = p.tag;
        is_show = p.is_show;
    }

    Point &operator=(const Point &p)
    {

        scale = p.scale;
        center_x = p.center_x;
        center_y = p.center_y;
        x = p.x;
        y = p.y;
        tag = p.tag;
        is_show = p.is_show;

        return *this;
    }
};

double norm(Point *p1, Point *p2)
{
    double res = sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
    return res;
}

double norm(Point *p1)
{
    double res = sqrt(pow((p1->x), 2) + pow((p1->y), 2));
    return res;
}

double angleBetweenPoints(Point *p1, Point *p2, Point *p3, bool sh = true)
{
    double m1 = (p2->y - p1->y) / (p2->x - p1->x);
    double m2 = (p3->y - p2->y) / (p3->x - p2->x);

    double theta = atan((m2 - m1) / (1 + m1 * m2));

    theta = theta * 180.0 / M_PI;

    return theta;
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0.0, 0.0, 0.0);

    for (int i = 0; i < shapeStore.size(); i++)
    {
        // cerr<< "i: " << i<<" "<<shapeStore[i]<<endl;
        if (shapeStore[i]->getIs_show())
            shapeStore[i]->show();
    }
    // switch buffers
    glutSwapBuffers();
}

enum lineType
{
    SEGMENT,
    RAY,
    LINE
};

class Line : public Shape
{

    // if both points are same then shows a point
    Point a;
    Point b;
    bool is_show;

    // y = mx+c
    double m;
    double c;

    lineType t;   // RAY, LINE, SEGMENT
    double angle; // clockwise angle in degrees

    // figures
    double scale;
    Point center;

    double R(bool positive, Point initial, Point final)
    {

        double r, r1, r2;
        if (positive)
        {

            r1 = (yAxis - abs(final.y)) / sin(angle * PI / 180);
            r2 = (xAxis - abs(final.x)) / cos(angle * PI / 180);

            r1 = abs(r1);
            r2 = abs(r2);
            r = min(r1, r2) - 1;

            return r;
        }
        else
        {

            r1 = (abs(b.y) - yAxis) / sin(angle * PI / 180);
            r2 = (abs(b.x) - xAxis) / cos(angle * PI / 180);

            r1 = abs(r1);
            r2 = abs(r2);

            r = min(r1, r2) - 1;

            return r;
        }
    }

public:
    Line()
    {
        shapeStore.push_back(this);
    }

    Line(Point *x1, Point *x2, lineType type = SEGMENT, Point *Center = new Point(0, 0, false), double Scale = 1.0) : a(*x1),
                                                                                                                      b(*x2),
                                                                                                                      t(type),
                                                                                                                      is_show(true),
                                                                                                                      m(0),
                                                                                                                      c(0),
                                                                                                                      scale(Scale),
                                                                                                                      center(*Center)
    {

        shapeStore.push_back(this);

        if (x1->x == x2->x)
        {
            angle = 90.0;
        }
        else
        {
            angle = atan((x2->y - x1->y) / (x2->x - x1->x)) * 180 / PI;
        }

        if (angle < 0)
            angle += 180;

        if (angle != 90)
        {
            m = (b.y - a.y) / (b.x - a.x);
            c = b.y - m * b.x;
        }
    }

    // m, c constructor
    // y = mx + c
    Line(double m1, double c1, bool sh = false, Point *Center = new Point(0, 0, false), double Scale = 1.0) : m(m1),
                                                                                                              c(c1),
                                                                                                              is_show(sh),
                                                                                                              scale(Scale),
                                                                                                              center(*Center)
    {

        // (0, c), (1, m+c) taken as points

        a.x = 0;
        a.y = c;

        b.x = 1;
        b.y = m + c;

        angle = atan(m1) * 180 / PI;
        is_show = true;
        t = LINE;

        shapeStore.push_back(this);
    }

    // Copy Constructor
    Line(const Line &l)
    {
        a = l.a;
        b = l.b;
        is_show = l.is_show; // if its true already pushed
        angle = l.angle;
        c = l.c;
        m = l.m;
        t = l.t;
    }

    // copy assignment operator
    Line &operator=(const Line &l)
    {

        a = l.a;
        b = l.b;
        is_show = l.is_show; // if its true already pushed
        angle = l.angle;
        c = l.c;
        m = l.m;
        t = l.t;

        return *this;
    }

    void printEquation()
    {

        cout << "m: " << m << endl;
        cout << "c: " << c << endl;
        cout << "angle: " << angle << endl;
    }

    void setDisplay(bool d)
    {

        is_show = d;
        return;
    }

    void showSegment()
    {

        glTranslatef(center.x, center.y, 0.0f);
        glScalef(scale, scale, 0.0f);
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex2d(a.x, a.y);
        glVertex2d(b.x, b.y);
        glEnd();
        glLoadIdentity();
    }

    void showRay()
    {

        // 1/2 diagnol of unit length box
        double arrowLength = width / (2 * (1.14) * xAxis);

        double xFinal, yFinal;

        double r, rx, ry;

        if (a == b)
        {
            xFinal = b.x;
            yFinal = b.y;
        }
        else
        {

            r = (b.x - a.x) / cos(angle * PI / 180);

            if (r > 0)
            {

                if (b.x - a.x > 0)
                {

                    r = (xAxis - a.x) / cos(angle * PI / 180);
                }
                else
                {

                    r = (-xAxis - a.x) / cos(angle * PI / 180);
                }

                rx = r;

                if (b.y - a.y > 0)
                {
                    r = (yAxis - a.y) / sin(angle * PI / 180);
                }
                else
                {
                    r = (-yAxis - a.y) / sin(angle * PI / 180);
                }

                ry = r;

                r = abs(min(rx, ry));

                if (r >= norm(&a, &b) + 1)
                    r = abs(r - 1);

                xFinal = a.x + r * cos(angle * PI / 180);
                yFinal = a.y + r * sin(angle * PI / 180);
            }
            else
            {

                if (b.x - a.x > 0)
                {

                    r = (a.x - xAxis) / cos(angle * PI / 180);
                }
                else
                {

                    r = (xAxis + a.x) / cos(angle * PI / 180);
                }

                rx = r;

                if (b.y - a.y > 0)
                {
                    r = (-yAxis + a.y) / sin(angle * PI / 180);
                }
                else
                {
                    r = (yAxis + a.y) / sin(angle * PI / 180);
                }

                ry = r;

                r = abs(min(rx, ry));

                if (r >= norm(&a, &b) + 1)
                    r = abs(r - 1);

                xFinal = a.x - r * cos(angle * PI / 180);
                yFinal = a.y - r * sin(angle * PI / 180);
            }
        }

        glTranslatef(center.x, center.y, 0.0f);
        glScalef(scale, scale, 0.0f);
        glColor3f(0.0, 0.0, 0.0);

        glBegin(GL_POINTS);
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

    void showLine()
    {

        double r, rx, ry, xFinal1, yFinal1, xFinal2, yFinal2;

        if (a == b)
        {
            xFinal1 = b.x;
            yFinal1 = b.y;
            xFinal2 = a.x;
            yFinal2 = a.y;
        }
        else
        {

            r = (b.x - a.x) / cos(angle * PI / 180);

            if (r > 0)
            {

                if (b.x - a.x > 0)
                {

                    r = (xAxis - a.x) / cos(angle * PI / 180);
                }
                else
                {

                    r = (-xAxis - a.x) / cos(angle * PI / 180);
                }

                rx = r;

                if (b.y - a.y > 0)
                {
                    r = (yAxis - a.y) / sin(angle * PI / 180);
                }
                else
                {
                    r = (-yAxis - a.y) / sin(angle * PI / 180);
                }

                ry = r;

                r = abs(min(rx, ry));

                if (r >= norm(&a, &b) + 1)
                    r = abs(r - 1);

                xFinal1 = a.x + r * cos(angle * PI / 180);
                yFinal1 = a.y + r * sin(angle * PI / 180);
            }
            else
            {

                if (b.x - a.x > 0)
                {

                    r = (a.x - xAxis) / cos(angle * PI / 180);
                }
                else
                {

                    r = (xAxis + a.x) / cos(angle * PI / 180);
                }

                rx = r;

                if (b.y - a.y > 0)
                {
                    r = (-yAxis + a.y) / sin(angle * PI / 180);
                }
                else
                {
                    r = (yAxis + a.y) / sin(angle * PI / 180);
                }

                ry = r;

                r = abs(min(rx, ry));

                if (r >= norm(&a, &b) + 1)
                    r = abs(r - 1);

                xFinal1 = a.x - r * cos(angle * PI / 180);
                yFinal1 = a.y - r * sin(angle * PI / 180);
            }

            swap(a.x, b.x);
            swap(a.y, b.y);

            r = (b.x - a.x) / cos(angle * PI / 180);

            if (r > 0)
            {

                if (b.x - a.x > 0)
                {

                    r = (xAxis - a.x) / cos(angle * PI / 180);
                }
                else
                {

                    r = (-xAxis - a.x) / cos(angle * PI / 180);
                }

                rx = r;

                if (b.y - a.y > 0)
                {
                    r = (yAxis - a.y) / sin(angle * PI / 180);
                }
                else
                {
                    r = (-yAxis - a.y) / sin(angle * PI / 180);
                }

                ry = r;

                r = abs(min(rx, ry));

                if (r >= norm(&a, &b) + 1)
                    r = abs(r - 1);

                xFinal2 = a.x + r * cos(angle * PI / 180);
                yFinal2 = a.y + r * sin(angle * PI / 180);
            }
            else
            {

                if (b.x - a.x > 0)
                {

                    r = (a.x - xAxis) / cos(angle * PI / 180);
                }
                else
                {

                    r = (xAxis + a.x) / cos(angle * PI / 180);
                }

                rx = r;

                if (b.y - a.y > 0)
                {
                    r = (-yAxis + a.y) / sin(angle * PI / 180);
                }
                else
                {
                    r = (yAxis + a.y) / sin(angle * PI / 180);
                }

                ry = r;

                r = abs(min(rx, ry));

                if (r >= norm(&a, &b) + 1)
                    r = abs(r - 1);

                xFinal2 = a.x - r * cos(angle * PI / 180);
                yFinal2 = a.y - r * sin(angle * PI / 180);
            }

            swap(a.x, b.x);
            swap(a.y, b.y);
        }

        glTranslatef(center.x, center.y, 0.0f);
        glScalef(scale, scale, 0.0f);
        glColor3f(0.0, 0.0, 0.0);

        glBegin(GL_POINTS);
        glVertex2f(a.x, a.y);
        glVertex2f(b.x, b.y);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xFinal1, yFinal1);
        glVertex2f(xFinal2, yFinal2);
        glEnd();

        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        glVertex2f(xFinal1, yFinal1);
        glVertex2f(xFinal2, yFinal2);
        glEnd();

        glLoadIdentity();
        glColor3f(0.0, 0.0, 0.0);
    }

    void show()
    {

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

    bool getIs_show()
    {
        return is_show;
    }

    friend Point *INTERSECTION(Line *l1, Line *l2);
    friend Line *LINE_AT_ANGLE(double a, Line *l, Point *p);
    friend Line *ANGLE_BISECTOR(Line *a, Line *b); // returns 1x2 array of lines
    friend bool isPerpendicular(Line *l1, Line *l2);
    friend bool isParallel(Line *l1, Line *l2);
    friend double SHORTEST_DISTANCE(Line *l1, Line *l2);

    Point *MIDPOINT_LINE()
    {

        if (t != SEGMENT)
            return &b;

        Point *p = new Point((a.x + b.x) / 2, (a.y + b.y) / 2);

        return p;
    }

    bool passesThrough(Point *p)
    {

        if (angle == 90)
        {

            if (p->x == a.x)
                return true;
            return false;
        }

        if (p->y == (m * p->x + c))
            return true;

        return false;
    }

    double AREA() override
    {
        return 0;
    }

    double PERIMETER() override
    {
        return 0;
    }
};

Point *rotatePoint(Point *point, Point *center, double theta)
{
    double x = center->x + (point->x - center->x) * std::cos(theta) - (point->y - center->y) * std::sin(theta);
    double y = center->y + (point->x - center->x) * std::sin(theta) + (point->y - center->y) * std::cos(theta);
    return new Point(x, y);
}

Line *LINE_AT_ANGLE(double a, Line *l, Point *p)
{

    if (!l->passesThrough(p))
    {

        cout << "LINE_AT_ANGLE: p doesn't pass through l\n";
        return l;
    }

    Point *rotatePoint1 = new Point(0, 0, false);
    Point *rotatePoint2 = new Point(0, 0, false);

    while (a >= 180)
        a -= 180;

    rotatePoint1 = rotatePoint(&l->a, p, a * PI / 180);
    rotatePoint2 = rotatePoint(&l->b, p, a * PI / 180);

    Line *l1 = new Line(rotatePoint1, rotatePoint2, LINE); // defaulting it LINE

    return l1;
}

Point *INTERSECTION(Line *l1, Line *l2)
{

    if (l1->m == l2->m)
    {
        cout << "Do not intersect parallel"
             << "\n";
        return &l1->a;
    }

    Point *p = new Point(0.0, 0.0, 1.0, 0, 0);

    if (l1->angle == 90)
    {
        p->x = l1->a.x;
        p->y = l2->m * p->x + l2->c;

        return p;
    }

    if (l2->angle == 90)
    {
        p->x = l2->a.x;
        p->y = l1->m * p->x + l1->c;

        return p;
    }

    p->x = (l2->c - l1->c) / (l1->m - l2->m);
    p->y = l1->m * p->x + l1->c;

    return p;
}

Line *ANGLE_BISECTOR(Line *a, Line *b)
{

    Line *x = new Line[2];

    if (a->angle == 90 && b->angle == 90)
    {

        cout << "Parallel lines cannot have angle bisectors\n";
        return x;
    }

    Line *l1, *l2;
    double d1 = pow(1 + a->m * a->m, 0.5);
    double d2 = pow(1 + b->m * b->m, 0.5);

    if (a->angle == 90)
    {

        l1 = new Line(b->m - d2, b->c + a->a.x * d2, true);
        l2 = new Line(b->m + d2, b->c - a->a.x * d2, true);

        x[0] = *l1;
        x[1] = *l2;

        return x;
    }
    else if (b->angle == 90)
    {

        l1 = new Line(a->m - d1, a->c + b->a.x * d1, true);
        l2 = new Line(a->m + d1, a->c - b->a.x * d1, true);

        x[0] = *l1;
        x[1] = *l2;

        return x;
    }

    if (a->m == b->m)
    {
        a->printEquation();
        b->printEquation();
        cout << "Parallel lines cannot have angle bisectors\n";
        return x;
    }

    if (d1 == d2)
    {
        l1 = new Line(new Point(0, 0), new Point(0, 5));
        l2 = new Line(0.0, 0.0, true);
    }
    else
    {
        l1 = new Line((a->m * d2 - b->m * d1) / (d2 - d1), (a->c * d2 - b->c * d1) / (d2 - d1), true);
        l2 = new Line((a->m * d2 + b->m * d1) / (d2 + d1), (a->c * d2 + b->c * d1) / (d2 + d1), true);
    }

    x[0] = *l1;
    x[1] = *l2;

    return x;
}

double SHORTEST_DISTANCE(Line *l1, Line *l2)
{

    if (l1->m == l2->m)
        return 0;

    return abs(l1->c - l2->c) / pow(1 + l1->m * l1->m, 0.5);
}

bool isPerpendicular(Line *l1, Line *l2)
{
    if (l1->m * l2->m == -1)
        return true;
    return false;
}

// upgrade
bool isParallel(Line *l1, Line *l2)
{
    if (l1->m == l2->m)
        return true;

    return false;
}

class Tri : public Shape
{
public:
    Point p1;
    Point p2;
    Point p3;
    bool is_show;
    double scale;
    Point center;

    Tri()
    {
        scale = 1;
        center = *(new Point(0, 0, false));
    }

    Tri(Point *point1, Point *point2, Point *point3, Point *Center = new Point(0, 0, false), double Scale = 1.0)
    {

        p1 = *point1;
        p2 = *point2;
        p3 = *point3;

        is_show = true;
        scale = Scale;
        center = *Center;

        // cerr << this << " " << shapeStore.size() << "\n";
        shapeStore.push_back(this);
    }

    Tri(Point *point1, Point *point2, Point *point3, bool sh, Point Center = Point(0, 0, false), double Scale = 1.0)
    {
        p1 = *point1;
        p2 = *point2;
        p3 = *point3;
        is_show = sh;
        scale = Scale;
        center = Center;
        shapeStore.push_back(this);
    }

    Tri(double s1, double s2, double s3, Point *Center = new Point(0, 0, false), double Scale = 1.0)
    {
        p1.x = 0;
        p2.x = 0;
        p2.x = s1;
        p2.y = 0;
        double a = (s2 * s2 + s1 * s1 - s3 * s3) / (2 * s1);
        double b = sqrt(s2 * s2 - a * a);
        p3.x = a;
        p3.y = b;
        is_show = true;
        center = *Center;
        scale = Scale;
        shapeStore.push_back(this);
    }

    Tri(double s1, double s2, double s3, bool sh, Point *Center = new Point(0, 0, false), double Scale = 1.0)
    {
        p1.x = 0;
        p2.x = 0;
        p2.x = s1;
        p2.y = 0;
        double a = (s2 * s2 + s1 * s1 - s3 * s3) / (2 * s1);
        double b = sqrt(s2 * s2 - a * a);
        p3.x = a;
        p3.y = b;
        is_show = sh;
        center = *Center;
        scale = Scale;
        shapeStore.push_back(this);
    }

    Tri(double h, double s, Point *Center = new Point(0, 0, false), double Scale = 1.0)
    {
        p1.x = 0;
        p2.x = 0;
        p2.x = s;
        p2.y = 0;
        p3.x = 0;
        p3.y = sqrt(h * h - s * s);
        center = *Center;
        is_show = true;
        scale = Scale;

        shapeStore.push_back(this);
    }

    // Tri(double h, double s, Point *Center = new Point(0, 0, false),double scale = 1.0,bool sh)
    // {
    //     p1 = Point(0, 0);
    //     p2 = Point(s, 0);
    //     p3 = Point(0, sqrt(h * h - s * s));
    //     center = *Center;
    //     is_show = sh;

    //     shapeStore.push_back(this);

    // }

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
        glTranslatef(-center.x, -center.y, 0.0f);
        glScalef((1.0 / scale), (1.0 / scale), 0.0f);
    }

    bool getIs_show()
    {
        return is_show;
    }

    Point* getPoint1() {
        return &this->p1;
    }

    Point* getPoint2() {
        return &this->p2;
    }

    Point* getPoint3() {
        return &this->p3;
    }



    Point *CIRCUMCENTER()
    {
        double a = (p1.y * p1.y + p2.x * p3.x) * (p2.x - p3.x) + (p2.y * p2.y + p3.x * p1.x) * (p3.x - p1.x) + (p3.y * p3.y + p1.x * p2.x) * (p1.x - p2.x);
        double b = (p1.x * p1.x + p2.y * p3.y) * (p2.y - p3.y) + (p2.x * p2.x + p3.y * p1.y) * (p3.y - p1.y) + (p3.x * p3.x + p1.y * p2.y) * (p1.y - p2.y);
        double c = p2.y * (p3.x - p1.x) - p2.x * (p3.y - p1.y) - (p1.y * p3.x - p3.y * p1.x);
        double k = a / (2 * c);
        double h = -b / (2 * c);

        return new Point(h, k);
    }

    Point *CENTROID()
    {
        Point *g = new Point((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3);
        return g;
    }

    Point *ORTHOCENTER()
    {
        Point *o = CIRCUMCENTER();
        Point *g = CENTROID();
        Point *h = new Point(3 * g->x - 2 * o->x, 3 * g->y - 2 * o->y);

        return h;
    }

    Point *EXCENTER(Point *p)
    {
        Line *a = new Line(&p1, &p2);
        Line *b = new Line(&p2, &p3);
        Line *c = new Line(&p3, &p1);

        a->setDisplay(false);
        b->setDisplay(false);
        c->setDisplay(false);

        Line *l1;
        Line *l2;
        Line *l3;

        l1 = ANGLE_BISECTOR(a, b);
        l2 = ANGLE_BISECTOR(b, c);
        l3 = ANGLE_BISECTOR(c, a);

        // cout<<p->x<<" "<<p->y<<endl;
        // cout<<p1.x<<" "<<p1.y<<endl;
        // cout<<p2.x<<" "<<p2.y<<endl;
        // cout<<p3.x<<" "<<p3.y<<endl;

        Point *q;

        if (p1.x == p->x && p1.y == p->y)
        {

            return INTERSECTION(&l2[1], &l3[1]); // Assuming 1st index will give external angle bisector
        }
        else if (p2.x == p->x && p2.y == p->y)
        {

            return INTERSECTION(&l3[1], &l1[1]);
        }
        else if (p3.x == p->x && p3.y == p->y)
        {

            return INTERSECTION(&l1[1], &l2[1]);
        }
        else
        {
            return q;
        }
    }

    Point *INCENTER()
    {
        Line *a = new Line(&p1, &p2);
        Line *b = new Line(&p2, &p3);
        Line *c = new Line(&p3, &p1);

        a->setDisplay(false);
        b->setDisplay(false);
        c->setDisplay(false);

        Line *l1;
        Line *l2;
        l1 = ANGLE_BISECTOR(a, b);
        l2 = ANGLE_BISECTOR(b, c);
        Point *i = INTERSECTION(&l1[0], &l2[0]); // Assuming 1st angle bisector is internal angle bisector

        return i;
    }

    Line *MEDIAN(Point *p)
    {
        Point *q;
        if (p1.x == p->x && p1.y == p->y)
        {
            q = new Point((p2.x + p3.x) / 2, (p2.y + p3.y) / 2);
            return new Line(p, q);
        }
        else if (p2.x == p->x && p2.y == p->y)
        {
            q = new Point((p1.x + p3.x) / 2, (p1.y + p3.y) / 2);
            return new Line(p, q);
        }
        else if (p3.x == p->x && p3.y == p->y)
        {
            q = new Point((p2.x + p1.x) / 2, (p2.y + p1.y) / 2);
            return new Line(p, q);
        }
        else
        {
            return new Line();
        }
    }

    Line *
    ALTITUDE(Point *p)
    {
        Point *q;
        if (p1.x == p->x && p1.y == p->y)
        {
            double c = (p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y);
            double a = (p2.x - p3.x) * (p2.x - p3.x) * p1.x + (p2.y - p3.y) * (p2.y - p3.y) * p2.x + (p1.y - p2.y) * (p2.y - p3.y) * (p2.x - p3.x);
            double b = (p2.x - p3.x) * (p2.x - p3.x) * p2.y + (p2.y - p3.y) * (p2.y - p3.y) * p1.y + (p1.x - p2.x) * (p2.y - p3.y) * (p2.x - p3.x);
            q = new Point(a / c, b / c);
            return new Line(p, q);
        }
        else if (p2.x == p->x && p2.y == p->y)
        {
            double c = (p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y);
            double a = (p3.x - p1.x) * (p3.x - p1.x) * p2.x + (p3.y - p1.y) * (p3.y - p1.y) * p3.x + (p2.y - p3.y) * (p3.y - p1.y) * (p3.x - p1.x);
            double b = (p3.x - p1.x) * (p3.x - p1.x) * p3.y + (p3.y - p1.y) * (p3.y - p1.y) * p2.y + (p2.x - p3.x) * (p3.y - p1.y) * (p3.x - p1.x);
            q = new Point(a / c, b / c);
            return new Line(p, q);
        }
        else if (p3.x == p->x && p3.y == p->y)
        {
            double c = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
            double a = (p1.x - p2.x) * (p1.x - p2.x) * p3.x + (p1.y - p2.y) * (p1.y - p2.y) * p1.x + (p3.y - p1.y) * (p1.y - p2.y) * (p1.x - p2.x);
            double b = (p1.x - p2.x) * (p1.x - p2.x) * p1.y + (p1.y - p2.y) * (p1.y - p2.y) * p3.y + (p3.x - p1.x) * (p1.y - p2.y) * (p1.x - p2.x);
            q = new Point(a / c, b / c);
            return new Line(p, q);
        }
        else
        {
            return new Line();
        }
    }

    double AREA() override
    {
        double area;
        area = abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2;

        return area;
    }

    double PERIMETER() override
    {
        return norm(&p1, &p2) + norm(&p2, &p3) + norm(&p3, &p1);
    }
};

class Circle : public Shape
{
public:
    float radius;
    Point ctr;
    Point figCenter;
    double scale;
    bool is_show;

    Circle(float radius, Point *Center, Point *fcenter = new Point(0, 0, false), double Scale = 1.0)
    {
        this->radius = radius;
        scale = Scale;
        ctr = *Center;
        figCenter = *fcenter;
        is_show = true;
        shapeStore.push_back(this);
    }

    Circle(float radius, Point *Center, bool sh, Point *fcenter = new Point(0, 0, false), double Scale = 1.0)
    {
        this->radius = radius;
        scale = Scale;
        ctr = *Center;
        figCenter = *fcenter;
        is_show = sh;
        shapeStore.push_back(this);
    }

    void show()
    {
        glScalef(scale, scale, 0.0f);
        glTranslatef(figCenter.x, figCenter.y, 0.0f);

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // Blue
        GLfloat angle;
        for (int i = 0; i <= 360; i++)
        {
            angle = i * PI / 180; // 360 deg for all segments
            glVertex2f(cos(angle) * radius, sin(angle) * radius);
        }
        glEnd();

        // glLoadIdentity();
        glTranslatef(-figCenter.x, -figCenter.y, 0.0f);
        glScalef((1.0/scale), (1.0/scale), 0.0f);

    }

    bool getIs_show()
    {
        return is_show;
    }

    Point* getCenter() {
        return &this->ctr;
    }

    Line* TANGENT(Point *q)
    {
        double m;
        m = (ctr.y - q->y) / (ctr.x - q->x);
        Line *l;
        l = new Line(-(1 / m), q->y + (1 / m) * q->x);
        return l;
    }

    double AREA()
    {
        return 3.14 * radius * radius;
    }

    // Here PERIMETER means circumference
    double PERIMETER()
    {
        return 2 * 3.14 * radius;
    }
};

class Para : public Shape
{
public:
    Point p1; // p1,p2,p3,p4 are attributes
    Point p2;
    Point p3;
    Point p4;
    double scale;
    Point center;
    bool is_show;

    Para(double s1, double ang, double s2, Point *Center = new Point(0, 0, false), double Scale = 1.0)
    {

        p1.x = 0;
        p1.y = 0;
        p2.x = s1;
        p2.y = 0;
        p3.x = s2 * cos(ang) + s1;
        p3.y = s2 * sin(ang);
        p4.x = s2 * cos(ang);
        p4.y = s2 * sin(ang);
        is_show = true;
        center = *Center;
        scale = Scale;
        shapeStore.push_back(this);
    }

    Para(double s1, double ang, double s2, bool sh, Point *Center = new Point(0, 0, false), double Scale = 1.0)
    {

        p1.x = 0;
        p1.y = 0;
        p2.x = s1;
        p2.y = 0;
        p3.x = s2 * cos(ang) + s1;
        p3.y = s2 * sin(ang);
        p4.x = s2 * cos(ang);
        p4.y = s2 * sin(ang);
        is_show = sh;
        center = *Center;
        scale = Scale;
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
        glVertex2d(p4.x, p4.y);
        glEnd();
        // glLoadIdentity();
        glTranslatef(-center.x, -center.y, 0.0f);
        glScalef((1.0 / scale), (1.0 / scale), 0.0f);
    }

    bool getIs_show()
    {
        return is_show;
    }

    Line **DIAGONAL()
    {

        Line **diagonals = new Line *[2]; // free

        diagonals[0] = new Line(&p1, &p3);
        diagonals[1] = new Line(&p2, &p4);

        return diagonals;
    }

    double AREA() override
    {
        double s1 = norm(&p1, &p2);
        double s2 = norm(&p2, &p3);
        double angle = angleBetweenPoints(&p1, &p2, &p3);
        return s1 * s2 * sin(angle);
    }

    double PERIMETER() override
    {
        double s1 = norm(&p1, &p2);
        double s2 = norm(&p2, &p3);
        return 2 * (s1 + s2);
    }
};

class RegPoly : public Shape
{
public:
    int numOfSides;
    double sideLength;
    double scale;
    Point center;
    bool is_show;

    RegPoly(int numOfSides, double sideLength, bool sh, Point *Center = new Point(0, 0, false), double Scale = 1.0)
    {
        scale = Scale;
        center = *Center;
        this->numOfSides = numOfSides;
        this->sideLength = sideLength;
        is_show = sh;
        shapeStore.push_back(this);
    }

    RegPoly(int numOfSides, double sideLength, Point *Center = new Point(0, 0, false), double Scale = 1.0)
    {
        scale = Scale;
        center = *Center;
        this->numOfSides = numOfSides;
        this->sideLength = sideLength;
        is_show = true;
        shapeStore.push_back(this);
    }

    void show()
    {

        glTranslatef(center.x, center.y, 0.0f);
        glScalef(scale, scale, 0.0f);
        glColor3f(0.0, 0.0, 0.0);

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // Yellow

        GLfloat angle = 0;
        for (int i = 0; i < numOfSides; i++)
        {
            glVertex2f(sideLength * cos(angle), sideLength * sin(angle));
            angle += (PI / 180) * (360 / numOfSides);
        }
        glEnd();

        // glLoadIdentity();
        glTranslatef(-center.x, -center.y, 0.0f);
        glScalef((1.0 / scale), (1.0 / scale), 0.0f);
    }

    bool getIs_show()
    {
        return is_show;
    }

    double AREA()
    {
        return ((numOfSides * sideLength * sideLength) / (4 * tan(PI / numOfSides)));
    }

    double PERIMETER()
    {
        return numOfSides * sideLength;
    }
};


//Non-memeber functions
Point*
    INTERSECTION_CIRCLE(Circle *c1, Circle *c2)
    {
        Point* p = NULL;
        // Finding quadratic equation and then sove it.
        double d = norm(&c1->ctr,&c2->ctr);
        if (d > c1->radius + c2->radius)
            return p;
        if (d < abs(c1->radius - c2->radius))
            return p;
        if (d == 0 && (c1->radius - c2->radius) == 0)
            return p;
        double c, k;
        c = (c1->radius * c1->radius - (c2->radius * c2->radius) + (c2->ctr.x * c2->ctr.x + c2->ctr.y * c2->ctr.y) - (c1->ctr.x * c1->ctr.x + c1->ctr.y * c1->ctr.y)) / (2 * (c2->ctr.x - c1->ctr.x));
        k = (c1->ctr.y - c2->ctr.y) / (c2->ctr.x - c1->ctr.x);
        double D = (pow((2 * c * k - 2 * c1->ctr.x * k - 2 * c1->ctr.y), 2)) - 4 * (k * k + 1) * (c1->ctr.x * c1->ctr.x + c1->ctr.y * c1->ctr.y + c * c - c1->radius * c1->radius - 2 * c * c1->radius);
        
        if (D == 0)
        {   
            p = new Point[1];
            p[0].y = -1 * (pow((2 * c * k - 2 * c1->ctr.x * k - 2 * c1->ctr.y), 2) / 2 * (k * k + 1));
            p[0].x = k * p[0].y + c;
        }
        else
        {
            
            p = new Point[2];
            p[0].y = -1 * (pow((2 * c * k - 2 * c1->ctr.x * k - 2 * c1->ctr.y), 2) / 2 * (k * k + 1)) + sqrt(D);
            p[1].y =  1 * (pow((2 * c * k - 2 * c1->ctr.x * k - 2 * c1->ctr.y), 2) / 2 * (k * k + 1)) + sqrt(D);
            p[0].x = k * p[0].y + c;
            p[1].x = k * p[1].y + c;

        }

    return p;
}

// vector<class Line> COMMON_TANGENT(Circle *c1,Circle *c2) {
//     vector<Line> *tangents;
//     double c1c2 = norm(c1->center,c2->center);

//     if(c1c2 < abs(c1->radius - c2->radius)) {
//         return *tangents;
//     }

//     else if( c1c2 == abs(c1->radius - c2->radius)) {
//         vector<Point> intersect;
//         intersect = INTERSECTION_CIRCLE(c1,c2);
//         Line *l = c1->TANGENT(&intersect[0]);
//         tangents->push_back(*l);
//         return *tangents;
//     }

//     else if(c1c2 > abs(c1->radius - c2->radius) && c1c2 < c1->radius + c2->radius) {
//         Point *p;
//         p->x = (c2->radius*c1->center.x - c1->radius*c2->center.x) / (c2->radius - c1->radius);
//         p->y = (c2->radius*c1->center.y - c1->radius*c2->center.y) / (c2->radius - c1->radius);
//         double d1 = norm(p,c1->center);
//         Circle *c = new Circle(sqrt(d1*d1 - c1->radius*c1->radius),*p,false);
//         vector<Point> intersect;
//         intersect = INTERSECTION_CIRCLE(*c1,*c);
//         tangents->push_back(Line(p,intersect[0]));
//         tangents->push_back(Line(p,intersect[1]));
//         return tangents;
//     }

//     else if(c1c2 == c1.radius + c2.radius) {
//         vector<Point> intersect;
//         intersect = INTERSECTION_CIRCLE(c1,c2);
//         Line l = c1.TANGENT(intersect[0]);
//         tangents.push_back(l);

//         Point p;
//         p.x = (c2.radius*c1.center.x - c1.radius*c2.center.x) / (c2.radius - c1.radius);
//         p.y = (c2.radius*c1.center.y - c1.radius*c2.center.y) / (c2.radius - c1.radius);
//         double d1 = norm(p,c1.center);
//         Circle c = Circle(sqrt(d1*d1 - c1.radius*c1.radius),p,false);
//         vector<Point> intersect2;
//         intersect2 = INTERSECTION_CIRCLE(c1,c);
//         tangents.push_back(Line(p,intersect2[0]));
//         tangents.push_back(Line(p,intersect2[1]));
//         return tangents;
//     }

//     else if(c1c2 > c1.radius + c2.radius) {
//         Point p;
//         p.x = (c2.radius*c1.center.x - c1.radius*c2.center.x) / (c2.radius - c1.radius);
//         p.y = (c2.radius*c1.center.y - c1.radius*c2.center.y) / (c2.radius - c1.radius);
//         double d1 = norm(p,c1.center);
//         Circle c = Circle(sqrt(d1*d1 - c1.radius*c1.radius),p,false);
//         vector<Point> intersect;
//         intersect = INTERSECTION_CIRCLE(c1,c);
//         tangents.push_back(Line(p,intersect[0]));
//         tangents.push_back(Line(p,intersect[1]));

//         Point q;
//         q.x = (c2.radius*c1.center.x + c1.radius*c2.center.x) / (c2.radius + c1.radius);
//         q.y = (c2.radius*c1.center.y + c1.radius*c2.center.y) / (c2.radius + c1.radius);
//         double d2 = norm(q,c1.center);
//         Circle c_ = Circle(sqrt(d2*d2 - c1.radius*c1.radius),p,false);
//         vector<Point> intersect2;
//         intersect2 = INTERSECTION_CIRCLE(c1,c_);
//         tangents.push_back(Line(q,intersect2[0]));
//         tangents.push_back(Line(q,intersect2[1]));
//         return tangents;
//     }

//     return tangents;

// }