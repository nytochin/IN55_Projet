#include "color.h"
#include <strstream>
#include <string>
#include <vector>
using namespace std;

Color::Color()
{

}

void Color::readDataFrom(TiXmlElement *src){
    m_color = getFloats(src->GetText());
    buildComponents();
}

float *Color::getFloats(string values){
    istrstream iss(values.c_str());
    vector<float> *tokens = new vector<float>();
    string token;
    while(getline(iss, token, ' ')){
        if(!token.empty()) tokens->push_back((float)atof(token.c_str()));
    }
    return tokens->data();
}

void Color::buildComponents(){
    r = m_color[0];
    g = m_color[1];
    b = m_color[2];
    alpha = m_color[3];
}
