#ifndef FRAME_H
#define FRAME_H
#include "transform.h"

const int TOTAL_FRAME = 15;

class Frame
{
public:
    Frame(int ID, Collada *collada);
    void loadAnimation();
    void loadNextFrame();

private:
    Matrix4 buildAnimJoint(int frameNum);
    void applyAnimation(int frameNum);
    Matrix4 interpolate(int frame1, int frame2, float time);
    int getFrameOf(float time);
    void findTimeBounds(float currentTime, float& lBound, float& uBound);

    Collada* m_Collada;
    vector<Transform> m_Transforms;
    int m_ID;
    int currentFrame;
    int frameDirection;
    int frameSize;
    float totalTime;
    float stepTime;
    Matrix4 m_NextJoint;
    string m_TargetJoint;

public:
    vector<AnimElement> m_AnimatJointData;

};



#endif // FRAME_H
