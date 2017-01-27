#ifndef ACCESSOR_H
#define ACCESSOR_H
#include "param.h"
#include <vector>
using namespace std;

class Accessor
{
public:
    Accessor();
    void readDataFrom(TiXmlElement *src);
//private:
    string m_Source;
    unsigned int m_Count;
    unsigned int m_Stride;
    vector<Param> m_Params;

};

#endif // ACCESSOR_H
