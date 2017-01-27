#include "joints.h"

Joints::Joints()
{
}

void Joints::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("input") == 0){
            Input ip;
            ip.readDataFrom(cur);
            m_Inputs.push_back(ip);
        }
        cur = cur->NextSiblingElement();
    }
}

InputAttributes Joints::getAttributes(string SEM){
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
