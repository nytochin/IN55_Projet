#include "animationlibrary.h"

AnimationLibrary::AnimationLibrary()
{

}

void AnimationLibrary::readDataFrom(TiXmlElement *src){
    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("animation") == 0){
            Animation anim;
            anim.readDataFrom(cur);
            m_Animations.push_back(anim);
        }
        cur = cur->NextSiblingElement();
    }
}

int AnimationLibrary::getAnimationNumber(){
    int nbAnim = 0;
    for(int i=0; i<m_Animations.size(); i++){
        Animation anim = m_Animations.at(i);
        if(anim.m_Channels.size() == 16) nbAnim++;
    }
    return nbAnim;
}
