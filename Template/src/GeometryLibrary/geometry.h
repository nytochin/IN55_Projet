#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "mesh.h"

class Geometry
{
public:
    Geometry();
    void readDataFrom(TiXmlElement *src);

//private:
    Mesh m_Mesh;
    string m_ID;
    string m_Name;
};

#endif // GEOMETRY_H
