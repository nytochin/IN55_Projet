#ifndef SHININESS_H
#define SHININESS_H

#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"

class Shininess
{
public:
    Shininess();
    void readDataFrom(TiXmlElement *src);

    float m_Float;
};

#endif // SHININESS_H
