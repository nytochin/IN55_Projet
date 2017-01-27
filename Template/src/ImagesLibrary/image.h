#ifndef IMAGE_H
#define IMAGE_H
#include "init_from.h"

class Image
{
public:
    Image();
    void readDataFrom(TiXmlElement *src);

    string m_ID;
    string m_Name;
    Init_From m_Init_From;
};

#endif // IMAGE_H
