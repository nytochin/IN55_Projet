#include "accessor.h"

Accessor::Accessor()
{
    //this->m_Params = new vector<Param*>();
}

void Accessor::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_Source = src->Attribute("source");
    src->QueryUnsignedAttribute("count", &m_Count);
    src->QueryUnsignedAttribute("stride", &m_Stride);

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("param") == 0){
            Param par;
            par.readDataFrom(cur);
            m_Params.push_back(par);
        }
        cur = cur->NextSiblingElement();
    }
}

