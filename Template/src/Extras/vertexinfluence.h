#ifndef VERTEXINFLUENCE_H
#define VERTEXINFLUENCE_H
#include "CommonElements/Matrices.h"
#include "jointinfluence.h"

class VertexInfluence
{
public:
    VertexInfluence();
    VertexInfluence(int m_ID, Collada *collada);
    void buildFinalTransform();
    void buildBindShapeMatrix();
    void loadJointInfluences(int nbInf, int &index);
    Vector4 getBonedVector();

    Collada *m_Collada;
    Vector4 m_Vertex;
    vector<JointInfluence> m_Joints;
    Matrix4 m_finalTransform;
    Matrix4 m_bindShapeMatrix;
    int m_ID;
};

#endif // VERTEXINFLUENCE_H
