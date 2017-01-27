#ifndef JOINTINFLUENCE_H
#define JOINTINFLUENCE_H
#include "CommonElements/Matrices.h"
#include "collada.h"

class JointInfluence
{
public:
    JointInfluence();
    JointInfluence(int m_ID, Collada *collada);

    void buildJoint();

    Collada* m_Collada;
    int m_ID;
    int m_Woffset;
    int m_Joffset;
    Matrix4 m_Joint;
    Matrix4 m_invBindMatrix;
    float m_Weight;

};

#endif // JOINTINFLUENCE_H
