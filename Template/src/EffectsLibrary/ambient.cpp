#include "ambient.h"

Ambient::Ambient()
{

}

void Ambient::readDataFrom(TiXmlElement *src){
    m_Color.readDataFrom(src->FirstChildElement());
}
