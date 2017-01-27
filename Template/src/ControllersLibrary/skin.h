#ifndef SKIN_H
#define SKIN_H
#include "controllerDef.h"
#include "vertex_weights.h"
#include "CommonElements/source.h"
#include "bind_shape_matrix.h"
#include "joints.h"

class Skin
{
public:
    Skin();
    void readDataFrom(TiXmlElement *src);
    Source findSource(string srcID);
    void buildInverseBindMatrices();


    vector<Matrix4> m_InvBindMatrices;
    string m_Source;
    Bind_Shape_Matrix m_Bind_Shape_Matrix;
    vector<Source> m_Sources;
    Joints m_Joints;
    Vertex_Weights m_Vertex_Weights;
};

#endif // SKIN_H
