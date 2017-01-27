#include "triangles.h"

Triangles::Triangles()
{
    //this->m_Inputs = new vector<Input*>();
    //this->m_P = new P();

}

void Triangles::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_Material = src->Attribute("material") ? src->Attribute("material") : "";
    src->QueryUnsignedAttribute("count", &m_Count);

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("input") == 0){
            Input ip;
            ip.readDataFrom(cur);
            m_Inputs.push_back(ip);
        }
        else if(string(cur->Value()).compare("p") == 0){
            m_P.readDataFrom(cur);
            //m_P.m_Count = m_Count;
        }
        cur = cur->NextSiblingElement();
    }
}

InputAttributes Triangles::getAttributes(string SEM){
    int i = 0;
    InputAttributes ia;
    while(m_Inputs.at(i).m_Semantic.compare(SEM) != 0 && i < m_Inputs.size()){
        i++;
    }
    if (i >= m_Inputs.size()){
        ia.m_Source = "";
        ia.m_Offset = -1;
        ia.m_Set = -1;
        return ia;
    }
    ia.m_Source = m_Inputs.at(i).m_Source.substr(1);
    ia.m_Offset = m_Inputs.at(i).m_Offset;
    ia.m_Set = m_Inputs.at(i).m_Set;
    return ia;
}

