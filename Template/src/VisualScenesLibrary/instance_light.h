#ifndef INSTANCE_LIGHT_H
#define INSTANCE_LIGHT_H
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <string>
using namespace std;

class Instance_Light
{
public:
    Instance_Light();
    void readDataFrom(TiXmlElement *src);
    string m_Url;
};

#endif // INSTANCE_LIGHT_H
