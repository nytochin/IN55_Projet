#ifndef INSTANCE_VISUAL_SCENE_H
#define INSTANCE_VISUAL_SCENE_H
#include <string>
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
using namespace std;

class Instance_Visual_Scene
{
public:
    Instance_Visual_Scene();
    void readDataFrom(TiXmlElement *src);
    string m_Url;
};

#endif // INSTANCE_VISUAL_SCENE_H
