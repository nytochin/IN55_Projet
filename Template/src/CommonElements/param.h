#ifndef PARAM_H
#define PARAM_H
#include <string>
#include <iostream>
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
using namespace std;

class Param
{
public:
    Param();
    void readDataFrom(TiXmlElement *src);
//private:
    string m_Name;
    string m_Type;

};

#endif // PARAM_H
