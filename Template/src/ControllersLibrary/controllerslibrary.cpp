#include "controllerslibrary.h"

ControllerLibrary::ControllerLibrary()
{

}

void ControllerLibrary::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("controller") == 0){
            m_Controller.readDataFrom(cur);
        }
        cur = cur->NextSiblingElement();
    }
}

