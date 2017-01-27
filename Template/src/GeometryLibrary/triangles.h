#ifndef TRIANGLES_H
#define TRIANGLES_H
#include <string>
#include <vector>
#include "CommonElements/input.h"
#include "p.h"
using namespace std;


class Triangles
{
public:
    Triangles();
    void readDataFrom(TiXmlElement *src);
    InputAttributes getAttributes(string SEM);

//private:
    unsigned int m_Count;
    string m_Material;
    vector<Input> m_Inputs;
    P m_P;


};

#endif // TRIANGLES_H
