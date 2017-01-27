#include "instance_visual_scene.h"

Instance_Visual_Scene::Instance_Visual_Scene()
{
}

void Instance_Visual_Scene::readDataFrom(TiXmlElement *src){
    m_Url = src->Attribute("url");
}
