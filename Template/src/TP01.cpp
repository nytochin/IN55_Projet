﻿#include "TP01.h"


#include "Shapes/Basis.h"
#include "projet.h"

#include <iostream>

using namespace std;


GLfloat angle1 = 30.0f;
GLfloat angle2 = 20.0f;

const GLfloat g_AngleSpeed = 10.0f;


Basis* g_Basis;
Projet* g_Projet;

string texFile = "../../Model/boy_10.JPG";

TP01::TP01()
{
    setWindowTitle(trUtf8("IN55-TP01"));

    g_Basis = new Basis( 10.0 );
    g_Projet = new Projet();
    g_Projet->init();
}


TP01::~TP01()
{
    delete g_Basis;
}


bool
TP01::initializeObjects()
{
	// Fond gris
	glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
	glEnable( GL_DEPTH_TEST );

	// Chargement des shaders
	createShader( "Shaders/color" );

    cout << "Shader color: ";
    if (useShader( "color" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }

    QPixmap *qpix = new QPixmap(texFile.c_str());
    const int NBR_TEXTURES = 1 ;
    GLuint texId[NBR_TEXTURES];
    glEnable(GL_TEXTURE_2D);
    glGenTextures( NBR_TEXTURES, texId );
    glActiveTexture( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, texId[0] );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    int w = qpix->width();
    int h = qpix->height();
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, w, h,
    0, GL_RGBA, GL_UNSIGNED_BYTE, qpix->toImage().bits() );

	return true;
}


void
TP01::render()
{
	// Initialisation de la caméra
	lookAt( 0, 5, 30, 0, 0, 0 );


	// Rendu des objets
	pushMatrix();
		rotate( angle1, 0, 1, 0 );
		rotate( angle2, 1, 0, 0 );

        g_Basis->draw();
        g_Projet->draw();
	popMatrix();
}


void
TP01::keyPressEvent( QKeyEvent* event )
{
	switch( event->key())
	{
		case Qt::Key_Escape:
			close();
			break;

		case Qt::Key_Left:
			angle1 -= g_AngleSpeed;
			break;

		case Qt::Key_Right:
			angle1 += g_AngleSpeed;
			break;

		case Qt::Key_Up:
			angle2 -= g_AngleSpeed;
			break;

		case Qt::Key_Down:
			angle2 += g_AngleSpeed;
			break;

		case Qt::Key_R:
			angle1 = angle2 = 0.0f;
			break;
	}
}
