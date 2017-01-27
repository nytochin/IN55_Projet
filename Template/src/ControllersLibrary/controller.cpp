#include "controller.h"

Controller::Controller()
{

}

void Controller::readDataFrom(TiXmlElement *src){
   m_ID = src->Attribute("id");
   m_Skin.readDataFrom(src->FirstChildElement());
}

Source Controller::findSource(string srcID){
    return m_Skin.findSource(srcID);
}

float Controller::getWeight(string wsource, int wind){
    Source src = findSource(wsource);
    return src.m_Float_Array.m_Floats[wind];
}

string Controller::getJointSID(string jsource, int jind){
    Source src = findSource(jsource);
    return src.m_Name_Array.m_Names[jind];
}


