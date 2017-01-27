#include "specular.h"

Specular::Specular()
{

}

void Specular::readDataFrom(TiXmlElement *src){
    m_Color.readDataFrom(src->FirstChildElement());
}
