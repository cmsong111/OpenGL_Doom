#include "map.h"
#include <glut.h>
#include <glu.h>
#include <gl.h>
#include <GLAUX.H>

//p.351
//void loadTexture() {
//	AUX_RGBImageRec* pBottomImage = auxDIBImageLoad("/images/bottom.jpg");
//}

void Doom_map() {
	//Bottom
	glBegin(GL_POLYGON);
	glColor3f(0.349f, 0.231f, 0.145f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();

	//1Wall
	//front
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-20.5f, 0.0f, -21.0f);
	glVertex3f(-20.5f, 6.0f, -21.0f);
	//right
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-20.5f, 6.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, -21.0f);
	glVertex3f(-20.5f, 6.0f, -21.0f);
	glEnd();
	//bottom
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-20.5f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glEnd();
	//back
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 6.0f, 21.0f);
	glEnd();
	//top
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-20.5f, 6.0f, 21.0f);
	glVertex3f(-20.5f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glEnd();
	//left
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glEnd();

	//2Wall
	//front
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glEnd();
	//right
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -20.5f);
	glVertex3f(21.0f, 6.0f, -20.5f);
	glEnd();
	//bottom
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-21.0f, 0.0f, -20.5f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -20.5f);
	glEnd();
	//back
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-21.0f, 6.0f, -20.5f);
	glVertex3f(-21.0f, 0.0f, -20.5f);
	glVertex3f(21.0f, 0.0f, -20.5f);
	glVertex3f(21.0f, 6.0f, -20.5f);
	glEnd();
	//top
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-21.0f, 6.0f, -20.5f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -20.5f);
	glEnd();
	//left
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -20.5f);
	glVertex3f(-21.0f, 6.0f, -20.5f);
	glEnd();

	//3Wall
	//front
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glEnd();
	//right
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glEnd();
	//bottom
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(20.5f, 0.0f, 21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();
	//back
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(20.5f, 6.0f, 21.0f);
	glVertex3f(20.5f, 0.0f, 21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//top
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(20.5f, 6.0f, 21.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//left
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glEnd();


	//4Wall
	//front
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-13.5f, 6.0f, -21.0f);
	glVertex3f(-13.5f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 20.5f);
	glEnd();
	//right
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(14.0f, 6.0f, 21.0f);
	glVertex3f(14.0f, 0.0f, 21.0f);
	glVertex3f(13.5f, 0.0f, 20.5f);
	glVertex3f(13.5f, 6.0f, 20.5f);
	glEnd();
	//bottom
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 0.0f, 21.0f);
	glVertex3f(-13.5f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();
	//back
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 6.0f, -21.0f);
	glVertex3f(-14.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//top
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 6.0f, 21.0f);
	glVertex3f(-13.5f, 6.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//left
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 6.0f, 21.0f);
	glVertex3f(-14.0f, 0.0f, 21.0f);
	glVertex3f(-13.5f, 0.0f, 20.5f);
	glVertex3f(-13.5f, 6.0f, 20.5f);
	glEnd();


	//5Wall
	//front
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 6.0f, -7.0f);
	glEnd();
	//right
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-6.5f, 6.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, 21.0f);
	glVertex3f(-6.5f, 6.0f, 21.0f);
	glEnd();
	//bottom
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 0.0f, 21.0f);
	glVertex3f(-13.5f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();
	//back
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 6.0f, 21.0f);
	glVertex3f(-14.0f, 0.0f, 21.0f);
	glVertex3f(-13.5f, 0.0f, 21.0f);
	glVertex3f(-13.5f, 6.0f, 21.0f);
	glEnd();
	//top
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 6.0f, 21.0f);
	glVertex3f(-13.5f, 6.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//left
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
	glEnd();

	//TEMP Charactor
	glColor3f(1.0f, 1.0f, 0.0f);
	//glutSolidTeapot(0.5);
	glutWireTeapot(0.5);


    return;
}


