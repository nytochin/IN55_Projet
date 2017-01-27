#ifndef ANIMATIONLIBRARY_H
#define ANIMATIONLIBRARY_H
#include "animationDef.h"
#include "animation.h"

class AnimationLibrary
{
public:
    AnimationLibrary();
    void readDataFrom(TiXmlElement *src);
    int getAnimationNumber();

    vector<Animation> m_Animations;
};

#endif // ANIMATIONLIBRARY_H
