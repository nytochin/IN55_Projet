#ifndef TRANSPARENCY_H
#define TRANSPARENCY_H

#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"

class Transparency
{
public:
    Transparency();
    void readDataFrom(TiXmlElement *src);

    float m_Float;
};

#endif // TRANSPARENCY_H
