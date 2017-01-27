#ifndef AMBIENT_H
#define AMBIENT_H
#include "color.h"


class Ambient
{
public:
    Ambient();
    void readDataFrom(TiXmlElement *src);

    Color m_Color;
};

#endif // AMBIENT_H
