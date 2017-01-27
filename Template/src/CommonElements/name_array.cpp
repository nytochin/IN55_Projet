#include "name_array.h"
#include <strstream>

Name_Array::Name_Array()
{

}

void Name_Array::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_ID = src->Attribute("id");
    src->QueryUnsignedAttribute("count", &m_Count);
    m_Names = getStrings(src->GetText());
}

string *Name_Array::getStrings(string values){
    istrstream iss(values.c_str());
    vector<string> *tokens = new vector<string>();
    string token;
    while(getline(iss, token, ' ')){
        if(!token.empty()) tokens->push_back(token.c_str());
    }
    return tokens->data();
}
