#include "geometrylibrary.h"
#include <vector>
using namespace std;

GeometryLibrary::GeometryLibrary()
{
    //this->m_Geometries = new vector<Geometry*>();
}

void GeometryLibrary::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("geometry") == 0){
            Geometry geom;
            geom.readDataFrom(cur);
            m_Geometries.push_back(geom);
        }
        cur = cur->NextSiblingElement();
    }
}
