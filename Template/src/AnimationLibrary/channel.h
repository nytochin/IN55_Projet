#ifndef CHANNEL_H
#define CHANNEL_H
#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
#include <string>
#include <vector>
#include "CommonElements/Matrices.h"
using namespace std;

typedef struct TransformTarget{
    string targetID;
    int rowNum;
    int colNum;
}TransformTarget;

typedef struct ChannelAttr{
    string source;
    TransformTarget transTarget;
}ChannelAttr;

class Channel
{
public:
    Channel();
    void readDataFrom(TiXmlElement *src);
    ChannelAttr getAttributes();

public:
    string m_Source;
    string m_Target;
};

#endif // CHANNEL_H
