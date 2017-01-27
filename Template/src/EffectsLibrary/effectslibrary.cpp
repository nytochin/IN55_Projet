#include "effectslibrary.h"

EffectsLibrary::EffectsLibrary()
{

}

void EffectsLibrary::readDataFrom(TiXmlElement *src){
    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("effect") == 0){
            Effect ef;
            ef.readDataFrom(cur);
            m_Effects.push_back(ef);
        }
        cur = cur->NextSiblingElement();
    }
}
