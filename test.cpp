#include<bits/stdc++.h>
using namespace std;

int main(){

    const char* translatedFilename = "translated.cpp";
    FILE* fout_translated = fopen(translatedFilename, "w");

    if (fout_translated == NULL)
    {
      fprintf(stderr, "%s file could not be opened\n", translatedFilename);
      exit(1);
    }
    deque <string> collection;
    collection.push_back("anshuu");
    collection.push_back("baby!!!");
    fprintf(fout_translated,"#include<iostream>\n");
    fprintf(fout_translated,"#include<vector>\n");
    fprintf(fout_translated,"#include<GL/glut.h>\n");
    fprintf(fout_translated,"#include<bits/stdc++.h>\n");
    fprintf(fout_translated,"#include<string>\n");
    fprintf(fout_translated,"#include<stdlib.h>\n");
    fprintf(fout_translated,"#include<math.h>\n");
    fprintf(fout_translated,"#include<deque>\n");
    fprintf(fout_translated,"#include \"standard_lib.hpp\" \n");
    fprintf(fout_translated,"using namespace std;\n \n");
    fprintf(fout_translated,"void initGL() { \n glClearColor(1.0f, 1.0f, 1.0f, 1.0f); \n } \n");
    fprintf(fout_translated,"int main(int argc, char** argv){\n");
    fprintf(fout_translated," glutInit(&argc, argv); \n glutInitWindowSize(640, 480); \n glutInitWindowPosition(50, 50);\n glutCreateWindow(\"Viewport Transform\"); \n glutDisplayFunc(display);\n glutReshapeFunc(reshape); \n initGL(); \n glutMainLoop();\n");
    for(int i=0;i<collection.size();i++){
       printf("%s\n",collection[i].c_str());
    }
    fprintf(fout_translated,"return 0\n } \n");


}

