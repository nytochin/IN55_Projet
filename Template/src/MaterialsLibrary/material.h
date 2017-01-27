#ifndef MATERIAL_H
#define MATERIAL_H
#include "instance_effect.h"

class Material
{
public:
    Material();
    void readDataFrom(TiXmlElement *src);

    string m_ID;
    string m_Name;
    Instance_Effect m_Instance_Effect;
};

#endif // MATERIAL_H
