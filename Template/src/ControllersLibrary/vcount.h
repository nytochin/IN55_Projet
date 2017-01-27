#ifndef VCOUNT_H
#define VCOUNT_H

#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <strstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef struct stGet {
    unsigned short *s;
    int count;
} stGet;
class Vcount
{
public:
    Vcount();
    void readDataFrom(TiXmlElement *src);
    unsigned short * m_Vcounts;

private:
    stGet getShorts(string values);
};

#endif // VCOUNT_H
