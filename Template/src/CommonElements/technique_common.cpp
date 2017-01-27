#include "technique_common.h"

Technique_Common::Technique_Common()
{
    //this->m_Accessor = new Accessor();
}

void Technique_Common::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    TiXmlElement *cur = src->FirstChildElement();
    m_Accessor.readDataFrom(cur);
}

