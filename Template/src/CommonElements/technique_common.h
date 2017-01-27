#ifndef TECHNIQUE_COMMON_H
#define TECHNIQUE_COMMON_H
#include "accessor.h"

class Technique_Common
{
public:
    Technique_Common();
    void readDataFrom(TiXmlElement *src);
//private:
    Accessor m_Accessor;



};

#endif // TECHNIQUE_COMMON_H
