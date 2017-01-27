#include "matrix.h"

Matrix::Matrix()
{

}

void Matrix::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_Values = getFloats(src->GetText());
}

float *Matrix::getFloats(string values){
    istrstream iss(values.c_str());
    vector<float> *tokens = new vector<float>();
    string token;
    while(getline(iss, token, ' ')){
        if(!token.empty()) tokens->push_back((float)atof(token.c_str()));
    }
    return tokens->data();
}


