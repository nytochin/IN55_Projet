#ifndef NAME_ARRAY_H
#define NAME_ARRAY_H
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Name_Array
{
public:
    Name_Array();
    void readDataFrom(TiXmlElement *src);
//private:
    unsigned int m_Count;
    string m_ID;
    string *m_Names;

private:
    string *getStrings(string values);

};

#endif // NAME_ARRAY_H
