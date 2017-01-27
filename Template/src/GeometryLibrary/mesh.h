#ifndef MESH_H
#define MESH_H
#include <vector>
#include <Vectors.h>
#include "CommonElements/source.h"
#include "triangles.h"
#include "vertices.h"
using namespace std;

class Mesh
{
public:
    Mesh();
    void readDataFrom(TiXmlElement *src);
    vector<Vector4> getVertices();
    vector<Vector4> getTextures();
    Source findSource(string srcID);
//private:
    vector<Source> m_Sources;
    Vertices m_Vertices;
    vector<Triangles> m_Triangles;



};

#endif // MESH_H
