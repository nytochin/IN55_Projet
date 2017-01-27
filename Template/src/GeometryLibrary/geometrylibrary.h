#ifndef GEOMETRYLIBRARY_H
#define GEOMETRYLIBRARY_H
#include "geometry.h"

class GeometryLibrary
{
public:
    GeometryLibrary();
    void readDataFrom(TiXmlElement *src);

//private:
    vector<Geometry> m_Geometries;

};

#endif // GEOMETRYLIBRARY_H
