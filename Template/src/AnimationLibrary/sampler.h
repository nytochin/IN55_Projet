#ifndef SAMPLER_H
#define SAMPLER_H
#include "CommonElements/input.h"
#include <string>
#include <vector>
using namespace std;


class Sampler
{
public:
    Sampler();
    void readDataFrom(TiXmlElement *src);
    InputAttributes getAttributes(string SEM);

    string m_ID;
    vector<Input> m_Inputs;
};

#endif // SAMPLER_H
