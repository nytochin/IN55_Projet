#include "input.h"

Input::Input()
{

}

void Input::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_Semantic = src->Attribute("semantic") ? src->Attribute("semantic") : "";
    m_Source = src->Attribute("source") ? src->Attribute("source") : "";
    if(src->QueryIntAttribute("offset", &m_Offset) == TIXML_NO_ATTRIBUTE) m_Offset = -1;
    if(src->QueryIntAttribute("set", &m_Set)== TIXML_NO_ATTRIBUTE) m_Set = -1;
}
