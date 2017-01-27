#include "animation.h"

Animation::Animation()
{

}


void Animation::readDataFrom(TiXmlElement *src){
    m_ID = src->Attribute("id");

    TiXmlElement * cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("source") == 0){
            Source thisSource;
            thisSource.readDataFrom(cur);
            m_Sources.push_back(thisSource);
        }
        else if(string(cur->Value()).compare("sampler") == 0){
            Sampler samp;
            samp.readDataFrom(cur);
            m_Samplers.push_back(samp);
        }
        else if(string(cur->Value()).compare("channel") == 0){
            Channel chan;
            chan.readDataFrom(cur);
            m_Channels.push_back(chan);
        }
        cur = cur->NextSiblingElement();
    }
}


Sampler Animation::findSampler(string sampID){
    int index = 0;
    while (m_Samplers.at(index).m_ID.compare(sampID) != 0){
        index++;
    }
    return m_Samplers.at(index);
}

Source Animation::findSource(string srcID){
    int index = 0;
    while (m_Sources.at(index).m_ID.compare(srcID) != 0){
        index++;
    }
    return m_Sources.at(index);
}
