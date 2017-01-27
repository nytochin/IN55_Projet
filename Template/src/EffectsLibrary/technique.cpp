#include "technique.h"

Technique::Technique()
{

}

void Technique::readDataFrom(TiXmlElement *src){
    m_SID = src->Attribute("sid");

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("phong") == 0){
            m_Phong.readDataFrom(cur);
            break;
        }
        cur = cur->NextSiblingElement();
    }
}
