#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "collada.h"

class Transform
{
public:
    Transform();
    string m_ConcernedNode;

    float m_Time;
    Matrix4 m_TransformJoint;
};

#endif // TRANSFORM_H
