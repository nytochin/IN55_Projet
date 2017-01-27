#ifndef P_H
#define P_H

#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"

#include <strstream>
#include <iostream>
#include <string>
#include <vector>
#include "ControllersLibrary/vcount.h"
using namespace std;

class P
{
public:
    P();
    void readDataFrom(TiXmlElement *src);

//private:
    unsigned int m_Count;
    unsigned short *m_Indices;

private:
    stGet getShorts(string values);

};

#endif // P_H
