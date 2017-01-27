#include "jointinfluence.h"

JointInfluence::JointInfluence()
{

}

JointInfluence::JointInfluence(int m_ID, Collada *collada)
{
    this->m_ID = m_ID;
    this->m_Collada = collada;
}

void JointInfluence::buildJoint(){
    InputAttributes ia = m_Collada->m_ControllerLibrary.m_Controller.m_Skin.m_Vertex_Weights.getAttributes("WEIGHT");
    int wind = m_Collada->m_ControllerLibrary.m_Controller.m_Skin.m_Vertex_Weights.m_V.m_Indices[m_ID+ia.m_Offset];
    m_Weight = m_Collada->m_ControllerLibrary.m_Controller.getWeight(ia.m_Source, wind);
//    cout << "m_Weight " << m_ID << " " << m_Weight << endl;

    ia = m_Collada->m_ControllerLibrary.m_Controller.m_Skin.m_Vertex_Weights.getAttributes("JOINT");
    int ind = m_Collada->m_ControllerLibrary.m_Controller.m_Skin.m_Vertex_Weights.m_V.m_Indices[m_ID+ia.m_Offset];
    string SID = m_Collada->m_ControllerLibrary.m_Controller.getJointSID(ia.m_Source, ind);
    m_Joint = m_Collada->m_VisualScenesLibrary.m_Visual_Scene.getJointBySID(SID);
//    cout << "m_Joint " << SID << endl;
//    cout << m_Joint[0] << " " << m_Joint[4] << " " << m_Joint[8] << " " << m_Joint[12] << endl;
//    cout << m_Joint[1] << " " << m_Joint[5] << " " << m_Joint[9] << " " << m_Joint[13] << endl;
//    cout << m_Joint[2] << " " << m_Joint[6] << " " << m_Joint[10] << " " << m_Joint[14] << endl;
//    cout << m_Joint[3] << " " << m_Joint[7] << " " << m_Joint[11] << " " << m_Joint[15] << endl;


    ia = m_Collada->m_ControllerLibrary.m_Controller.m_Skin.m_Joints.getAttributes("INV_BIND_MATRIX");
    Source iBMSrc = m_Collada->m_ControllerLibrary.m_Controller.m_Skin.findSource(ia.m_Source);
    m_invBindMatrix = iBMSrc.m_Float_Array.readMatrixAt(ind);

//    int ind = m_Collada.m_ControllerLibrary.m_Controller.m_Skin.m_Vertex_Weights.m_V.m_Indices[m_ID+ia.m_Offset];
//    string SID = m_Collada.m_ControllerLibrary.m_Controller.getJointSID(ia.m_Source, ind);
//    m_Joint = m_Collada.m_VisualScenesLibrary.m_Visual_Scene.getJointBySID(SID);
//    m_invBindMatrix = m_Collada.m_ControllerLibrary.m_Controller.m_Skin.m_InvBindMatrices.at(ind);
}

