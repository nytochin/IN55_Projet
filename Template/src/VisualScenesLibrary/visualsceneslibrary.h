#ifndef VISUALSCENESLIBRARY_H
#define VISUALSCENESLIBRARY_H
#include "visual_scene.h"


class VisualScenesLibrary
{
public:
    VisualScenesLibrary();
    void readDataFrom(TiXmlElement *src);
    Visual_Scene m_Visual_Scene;
};

#endif // VISUALSCENESLIBRARY_H
