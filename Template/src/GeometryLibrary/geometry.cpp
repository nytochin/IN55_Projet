#include "geometry.h"

Geometry::Geometry()
{
    //this->m_Mesh = new Mesh();
}

void Geometry::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_ID = src->Attribute("id") ? src->Attribute("id") : "";
    m_Name = src->Attribute("name") ? src->Attribute("name") : "";

    TiXmlElement *cur = src->FirstChildElement();
    if(string(cur->Value()).compare("mesh") == 0){
        m_Mesh.readDataFrom(cur);
    }
}
