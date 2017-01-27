#ifndef EFFECT_H
#define EFFECT_H
#include "effectDef.h"
#include "profile_common.h"


class Effect
{
public:
    Effect();
    void readDataFrom(TiXmlElement *src);

    string m_ID;
    string m_Name;
    Profile_Common m_Profile_Common;
};

#endif // EFFECT_H
