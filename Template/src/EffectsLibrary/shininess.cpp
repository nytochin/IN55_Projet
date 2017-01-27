#include "shininess.h"

Shininess::Shininess()
{

}

void Shininess::readDataFrom(TiXmlElement *src){
    m_Float = (float)atof(src->FirstChildElement()->GetText());
}
