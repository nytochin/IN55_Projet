#ifndef INSTANCE_CONTROLLER_H
#define INSTANCE_CONTROLLER_H
#include "visualSceneDef.h"


class Instance_Controller
{
public:
    Instance_Controller();
    void readDataFrom(TiXmlElement *src);
    string m_Url;
    vector<Skeleton> m_Skeletons;
};

#endif // INSTANCE_CONTROLLER_H
