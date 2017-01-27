#include "visualsceneslibrary.h"

VisualScenesLibrary::VisualScenesLibrary()
{

}

void VisualScenesLibrary::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("visual_scene") == 0){
            m_Visual_Scene.readDataFrom(cur);
        }
        cur = cur->NextSiblingElement();
    }
}
