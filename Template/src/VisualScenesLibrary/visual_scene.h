#ifndef VISUAL_SCENE_H
#define VISUAL_SCENE_H
#include "visualSceneDef.h"
#include "node.h"

typedef struct animatData_t{
    string targetID;
    Matrix4 Joint;
}AnimatData;

class Visual_Scene
{
public:
    Visual_Scene();
    void readDataFrom(TiXmlElement *src);
    vector<string> getRootIds();
    Matrix4 getJointBySID(string SID);
    Node* getNodeById(string ID);
    Node* getParentNodeOf(string childID);
    void buildAllSkeletons();
    void applyAnimation(vector<AnimatData> animDatas);

    string m_ID;
    string m_Name;
    vector<Node> m_Nodes;
};

#endif // VISUAL_SCENE_H
