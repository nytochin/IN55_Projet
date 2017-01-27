#ifndef ANIMATION_H
#define ANIMATION_H
#include "animationDef.h"

typedef struct animElmnt{
    Float_Array times;
    Float_Array elements;
    TransformTarget target;
}AnimElement;

class Animation
{
public:
    Animation();    
    void readDataFrom(TiXmlElement *src);

    Source findSource(string srcID);
    Sampler findSampler(string sampID);

public:
    string m_ID;
    vector<Source> m_Sources;
    vector<Sampler> m_Samplers;
    vector<Channel> m_Channels;

};

#endif // ANIMATION_H
