#include "source.h"

Source::Source()
{
    //this->m_Float_Array = new Float_Array();
    //this->m_Name_Array = new Name_Array();
    //this->m_Technique_Common = new Technique_Common();
}

void Source::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_ID = src->Attribute("id");

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("float_array") == 0)
            m_Float_Array.readDataFrom(cur);
        else if(string(cur->Value()).compare("Name_array") == 0)
            m_Name_Array.readDataFrom(cur);
        else if(string(cur->Value()).compare("technique_common") == 0)
            m_Technique_Common.readDataFrom(cur);
        cur = cur->NextSiblingElement();
    }
}
