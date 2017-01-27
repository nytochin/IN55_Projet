#ifndef NODE_H
#define NODE_H
#include "visualSceneDef.h"
#include "instance_controller.h"
#include "CommonElements/Matrices.h"

class Node
{
public:
    Node();
    Node(string ID);

    static int numJoint;
    bool m_LocalBuilt;
    bool m_animated;

    void readDataFrom(TiXmlElement *src);
    void animate(Matrix4 animatedJoint);
    void buildLocalMatrix(Matrix4 tr);
    void buildGlobalMatrix(Matrix4 m_ParentMatrix, Matrix4 tr, int depth);
    Matrix4 getJointBySID(string SID);
    Node* getNodeByID(string ID);

    bool m_GlobalBuilt;
    string m_ID;
    string m_Name;
    string m_SID;
    string m_Type;
    Matrix m_Matrix;

    Matrix4 m_LocalTransform;
    Matrix4 m_GlobalTransform;

    vector<Node> m_Nodes;
    Instance_Controller m_Instance_Controller;

    bool hasInstanceController;
};

#endif // NODE_H
