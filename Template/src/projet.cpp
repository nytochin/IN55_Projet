#include <QCoreApplication>
#include "projet.h"

#include <iostream>
#include <strstream>
#include <string>
using namespace std;

const string model = "..\\..\\Model\\astroBoy_walk_Max.dae";

Projet::Projet(){

}

void Projet::init()
{
    m_Vertices = NULL;
    m_VerticesTexture = NULL;
    TiXmlDocument doc(model.c_str());
    doc.LoadFile();

    TiXmlElement *root = doc.RootElement();

    TiXmlElement *elmnt = root->FirstChildElement();

    //Collada collada;

    m_Collada.readGeometries(elmnt);
    m_Collada.readControllers(elmnt);
    m_Collada.readVisualScenes(elmnt);
    m_Collada.readAnimations(elmnt);


    m_KeyFrames = AnimationData(&m_Collada);

    cout << "Initializing frames " <<endl;
    m_KeyFrames.init();
    cout << " Done!" <<endl;

    cout << "Initializing vertices " <<endl;
    allVertices = m_Collada.m_GeometryLibrary.m_Geometries.at(0).m_Mesh.getVertices();
    cout << " Done!" <<endl;

    cout << "Initializing Texture coordinates " <<endl;
    allTextures = m_Collada.m_GeometryLibrary.m_Geometries.at(0).m_Mesh.getTextures();
    cout << " Done!" <<endl;
}

void Projet::loadInfluences(){
    int count = m_Collada.m_ControllerLibrary.m_Controller.m_Skin.m_Vertex_Weights.m_Count;
    m_Collada.m_VisualScenesLibrary.m_Visual_Scene.buildAllSkeletons();
    int index = 0;
    for (int i = 0 ; i < count ; i++){
        VertexInfluence vi(i, &m_Collada);
        vi.loadJointInfluences(m_Collada.m_ControllerLibrary.m_Controller.m_Skin.m_Vertex_Weights.m_Vcount.m_Vcounts[i], index);

        vi.m_Vertex = allVertices.at(i);
        m_VertexInfluences.push_back(vi);
    }
}

void Projet::computeRendering(){

    if(m_Vertices) delete m_Vertices;
    if(m_VerticesTexture) delete m_VerticesTexture;
    m_VertexInfluences.clear();

    // Colors
    color_t red, green, blue;
    red.r = green.v = blue.b = 1.0f;
    red.v = red.b = green.r = green.b = blue.r = blue.v = 0.0f;

    // Initializing vertices and textures
    m_Vertices = new VerticeCollection();
    m_VerticesTexture = new VerticeCollection();
    vertex v;
    texCoord3 texC;
    v.color = red;

    m_KeyFrames.loadNextFrame();
    loadInfluences();

    Vector4 vi;
    for (GLint i = 0; i < m_VertexInfluences.size() ; i++){
        vi = m_VertexInfluences.at(i).getBonedVector();
        v.x = vi.x;
        v.y = vi.y;
        v.z = vi.z;

        m_Vertices->add(v);
    }

    Vector4 tc;
    for (GLint i = 0; i < allTextures.size() ; i++){
        tc = allTextures.at(i);
        texC.s = tc.x;
        texC.t = tc.y;

        m_VerticesTexture->add(texC);
    }

    //Ordering vertices and textures
    vector<GLuint> *tabOrder = new vector<GLuint>();
    vector<GLuint> *tabOrderTextures = new vector<GLuint>();

    for(int j = 0; j< m_Collada.m_GeometryLibrary.m_Geometries.at(0).m_Mesh.m_Triangles.size(); j++){
        P p = m_Collada.m_GeometryLibrary.m_Geometries.at(0).m_Mesh.m_Triangles.at(j).m_P;

        for (GLint i = 0; i < p.m_Count ; i += 3){
           tabOrder->push_back(p.m_Indices[i]);
           tabOrderTextures->push_back(p.m_Indices[i+2]);
        }
    }

    m_nbVertices = tabOrder->size();
    m_nbTextures = tabOrderTextures->size();

    m_Vertices->orderVerticeTab(tabOrder->data(), m_nbVertices);
    m_VerticesTexture->orderTextureTab(tabOrderTextures->data(), m_nbTextures);

    m_TabVerticeIndices = m_Vertices->generateFinalisedVerticeTab();
    m_Colors = m_Vertices->generateFinalisedColorTab();
    m_texCoord = m_VerticesTexture->generateFinalisedTexCoordTab();

}

void Projet::drawShape()
{

    computeRendering();
    glUniform1i( glGetUniformLocation( 0, "texId" ), 1 );
    GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
    glEnableVertexAttribArray( var1 );
    glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, m_TabVerticeIndices );
    GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
    glEnableVertexAttribArray( var2 );
    glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, m_Colors );
    GLint var3 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "texCoord" );
    glEnableVertexAttribArray( var3 );
    glVertexAttribPointer( var3, 2, GL_FLOAT, GL_FALSE, 0, m_texCoord );
    glDrawArrays( GL_TRIANGLES, 0, m_nbVertices );
    glDisableVertexAttribArray( var1 );
    glDisableVertexAttribArray( var2 );
    glDisableVertexAttribArray( var3 );
}

