#ifndef SKELETON_H
#define SKELETON_H
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <string>
#include <iostream>
using namespace std;


class Skeleton
{
public:
    Skeleton();
    void readDataFrom(TiXmlElement *src);
    string m_Skeleton;
};

#endif // SKELETON_H
