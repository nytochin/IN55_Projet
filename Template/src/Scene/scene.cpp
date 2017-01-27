#include "scene.h"

Scene::Scene()
{
}

void Scene::readDataFrom(TiXmlElement *src){
    m_Instance_Visual_Scene.readDataFrom(src->FirstChildElement());
}
