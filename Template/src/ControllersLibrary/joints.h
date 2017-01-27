#ifndef JOINTS_H
#define JOINTS_H
#include "CommonElements/input.h"

class Joints
{
public:
    Joints();
    void readDataFrom(TiXmlElement *src);
    InputAttributes getAttributes(string SEM);

    vector<Input> m_Inputs;
};

#endif // JOINTS_H
