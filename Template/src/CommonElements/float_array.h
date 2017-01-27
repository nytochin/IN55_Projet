#ifndef FLOAT_ARRAY_H
#define FLOAT_ARRAY_H
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <string>
#include <iostream>
#include <vector>
#include "Matrices.h"
using namespace std;

class Float_Array
{
public:
    Float_Array();
    void readDataFrom(TiXmlElement *src);
    vector<Vector4> readVectors();
    vector<Matrix4> readMatrices();
    Matrix4 readMatrixAt(int matInd);
    float getAt(int ind);

    static int m_nbInstance;
//private:
    unsigned int m_Count;
    string m_ID;
    float *m_Floats;
private:
    float *getFloats(string values);

};

#endif // FLOAT_ARRAY_H
