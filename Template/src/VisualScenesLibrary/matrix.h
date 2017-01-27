#ifndef MATRIX_H
#define MATRIX_H
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <strstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Matrix
{
public:
    Matrix();
    void readDataFrom(TiXmlElement *src);
    float* m_Values;

private:
    float *getFloats(string values);
};

#endif // MATRIX_H
