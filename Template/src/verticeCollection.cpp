#include "verticeCollection.h"
#include <iostream>
using namespace std;
VerticeCollection::VerticeCollection(GLuint n)
{
    m_ordered = false;
    //m_vertice = new vertice();
    m_vertice.clear();
}


VerticeCollection::VerticeCollection()
{
    m_ordered = false;
    //m_vertice = new vertice();
    m_vertice.clear();
}

void VerticeCollection::add(vertex v){
    m_vertice.push_back(v);
}

void VerticeCollection::add(texCoord3 tc){
    m_texCoord.push_back(tc);
}

vertice VerticeCollection::get(){
    return m_vertice;
}

vertex VerticeCollection::getAt(int i){
    return m_vertice[i];
}

void VerticeCollection::setAt(int i, vertex v){
    m_vertice[i] = v;
}

GLfloat* VerticeCollection::generateFinalisedVerticeTab(){
    vertice target;
    target = m_verticeOrdered;

    int n = target.size();
    vector<GLfloat>* retVal = new vector<GLfloat>();

    int j = 0;
    for(int i = 0; i < n; i++){
        retVal->push_back(target[i].x);
        retVal->push_back(target[i].y);
        retVal->push_back(target[i].z);
    }

    return retVal->data();
}

GLfloat* VerticeCollection::generateFinalisedColorTab(){
    vertice target;
    target = m_verticeOrdered;

    int n = target.size();
    vector<GLfloat>* retVal = new vector<GLfloat>();

    int j = 0;

    for(int i = 0; i < n; i++){
        retVal->push_back(target[i].color.r);
        retVal->push_back(target[i].color.v);
        retVal->push_back(target[i].color.b);
    }

    return retVal->data();
}

GLfloat* VerticeCollection::generateFinalisedTexCoordTab(){
    TexCoords3 target;
    target = m_TexCoordOrdered;

    int n = target.size();
    vector<GLfloat>* retVal = new vector<GLfloat>();

    int j = 0;
    for(int i = 0; i < n; i++){
        retVal->push_back(target.at(i).s);
        retVal->push_back(target.at(i).t);
    }

    return retVal->data();
}


void VerticeCollection::orderVerticeTab(GLuint tabOrder[], GLuint size){

    m_verticeOrdered.clear();

    for(int i = 0; i < size; i++){
        m_verticeOrdered.push_back(m_vertice.at(tabOrder[i]));
    }
    m_ordered = true;
}

void VerticeCollection::orderTextureTab(GLuint tabOrder[], GLuint size){

    m_TexCoordOrdered.clear();

    for(int i = 0; i < size; i++){
        m_TexCoordOrdered.push_back(m_texCoord.at(tabOrder[i]));
    }
    m_ordered = true;
}
