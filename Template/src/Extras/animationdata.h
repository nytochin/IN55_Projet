#ifndef ANIMATIONDATA_H
#define ANIMATIONDATA_H
#include "frame.h"

class AnimationData
{
public:
    AnimationData();
    AnimationData(Collada *collada);
    void init();
    void loadNextFrame();

//private:
    vector<Frame> animations;
    Collada* m_Collada;
    vector<AnimatData> nextAnimationDatas;


};

#endif // ANIMATIONDATA_H
