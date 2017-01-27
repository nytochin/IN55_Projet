#ifndef COLOR_H
#define COLOR_H

#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <string>
using namespace std;

class Color
{
public:
    Color();
    void readDataFrom(TiXmlElement *src);

    float *m_color;
    float r;
    float g;
    float b;
    float alpha;

private:
    float *getFloats(string values);
    void buildComponents();
};

#endif // COLOR_H
