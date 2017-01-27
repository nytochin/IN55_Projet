#ifndef SOURCE_H
#define SOURCE_H
#include <string>
#include "float_array.h"
#include "name_array.h"
#include "technique_common.h"
#include <iostream>
using namespace std;

class Source
{
public:
    Source();
    void readDataFrom(TiXmlElement *src);
//private:
    string m_ID;
    Float_Array m_Float_Array;
    Name_Array m_Name_Array;
    Technique_Common m_Technique_Common;


};

#endif // SOURCE_H
