#ifndef SCENE_H
#define SCENE_H
#include "instance_visual_scene.h"

class Scene
{
public:
    Scene();
    void readDataFrom(TiXmlElement *src);

    Instance_Visual_Scene m_Instance_Visual_Scene;
};

#endif // SCENE_H
