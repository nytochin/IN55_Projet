#include "collada.h"
#include <iostream>

Collada::Collada(){
    //this->m_GeometryLibrary = new GeometryLibrary();
}

void Collada::readAnimations(TiXmlElement *src){
    TiXmlElement *cur = src;
    while(cur){
        if(string(cur->Value()).compare("library_animations") == 0){
            cout << "Current Element : " <<cur->Value()<<endl;
            m_AnimationLibrary.readDataFrom(cur);
            break;
        }
        cur = cur->NextSiblingElement();
    }
}

void Collada::readGeometries(TiXmlElement *src){
    TiXmlElement *cur = src;
    while(cur){
        // cout << "Current Element : " <<cur->Value()<<endl;
        if(string(cur->Value()).compare("library_geometries") == 0){
            m_GeometryLibrary.readDataFrom(cur);
            break;
        }
        cur = cur->NextSiblingElement();
    }
}

void Collada::readImages(TiXmlElement *src){
    TiXmlElement *cur = src;
    while(cur){
        if(string(cur->Value()).compare("library_images") == 0){
            m_ImagesLibrary.readDataFrom(cur);
            break;
        }
        cur = cur->NextSiblingElement();
    }
}
void Collada::readMaterials(TiXmlElement *src){
    TiXmlElement *cur = src;
    while(cur){
        if(string(cur->Value()).compare("library_materials") == 0){
            m_MaterialsLibrary.readDataFrom(cur);
            break;
        }
        cur = cur->NextSiblingElement();
    }
}
void Collada::readEffects(TiXmlElement *src){
    TiXmlElement *cur = src;
    while(cur){
        if(string(cur->Value()).compare("library_effects") == 0){
            m_EffectsLibrary.readDataFrom(cur);
            break;
        }
        cur = cur->NextSiblingElement();
    }
}
void Collada::readControllers(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    TiXmlElement *cur = src;
    while(cur){
        if(string(cur->Value()).compare("library_controllers") == 0){
            m_ControllerLibrary.readDataFrom(cur);
            break;
        }
        cur = cur->NextSiblingElement();
    }
}
void Collada::readVisualScenes(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    TiXmlElement *cur = src;
    while(cur){
        if(string(cur->Value()).compare("library_visual_scenes") == 0){
            m_VisualScenesLibrary.readDataFrom(cur);
            break;
        }
        cur = cur->NextSiblingElement();
    }
}
