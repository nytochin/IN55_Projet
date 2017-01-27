#ifndef TECHNIQUE_H
#define TECHNIQUE_H
#include "phong.h"


class Technique
{
public:
    Technique();
    void readDataFrom(TiXmlElement *src);

    string m_SID;
    Phong m_Phong;
};

#endif // TECHNIQUE_H
