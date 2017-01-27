#include "profile_common.h"

Profile_Common::Profile_Common()
{

}

void Profile_Common::readDataFrom(TiXmlElement *src){
    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("technique") == 0){
            m_Technique.readDataFrom(cur);
            break;
        }
        cur = cur->NextSiblingElement();
    }
}
