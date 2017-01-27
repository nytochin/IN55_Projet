#include "instance_controller.h"

Instance_Controller::Instance_Controller()
{

}

void Instance_Controller::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;

    m_Url = src->Attribute("url");

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("skeleton") == 0){
            Skeleton sq;
            sq.readDataFrom(cur);
            m_Skeletons.push_back(sq);
        }
        cur = cur->NextSiblingElement();
    }
}


