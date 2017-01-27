#include "bind_shape_matrix.h"
#include <strstream>

Bind_Shape_Matrix::Bind_Shape_Matrix()
{
}

void Bind_Shape_Matrix::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
   m_Floats = getFloats(src->GetText());
}

float *Bind_Shape_Matrix::getFloats(string values){
    istrstream iss(values.c_str());
    vector<float> *tokens = new vector<float>();
    string token;
    while(getline(iss, token, ' ')){
        if(!token.empty()) tokens->push_back((float)atof(token.c_str()));
    }
    return tokens->data();
}
