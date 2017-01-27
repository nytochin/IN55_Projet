#ifndef EFFECTSLIBRARY_H
#define EFFECTSLIBRARY_H
#include "effectDef.h"
#include "effect.h"


class EffectsLibrary
{
public:
    EffectsLibrary();
    void readDataFrom(TiXmlElement *src);

    vector<Effect> m_Effects;
};

#endif // EFFECTSLIBRARY_H
