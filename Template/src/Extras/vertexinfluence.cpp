#include "vertexinfluence.h"

VertexInfluence::VertexInfluence()
{

}

VertexInfluence::VertexInfluence(int m_ID, Collada *collada){
    this->m_ID = m_ID;
    this->m_Collada = collada;
}

/** Build the final transformation Matrix by combining all the influencing matrices for a vertex **/
void VertexInfluence::buildFinalTransform(){
    Matrix4 final = Matrix4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    for (int i = 0 ; i < m_Joints.size() ; i++){
        //cout<<"VertexInfluence::buildFinalTransform:: begin"<<endl;
        float w = m_Joints.at(i).m_Weight;
        //cout << " VertexInfluence::buildFinalTransform:: w = "<<w <<endl;
        final +=  w * (m_Joints.at(i).m_Joint * (m_Joints.at(i).m_invBindMatrix * m_bindShapeMatrix));
        //cout << " VertexInfluence::buildFinalTransform:: final = "<<endl<<final <<endl;
    }
    //cout<<" VertexInfluence::buildFinalTransform:: Matrice built for id "<<m_ID<<endl;
    m_finalTransform = final;
}

/** Build a number of joint influences for each vertex
 *
 *@param nbInf: the number of influences to build
 *@param index: the reference to the index of the influence being read
 *
 **/
void VertexInfluence::loadJointInfluences(int nbInf, int &index){
    //cout << "index :" << index << endl;
    for (int i = 0 ; i < nbInf ; i++){
        JointInfluence jinf(index, m_Collada);
        jinf.buildJoint();
        m_Joints.push_back(jinf);
        index+=2;
    }

}

/** Build the boned vertex by applying the final transformation matrix to the related vertex
 *
 *@return the boned vertex
 *
 **/
Vector4 VertexInfluence::getBonedVector(){
    Vector4 v = Vector4(0,0,0,0);
    float totalWeight = 0.0f;
    float normalized;
    for (int i = 0 ; i < m_Joints.size() ; i++){
        //cout<<"VertexInfluence::buildFinalTransform:: begin"<<endl;
        float w = m_Joints.at(i).m_Weight;
//        cout << " VertexInfluence::getBonedVector:: BSM = "<<endl<<m_bindShapeMatrix <<endl;
//        cout << " VertexInfluence::getBonedVector:: IBM = "<<endl<<m_Joints.at(i).m_invBindMatrix <<endl;
//        cout << " VertexInfluence::getBonedVector:: JM = "<<endl<<m_Joints.at(i).m_Joint <<endl;
        Matrix4 skinningMatrix = (m_Joints.at(i).m_invBindMatrix * m_Joints.at(i).m_Joint);
        Vector4 vertexByBSM = m_Vertex * m_bindShapeMatrix;

//        cout << "Vertex " << m_ID << endl;
//        cout << skinningMatrix[0] << " " << skinningMatrix[4] << " " << skinningMatrix[8] << " " << skinningMatrix[12] << endl;
//        cout << skinningMatrix[1] << " " << skinningMatrix[5] << " " << skinningMatrix[9] << " " << skinningMatrix[13] << endl;
//        cout << skinningMatrix[2] << " " << skinningMatrix[6] << " " << skinningMatrix[10] << " " << skinningMatrix[14] << endl;
//        cout << skinningMatrix[3] << " " << skinningMatrix[7] << " " << skinningMatrix[11] << " " << skinningMatrix[15] << endl;

//        cout << "Vertex " << m_ID << endl;
//        cout << vertexByBSM.x << " " << vertexByBSM.y << " " << vertexByBSM.z << " " << vertexByBSM.w << endl << endl;

//        Vector4 testRes = vertexByBSM * skinningMatrix;
//        cout << "Prod of Vertex " << m_ID << endl;
//        cout << testRes.x << " " << testRes.y << " " << testRes.z << " " << testRes.w << endl << endl;


        v += (vertexByBSM * skinningMatrix * w);
//        cout << "Vertex " << m_ID << endl;
//        cout << skinningMatrix[0] << " " << skinningMatrix[4] << " " << skinningMatrix[8] << " " << skinningMatrix[12] << endl;
//        cout << skinningMatrix[1] << " " << skinningMatrix[5] << " " << skinningMatrix[9] << " " << skinningMatrix[13] << endl;
//        cout << skinningMatrix[2] << " " << skinningMatrix[6] << " " << skinningMatrix[10] << " " << skinningMatrix[14] << endl;
//        cout << skinningMatrix[3] << " " << skinningMatrix[7] << " " << skinningMatrix[11] << " " << skinningMatrix[15] << endl;
        //v += m_Joints.at(i).m_Joint * m_Joints.at(i).m_invBindMatrix * m_bindShapeMatrix * m_Vertex * w;
        //v +=  w * (skinningMatrix * (m_bindShapeMatrix * m_Vertex));
        //cout << "Vertex " << m_ID << " " << i << endl;
        //cout << m_Vertex[0] << " " << m_Vertex[1] << " " << m_Vertex[2] << " " << m_Vertex[3] << endl;
        //v += m_Joints.at(i).m_Joint * m_Joints.at(i).m_invBindMatrix * m_bindShapeMatrix * m_Vertex * w;
        //cout << " VertexInfluence::buildFinalTransform:: final = "<<endl<<final <<endl;
        totalWeight += w;
    }
    if (totalWeight != 1.0f){
        normalized = 1.0f / totalWeight;
        v *= normalized;
    }
    return v;
}

void VertexInfluence::buildBindShapeMatrix(){
    float * bsm = m_Collada->m_ControllerLibrary.m_Controller.m_Skin.m_Bind_Shape_Matrix.m_Floats;
    m_bindShapeMatrix = Matrix4(bsm);
}




