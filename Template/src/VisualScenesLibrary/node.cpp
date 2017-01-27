#include "node.h"

int Node::numJoint = 0;
Node::Node()
{
    m_GlobalBuilt = false;
    hasInstanceController = false;
    m_LocalBuilt = false;
    m_animated = false;
}

Node::Node(string ID){
    m_ID = ID;
}

void Node::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_ID = src->Attribute("id") ? src->Attribute("id") :"";
    m_Name = src->Attribute("name") ? src->Attribute("name"):"";
    m_Type = src->Attribute("type") ? src->Attribute("type") :"";
    m_SID = src->Attribute("sid") ? src->Attribute("sid") : "";

    TiXmlElement *cur = src->FirstChildElement();
    while(cur){
        if(string(cur->Value()).compare("matrix") == 0){
            m_Matrix.readDataFrom(cur);
        }
        else if(string(cur->Value()).compare("node") == 0){
            Node nd;
            nd.readDataFrom(cur);
            m_Nodes.push_back(nd);
        }
        else if(string(cur->Value()).compare("instance_controller") == 0){
            m_Instance_Controller.readDataFrom(cur);
            hasInstanceController = true;
        }
        cur = cur->NextSiblingElement();
    }
}

void Node::animate(Matrix4 animatedJoint){
    m_LocalTransform = animatedJoint;
    m_LocalBuilt = true;
}

void Node::buildLocalMatrix(Matrix4 tr){
    if(m_LocalBuilt) return;
    if(m_animated){
        m_LocalTransform *= tr;
//        cout << "Local Transformation " << m_SID << endl;
//        cout << m_LocalTransform<< endl;
        return;
    }
    m_LocalTransform = Matrix4(m_Matrix.m_Values)*tr;
//    cout << "Local Transformation " << m_ID << endl;
//    cout << m_LocalTransform<< endl;
//    cout << m_LocalTransform[0] << " " << m_LocalTransform[4] << " " << m_LocalTransform[8] << " " << m_LocalTransform[12] << endl;
//    cout << m_LocalTransform[1] << " " << m_LocalTransform[5] << " " << m_LocalTransform[9] << " " << m_LocalTransform[13] << endl;
//    cout << m_LocalTransform[2] << " " << m_LocalTransform[6] <<" " << m_LocalTransform[10] << " " << m_LocalTransform[14] << endl;
//    cout << m_LocalTransform[3] << " " << m_LocalTransform[7] << " " << m_LocalTransform[11] << " " << m_LocalTransform[15] << endl;
    m_LocalBuilt = true;
}

void Node::buildGlobalMatrix(Matrix4 m_ParentMatrix, Matrix4 tr, int depth){
//    for (int i = 0 ; i < depth ; i++){
//        cout << "  " ;
//    }
//    //cout << "Node " << m_ID << endl;
    if(m_Type.compare("NODE") !=0 ){
        //if (m_Type.compare("JOINT") != 0 || m_GlobalBuilt) return;
        //cout << "Node "<<++Node::numJoint<<" ID: "<<m_ID<<endl;
        buildLocalMatrix(tr);
        m_GlobalTransform = m_LocalTransform*m_ParentMatrix;
        for (int i = 0 ; i < m_Nodes.size() ; i++){
            m_Nodes.at(i).buildGlobalMatrix(m_GlobalTransform, Matrix4(), depth + 1);
        }
        m_GlobalBuilt = true;
    }else{
        buildLocalMatrix(Matrix4());
        for (int i = 0 ; i < m_Nodes.size() ; i++){
            m_Nodes.at(i).buildGlobalMatrix(m_ParentMatrix, m_LocalTransform, depth + 1);
        }
    }
}

Node *Node::getNodeByID(string ID){
    if(m_ID.compare(ID) == 0)
        return this;
    if(m_Nodes.size() == 0)
        return NULL;
    Node* res = NULL;
    int index = 0;
    do {
        res = m_Nodes.at(index).getNodeByID(ID);
        index++;
    } while (res == NULL && index < m_Nodes.size());
    return res;
}

Matrix4 Node::getJointBySID(string SID){
    Matrix4 null_Matrix = Matrix4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    if (m_SID.compare(SID) == 0){
//        buildLocalMatrix();
  //      return m_LocalTransform;
        //cout << "Joint SID: " << SID<<endl;
        //buildGlobalMatrix(m_GlobalTransform, 50);
        //if(m_animated) return m_LocalTransform;
        return m_GlobalTransform;
    }
    if (m_Nodes.size() == 0){
        return null_Matrix;
    }
    Matrix4 res = null_Matrix;
    int index = 0;
    do {
        res = m_Nodes.at(index).getJointBySID(SID);
        index++;
    } while (res == null_Matrix && index < m_Nodes.size());
    return res;

}

