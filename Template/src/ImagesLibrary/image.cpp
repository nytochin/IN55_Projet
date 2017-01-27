#include "image.h"

Image::Image()
{

}

void Image::readDataFrom(TiXmlElement *src){
    m_ID = src->Attribute("id");
    m_Name = src->Attribute("name");
    m_Init_From.readDataFrom(src->FirstChildElement());
}

