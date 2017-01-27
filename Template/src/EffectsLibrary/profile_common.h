#ifndef PROFILE_COMMON_H
#define PROFILE_COMMON_H
#include "technique.h"
#include <string>
using namespace std;


class Profile_Common
{
public:
    Profile_Common();
    void readDataFrom(TiXmlElement *src);

    Technique m_Technique;
};

#endif // PROFILE_COMMON_H
