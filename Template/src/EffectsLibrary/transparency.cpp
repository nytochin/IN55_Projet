#include "transparency.h"

Transparency::Transparency()
{

}


void Transparency::readDataFrom(TiXmlElement *src){
    m_Float = (float)atof(src->FirstChildElement()->GetText());
}
