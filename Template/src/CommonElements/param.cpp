#include "param.h"

Param::Param()
{

}

void Param::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_Type = src->Attribute("type")?src->Attribute("type"):"";
    m_Name = src->Attribute("name")? src->Attribute("name"):"";
}

