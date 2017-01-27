#ifndef VERTICES_H
#define VERTICES_H
#include <string>
#include <vector>
#include "CommonElements/input.h"
using namespace std;

class Vertices
{
public:
    Vertices();
    void readDataFrom(TiXmlElement *src);
    InputAttributes getAttributes(string SEM);

//private:
    string m_ID;
    vector<Input> m_Inputs;
};

#endif // VERTICES_H
