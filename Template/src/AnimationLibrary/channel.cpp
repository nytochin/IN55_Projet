#include "channel.h"
#include <strstream>

Channel::Channel()
{

}

void Channel::readDataFrom(TiXmlElement *src){
    m_Source = src->Attribute("source");
    m_Target = src->Attribute("target");
}

ChannelAttr Channel::getAttributes(){
    ChannelAttr ca;
    ca.source = m_Source.substr(1);

    istrstream iss(m_Target.c_str());
    vector<string> tokens;
    string token;
    while(getline(iss, token, '/')){
        if(!token.empty()) tokens.push_back(token.c_str());
    }
    ca.transTarget.targetID = tokens.at(0);

    istrstream iss2(tokens.at(1).c_str());
    vector<string> tokens2;
    while(getline(iss2, token, '(')){
        if(!token.empty()) tokens2.push_back(token.c_str());
    }
    if(tokens2.size()>1){
        ca.transTarget.colNum = atoi(tokens2.at(1).substr(0, tokens2.at(1).length() - 1).c_str());
        ca.transTarget.rowNum = atoi(tokens2.at(2).substr(0, tokens2.at(1).length() - 1).c_str());
    }

    return ca;
}
