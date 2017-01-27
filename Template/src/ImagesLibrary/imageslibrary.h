#ifndef IMAGESLIBRARY_H
#define IMAGESLIBRARY_H
#include "image.h"

#include <vector>
using namespace std;

class ImagesLibrary
{
public:
    ImagesLibrary();
    void readDataFrom(TiXmlElement *src);
    vector<Image> m_Images;
};

#endif // IMAGESLIBRARY_H
