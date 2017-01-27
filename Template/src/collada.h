#ifndef COLLADA_H
#define COLLADA_H
#include "GeometryLibrary/geometrylibrary.h"
#include "AnimationLibrary/animationlibrary.h"
#include "ControllersLibrary/controllerslibrary.h"
#include "EffectsLibrary/effectslibrary.h"
#include "ImagesLibrary/imageslibrary.h"
#include "MaterialsLibrary/materialslibrary.h"
#include "VisualScenesLibrary/visualsceneslibrary.h"

class Collada
{
public:
    Collada();

    void readAnimations(TiXmlElement *src);
    void readGeometries(TiXmlElement *src);
    void readImages(TiXmlElement *src);
    void readMaterials(TiXmlElement *src);
    void readEffects(TiXmlElement *src);
    void readControllers(TiXmlElement *src);
    void readVisualScenes(TiXmlElement *src);

   // private:
    AnimationLibrary m_AnimationLibrary;
    GeometryLibrary m_GeometryLibrary;
    ImagesLibrary m_ImagesLibrary;
    MaterialsLibrary m_MaterialsLibrary;
    EffectsLibrary m_EffectsLibrary;
    ControllerLibrary m_ControllerLibrary;
    VisualScenesLibrary m_VisualScenesLibrary;

};

#endif // COLLADA_H
