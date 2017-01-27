#include "vertex_weights.h"

Vertex_Weights::Vertex_Weights()
{

}

void Vertex_Weights::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    src->QueryUnsignedAttribute("count", &m_Count);

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("input") == 0){
            Input ip;
            ip.readDataFrom(cur);
            m_Inputs.push_back(ip);
        }
        else if(string(cur->Value()).compare("vcount") == 0){
            m_Vcount.readDataFrom(cur);
        }
        else if(string(cur->Value()).compare("v") == 0){
            m_V.readDataFrom(cur);
        }
        cur = cur->NextSiblingElement();
    }
}

InputAttributes Vertex_Weights::getAttributes(string SEM){
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
