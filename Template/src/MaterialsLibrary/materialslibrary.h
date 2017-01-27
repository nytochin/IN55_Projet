#ifndef MATERIALSLIBRARY_H
#define MATERIALSLIBRARY_H

#include "material.h"
#include <vector>

class MaterialsLibrary
{
public:
    MaterialsLibrary();
    void readDataFrom(TiXmlElement *src);
    vector<Material> m_Materials;
};

#endif // MATERIALSLIBRARY_H
