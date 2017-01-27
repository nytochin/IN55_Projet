#include "frame.h"

Frame::Frame(int ID, Collada *collada)
{
    this->m_Collada = collada;
    this->m_ID = ID;
    currentFrame = -1;
    frameDirection = 1;
    //cout<<"Frame::construct Collada Pointer: "<<this->m_Collada<<endl;
}

void Frame::loadAnimation(){
    frameSize = 0;
    totalTime = 0.0f;
    for(int i = 0; i < m_Collada->m_AnimationLibrary.m_Animations.at(m_ID).m_Channels.size(); i++){
        ChannelAttr ca = m_Collada->m_AnimationLibrary.m_Animations.at(m_ID).m_Channels.at(i).getAttributes();
        Sampler samp = m_Collada->m_AnimationLibrary.m_Animations.at(m_ID).findSampler(ca.source);
        InputAttributes iia = samp.getAttributes("INPUT");
        InputAttributes oia = samp.getAttributes("OUTPUT");
        Source iSrc = m_Collada->m_AnimationLibrary.m_Animations.at(m_ID).findSource(iia.m_Source);
        Source oSrc = m_Collada->m_AnimationLibrary.m_Animations.at(m_ID).findSource(oia.m_Source);
        AnimElement ae;
        ae.times = iSrc.m_Float_Array;
        ae.elements = oSrc.m_Float_Array;
        ae.target = ca.transTarget;

        // Get the number of frames
        if(ae.times.m_Count > frameSize) frameSize = ae.times.m_Count;
        if(totalTime < ae.times.getAt(ae.times.m_Count-1))totalTime = ae.times.getAt(ae.times.m_Count-1);

        m_AnimatJointData.push_back(ae);
    }
    stepTime = totalTime/TOTAL_FRAME;
}

/**
 * Loads the next frame of the animated joint
 *
 */
void Frame::loadNextFrame(){
    //Initially set to -1, currentFrame will increase with a step of frameDirection.
    //frameDirection can eather be 1 or -1, depending on the rechability of the end of frames

    //For forward and backward moves, uncomment this part and comment the next part
//    currentFrame += frameDirection;
//    if(currentFrame == frameSize) frameDirection = -1;
//    else if(currentFrame == 0) frameDirection = 1;

    //currentFrame = ++currentFrame%frameSize;

    currentFrame = ++currentFrame%TOTAL_FRAME;
    //cout<<"Frame::loadNextFrame() -- Loading frame "<<currentFrame<<" / "<<frameSize<<endl;
    applyAnimation(currentFrame);
}

Matrix4 Frame::buildAnimJoint(int frameNum){
    float jRes[16];
    for(int i = 0; i < m_AnimatJointData.size(); i++){
        TransformTarget curTransform = m_AnimatJointData.at(i).target;
        if(curTransform.rowNum == 3 && curTransform.colNum == 3)
            jRes[4*curTransform.rowNum + curTransform.colNum] = 1.0f; //This element is always set to 1.0f. Some documents usually export it with a wrong value
        else if(m_AnimatJointData.at(i).elements.m_Count > frameNum){
            //cout<<"Frame num: "<<frameNum;
            jRes[4*curTransform.rowNum + curTransform.colNum] = m_AnimatJointData.at(i).elements.getAt(frameNum);
        }
        else
            jRes[4*curTransform.rowNum + curTransform.colNum] = m_AnimatJointData.at(i).elements.getAt(m_AnimatJointData.at(i).elements.m_Count - 1);
    }
    return Matrix4(jRes);
}

void Frame::applyAnimation(int frameNum){
    string targetJoint = m_AnimatJointData.at(0).target.targetID;
    //cout<<"applyAnimation:: Target joint: "<<targetJoint<<endl;
    Node* targetNode = m_Collada->m_VisualScenesLibrary.m_Visual_Scene.getNodeById(targetJoint);

    float currentTime = frameNum*stepTime;
    float lBound;
    float uBound;
    findTimeBounds(currentTime, lBound, uBound);

    //Interpolation factor: u = (t - ti)/(ti+1 - ti)
    float u = (currentTime - lBound)/(uBound - lBound);
    int frame1 = getFrameOf(lBound);
    int frame2 = getFrameOf(uBound);

    if(targetNode) {
        targetNode->m_LocalTransform = interpolate(frame1, frame2, u);
        //cout<<"applyAnimation()::"<<endl<<"Current node: "<<targetNode->m_ID<<endl<<"Current frame: "<<frameNum<<endl<<"Current transform: "<<endl<<targetNode->m_LocalTransform<<endl;
        targetNode->m_animated = true;
    }
}

void Frame::findTimeBounds(float currentTime, float& lBound, float& uBound){
    int i = 0;
    //Finding the first lower and upper bounds that containts currentTime
    while(i < frameSize && m_AnimatJointData.at(0).times.getAt(i) <= currentTime)
        i++;
    if(i<frameSize){
        //The first lower time is the previous time that is directly <= currentTime
        lBound = m_AnimatJointData.at(0).times.getAt(i-1);

        //The first upper time is the next time that is directly > currentTime
        uBound = m_AnimatJointData.at(0).times.getAt(i);
    }else{
        lBound = m_AnimatJointData.at(0).times.getAt(i-2);
        uBound = m_AnimatJointData.at(0).times.getAt(i-1);
    }
}

int Frame::getFrameOf(float time){
    //for(int i = 0; i < m_AnimatJointData.size(); i++){
        int noFrame = 0;
        while(noFrame < frameSize && m_AnimatJointData.at(0).times.getAt(noFrame) != time)
            noFrame++;
        if(noFrame < frameSize)
            return noFrame;
    //}
    return -1;
}

Matrix4 Frame::interpolate(int frame1, int frame2, float time){
    Matrix4 matFrame1 = buildAnimJoint(frame1);
    Matrix4 matFrame2 = buildAnimJoint(frame2);
    Matrix4 matFrameResult;
    for(int i = 0; i< 16; i++){
        matFrameResult[i] = time*matFrame2[i] + (1-time)*matFrame1[i];
    }
    return matFrameResult;
}

