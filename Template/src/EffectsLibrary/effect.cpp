#include "effect.h"

Effect::Effect()
{

}

void Effect::readDataFrom(TiXmlElement *src){
    m_ID = src->Attribute("id");
    m_Name = src->Attribute("name");

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("profile_COMMON") == 0){
            m_Profile_Common.readDataFrom(cur);
            break;
        }
        cur = cur->NextSiblingElement();
    }
}
