#include "emission.h"

Emission::Emission()
{

}

void Emission::readDataFrom(TiXmlElement *src){
    m_Color.readDataFrom(src->FirstChildElement());
}
