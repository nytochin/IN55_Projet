#ifndef VERTEX_H
#define VERTEX_H

#endif // VERTEX_H
#include "AbstractFramework.h"
#define DIMENSION 3

typedef struct texCoord2{
    GLfloat s;
    GLfloat t;
}texCoord2;


typedef struct texCoord3{
    GLfloat s;
    GLfloat t;
    GLfloat p;
}texCoord3;

typedef struct color{
    GLfloat r;
    GLfloat v;
    GLfloat b;
} color_t;

typedef struct vertex{
    GLfloat x;
    GLfloat y;
    GLfloat z;
    color_t color;
    texCoord3 tex;
} vertex;
