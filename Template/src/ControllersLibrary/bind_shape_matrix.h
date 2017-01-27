#ifndef BIND_SHAPE_MATRIX_H
#define BIND_SHAPE_MATRIX_H
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Bind_Shape_Matrix
{
public:
    Bind_Shape_Matrix();
    void readDataFrom(TiXmlElement *src);

    float *m_Floats;
private:
    float *getFloats(string values);
};

#endif // BIND_SHAPE_MATRIX_H
