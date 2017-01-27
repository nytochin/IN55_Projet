#ifndef INSTANCE_EFFECT_H
#define INSTANCE_EFFECT_H
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <string>
using namespace std;

class Instance_Effect
{
public:
    Instance_Effect();
    void readDataFrom(TiXmlElement *src);

    string m_Url;
};

#endif // INSTANCE_EFFECT_H
