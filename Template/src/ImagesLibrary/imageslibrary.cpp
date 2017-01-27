#include "imageslibrary.h"

ImagesLibrary::ImagesLibrary()
{

}

void ImagesLibrary::readDataFrom(TiXmlElement *src){

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("image") == 0){
            Image img;
            img.readDataFrom(cur);
            m_Images.push_back(img);
        }
        cur = cur->NextSiblingElement();
    }
}
