#!/bin/bash
FILENAME=$1

# g++  -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl test.cpp
#g++  -lGL -lGLU -lglut $FILENAME 
 g++ $FILENAME glad.c  -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lGLU -lglut
./a.out