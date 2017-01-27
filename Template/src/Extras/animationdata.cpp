#include "animationdata.h"

AnimationData::AnimationData()
{
}


AnimationData::AnimationData(Collada* collada)
{
    this->m_Collada = collada;
}

void AnimationData::init(){
    //cout<<"AnimationData::init() -- Animations number "<< m_Collada->m_AnimationLibrary.m_Animations.size()<<endl;
    for(int i = 0; i < m_Collada->m_AnimationLibrary.m_Animations.size(); i++){
        Animation anim = m_Collada->m_AnimationLibrary.m_Animations.at(i);

        //cout<<"AnimationData::init() -- Channels number "<<anim.m_Channels.size()<<endl;
        if(anim.m_Channels.size() == 16){
            Frame frame(i, m_Collada);
            frame.loadAnimation();
            animations.push_back(frame);
        }
    }
}

/**
 * Computes the next frame
 *
 */
void AnimationData::loadNextFrame(){
    //For all animated joints, compute the next frame
    for(int i = 0; i < animations.size(); i++){
        //cout<<"AnimationData::loadNextFrame() -- Loading animation "<<i<<endl;
        animations.at(i).loadNextFrame();
    }
}
