#ifndef INIT_FROM_H
#define INIT_FROM_H
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <string>
using namespace std;


class Init_From
{
public:
    Init_From();
    void readDataFrom(TiXmlElement *src);

    string m_Filename;
};

#endif // INIT_FROM_H
