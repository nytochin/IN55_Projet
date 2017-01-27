#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "controllerDef.h"
#include "skin.h"


class Controller
{
public:
    Controller();
    void readDataFrom(TiXmlElement *src);
    Source findSource(string srcID);
    float getWeight(string wsource, int wind);
    string getJointSID(string jsource, int jind);

    string m_ID;
    Skin m_Skin;
};

#endif // CONTROLLER_H
