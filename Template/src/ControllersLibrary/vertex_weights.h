#ifndef VERTEX_WEIGHTS_H
#define VERTEX_WEIGHTS_H
#include "controllerDef.h"



class Vertex_Weights
{
public:
    Vertex_Weights();
    void readDataFrom(TiXmlElement *src);
    InputAttributes getAttributes(string SEM);


    unsigned int m_Count;
    vector<Input> m_Inputs;
    Vcount m_Vcount;
    V m_V;
};

#endif // VERTEX_WEIGHTS_H
