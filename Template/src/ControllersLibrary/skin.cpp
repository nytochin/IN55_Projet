#include "skin.h"

Skin::Skin()
{

}

void Skin::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_Source = src->Attribute("source");

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("bind_shape_matrix") == 0){
            m_Bind_Shape_Matrix.readDataFrom(cur);
        }
        else if(string(cur->Value()).compare("source") == 0){
            Source sc;
            sc.readDataFrom(cur);
            m_Sources.push_back(sc);
        }
        else if(string(cur->Value()).compare("joints") == 0){
            m_Joints.readDataFrom(cur);
        }
        else if(string(cur->Value()).compare("vertex_weights") == 0){
            m_Vertex_Weights.readDataFrom(cur);
        }
        cur = cur->NextSiblingElement();
    }
}

Source Skin::findSource(string srcID){
    int index = 0;
    while (m_Sources.at(index).m_ID.compare(srcID) != 0){
        index++;
    }
    return m_Sources.at(index);
}

void Skin::buildInverseBindMatrices(){
    InputAttributes ia = m_Joints.getAttributes("INV_BIND_MATRIX");
    Source src = findSource(ia.m_Source);
    m_InvBindMatrices = src.m_Float_Array.readMatrices();

}



