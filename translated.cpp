#include<iostream>
#include<vector>
#include<GL/glut.h>
#include<bits/stdc++.h>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<deque>
#include "standard_lib.hpp" 
using namespace std;
 
void initGL() { 
 glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
 } 
int main(int argc, char** argv){
 glutInit(&argc, argv); 
   glutInitWindowSize(640, 480); 
 glutInitWindowPosition(50, 50);
 glutCreateWindow("Viewport Transform"); 
 glutDisplayFunc(display);
 glutReshapeFunc(reshape); 
 initGL(); 
 glutMainLoop();
return 0
 } 
