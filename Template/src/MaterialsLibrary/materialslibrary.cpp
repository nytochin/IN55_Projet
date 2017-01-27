#include "materialslibrary.h"

MaterialsLibrary::MaterialsLibrary()
{

}

void MaterialsLibrary::readDataFrom(TiXmlElement *src){
    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("material") == 0){
            Material mat;
            mat.readDataFrom(cur);
            m_Materials.push_back(mat);
        }
        cur = cur->NextSiblingElement();
    }
}
