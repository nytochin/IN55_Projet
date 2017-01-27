#include "instance_light.h"

Instance_Light::Instance_Light()
{
}

void Instance_Light::readDataFrom(TiXmlElement *src){
    m_Url = src->Attribute("url");
}
