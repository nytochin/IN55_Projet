#ifndef V_H
#define V_H

#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <strstream>
#include <iostream>
#include <string>
#include <vector>
#include "vcount.h"
using namespace std;

class V
{
public:
    V();
    void readDataFrom(TiXmlElement *src);
    unsigned short * m_Indices;

private:
    stGet getShorts(string values);
};

#endif // V_H
