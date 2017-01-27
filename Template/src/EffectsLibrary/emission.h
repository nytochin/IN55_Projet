#ifndef EMISSION_H
#define EMISSION_H
#include "color.h"


class Emission
{
public:
    Emission();
    void readDataFrom(TiXmlElement *src);

    Color m_Color;
};

#endif // EMISSION_H
