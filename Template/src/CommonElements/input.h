#ifndef INPUT_H
#define INPUT_H
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef struct InputAttributes {
    string m_Source;
    int m_Offset;
    int m_Set;
} InputAttributes;

class Input
{
public:
    Input();
    void readDataFrom(TiXmlElement *src);
//private:
    string m_Semantic;
    string m_Source;
    int m_Offset;
    int m_Set;

};

#endif // INPUT_H
