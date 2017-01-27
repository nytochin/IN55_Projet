#ifndef CONTROLLERSLIBRARY_H
#define CONTROLLERSLIBRARY_H
#include "controller.h"


class ControllerLibrary
{
public:
    ControllerLibrary();
    void readDataFrom(TiXmlElement *src);

    Controller m_Controller;
};

#endif // CONTROLLERSLIBRARY_H
