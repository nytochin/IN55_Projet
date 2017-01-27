#ifndef PHONG_H
#define PHONG_H
#include "effectDef.h"


class Phong
{
public:
    Phong();
    void readDataFrom(TiXmlElement *src);

    Emission m_Emission;
    Ambient m_Ambient;
    Specular m_Specular;
    Shininess m_Shininess;
    Transparency m_Transparency;
private:
    Diffuse m_Diffuse;
};

#endif // PHONG_H
