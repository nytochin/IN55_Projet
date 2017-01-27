#ifndef SPECULAR_H
#define SPECULAR_H
#include "color.h"


class Specular
{
public:
    Specular();
    void readDataFrom(TiXmlElement *src);

    Color m_Color;
};

#endif // SPECULAR_H
