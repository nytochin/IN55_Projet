#include "phong.h"

Phong::Phong()
{

}

void Phong::readDataFrom(TiXmlElement *src){
    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("emission") == 0){
            m_Emission.readDataFrom(cur);
        }
        else if(string(cur->Value()).compare("ambient") == 0){
            m_Ambient.readDataFrom(cur);
        }
        else if(string(cur->Value()).compare("specular") == 0){
            m_Specular.readDataFrom(cur);
        }
        else if(string(cur->Value()).compare("shininess") == 0){
            m_Shininess.readDataFrom(cur);
        }
        else if(string(cur->Value()).compare("transparency") == 0){
            m_Transparency.readDataFrom(cur);
        }
        cur = cur->NextSiblingElement();
    }
}
