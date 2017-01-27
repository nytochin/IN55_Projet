#include "material.h"

Material::Material()
{

}

void Material::readDataFrom(TiXmlElement *src){
    m_ID = src->Attribute("id");
    m_Name = src->Attribute("name");
    m_Instance_Effect.readDataFrom(src->FirstChildElement());
}

