#ifndef PROJET_H
#define PROJET_H
#include <algorithm>    // std::copy
#include "Object3D.h"
#include "collada.h"
#include "verticeCollection.h"
#include "Extras/vertexinfluence.h"
#include "Extras/animationdata.h"
#include <string>

#include "gl_tinyxml_collada-master/tinyxml/tinyxml.h"
#include "gl_tinyxml_collada-master/tinyxml/tinystr.h"
using namespace std;


class Projet : public Object3D
{
public:
    Projet();
    VerticeCollection *m_Vertices;
    VerticeCollection *m_VerticesTexture;
    GLfloat *m_TabVerticeIndices;
    GLfloat* m_Colors;
    GLfloat* m_texCoord;
    GLuint m_nbVertices;
    GLuint m_nbTextures;
    vector<VertexInfluence> m_VertexInfluences;
    AnimationData m_KeyFrames;
    Collada m_Collada;
    vector<Vector4> allVertices;
    vector<Vector4> allTextures;

    void init();
    void drawShape();

private:
    void loadInfluences();
    void computeRendering();
};

#endif // GEOMETRY_H
