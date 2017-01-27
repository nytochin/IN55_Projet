#include "mesh.h"

Mesh::Mesh()
{
}

void Mesh::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("source") == 0){
            Source sc;
            sc.readDataFrom(cur);
            m_Sources.push_back(sc);
        }
        else if(string(cur->Value()).compare("vertices") == 0){
            m_Vertices.readDataFrom(cur);
        }
        else if(string(cur->Value()).compare("triangles") == 0){
            Triangles tri;
            tri.readDataFrom(cur);
            m_Triangles.push_back(tri);
        }
        cur = cur->NextSiblingElement();
    }
}

vector<Vector4> Mesh::getVertices(){
    InputAttributes va = m_Vertices.getAttributes("POSITION");
    Source src = findSource(va.m_Source);
    Float_Array fa = src.m_Float_Array;
    vector<Vector4> res = fa.readVectors();
    return res;
}


vector<Vector4> Mesh::getTextures(){
    InputAttributes va = m_Triangles.at(0).getAttributes("TEXCOORD");
    Source src = findSource(va.m_Source);
    Float_Array fa = src.m_Float_Array;
    vector<Vector4> res = fa.readVectors();
    return res;
}

Source Mesh::findSource(string srcID){
    int index = 0;
    while (m_Sources.at(index).m_ID.compare(srcID) != 0){
        index++;
    }
    return m_Sources.at(index);
}
