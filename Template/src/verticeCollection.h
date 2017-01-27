#ifndef VERTICECOLLECTION_H
#define VERTICECOLLECTION_H

#define DIMENSION 3

#include "vertex.h"
#include <vector>

typedef std::vector<vertex> vertice;
typedef std::vector<texCoord3> TexCoords3;
class VerticeCollection
{
public:
    VerticeCollection(GLuint n);
    VerticeCollection();
private:
    vertice m_vertice;
    vertice m_verticeOrdered;
    TexCoords3 m_texCoord;
    TexCoords3 m_TexCoordOrdered;
    bool m_ordered;
public:
    void add(vertex v);
    void add(texCoord3 tc);
    vertice get();
    vertex getAt(int i);
    void setAt(int i, vertex v);
    GLfloat* generateFinalisedVerticeTab();
    GLfloat* generateFinalisedColorTab();
    GLfloat* generateFinalisedTexCoordTab();
    void orderVerticeTab(GLuint tabOrder[], GLuint size);
    void orderTextureTab(GLuint tabOrder[], GLuint size);
};

#endif // VERTICECOLLECTION_H
