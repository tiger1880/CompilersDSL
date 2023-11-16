#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <map>

using namespace std;

class Shapes{

public:
string label;
virtual void  Area()=0;
virtual void Perimeter()=0;

};

class Point:public Shapes{

};

class Line:public Shapes{

};

class Tri:public Shapes{

};

class Circle:public Shapes{

};

class Para:public Shapes{

};

class RegPoly:public Shapes{

};