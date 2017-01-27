#include "float_array.h"
#include <strstream>

int Float_Array::m_nbInstance = 0;
Float_Array::Float_Array()
{

}

void Float_Array::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_ID = src->Attribute("id");
    src->QueryUnsignedAttribute("count", &m_Count);
    m_Floats = getFloats(src->GetText());
}

float *Float_Array::getFloats(string values){
    istrstream iss(values.c_str());
    vector<float> *tokens = new vector<float>();
    string token;
    while(getline(iss, token, ' ')){
        if(!token.empty()) tokens->push_back((float)atof(token.c_str()));
    }
    return tokens->data();
}

vector<Vector4> Float_Array::readVectors(){
    Vector4 v;
    vector<Vector4> vectors;
    for (int i = 0; i < m_Count ; i += 3){
        v.x = m_Floats[i];
        v.y = m_Floats[i+1];
        v.z = m_Floats[i+2];
        v.w = 1;
        vectors.push_back(v);
    }
    return vectors;
}

vector<Matrix4> Float_Array::readMatrices(){
    Matrix4 m;
    vector<Matrix4> matrices;
    for (int i = 0; i < m_Count ; i += 16){
        m = Matrix4();
        for (int j = i; j < i+16 ; j++){
            m[j-i] = m_Floats[j];
        }
        matrices.push_back(m);
    }
    return matrices;
}

float Float_Array::getAt(int ind){
    return m_Floats[ind];
}


Matrix4 Float_Array::readMatrixAt(int matInd){
    //cout << "Reading Matrix n: "<<++m_nbInstance<<endl;
    int stride = 16;
    int realInd = stride*matInd;
    float mat[stride];
    for(int i=realInd; i<realInd+stride; i++){
        mat[i-realInd] = m_Floats[i];
    }
    return Matrix4(mat)/*.transpose()*/;
}

