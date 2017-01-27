#include "visual_scene.h"

Visual_Scene::Visual_Scene()
{

}

void Visual_Scene::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_ID = src->Attribute("id");
    m_Name = src->Attribute("name");

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("node") == 0){
            Node nd;
            nd.readDataFrom(cur);
            m_Nodes.push_back(nd);
        }
        cur = cur->NextSiblingElement();
    }
}

vector<string> Visual_Scene::getRootIds(){
    vector<string> rootIds;
    int ind = 0;
    while(!m_Nodes.at(ind).hasInstanceController && ind < m_Nodes.size())
        ind++;
    if(ind < m_Nodes.size()){
        Instance_Controller skelControl = m_Nodes.at(ind).m_Instance_Controller;
        for(int i = 0; i<skelControl.m_Skeletons.size(); i++){
            rootIds.push_back(skelControl.m_Skeletons.at(i).m_Skeleton.substr(1));
        }
    }
    return rootIds;
}

Node* Visual_Scene::getParentNodeOf(string childID){
    int i = 0;
    while(i<m_Nodes.size()){
        int j = 0;
        while(j<m_Nodes.at(i).m_Nodes.size() && m_Nodes.at(i).m_Nodes.at(j).m_ID.compare(childID)!=0)
            j++;
        if(j<m_Nodes.at(i).m_Nodes.size()) return &m_Nodes.at(i);
        i++;
    }
    return NULL;
}

Node* Visual_Scene::getNodeById(string ID){
    int index = 0;
    Node* res = NULL;
    do {
        res = m_Nodes.at(index).getNodeByID(ID);
        index++;
    } while (res == NULL && index < m_Nodes.size());
    return res;
}

void Visual_Scene::buildAllSkeletons(){
    vector<string> rootIds = getRootIds();
    Matrix4 m;
        Node* root = getNodeById(rootIds.at(0));
        Node* deform_rig_matrix = getParentNodeOf(root->m_ID);
        deform_rig_matrix->buildLocalMatrix(Matrix4());
        if(root != NULL){
            root->buildGlobalMatrix(m.identity(), deform_rig_matrix->m_LocalTransform, 0);
        }
}

Matrix4 Visual_Scene::getJointBySID(string SID){
    Matrix4 null_Matrix = Matrix4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    Matrix4 res = null_Matrix;
    int index = 0;
    do {
        res = m_Nodes.at(index).getJointBySID(SID);
        index++;
    } while (res == null_Matrix && index < m_Nodes.size());
    return res;
}
