#include "map.h"
#include <glut.h>
#include <glu.h>
#include <gl.h>
#include <GLAUX.H>
#include <windows.h>
#include <stdlib.h>


//GLuint g_textureID = 1;
//
//struct Vertex
//{
//	float tu, tv;
//	float x, y, z;
//};
//
//Vertex g_quadVertices[] = {
//	{0.0f,0.0f,-1.0f,-1.0f,0.0f},
//	{1.0f,0.0f,1.0f,-1.0f,0.0f},
//	{1.0f,1.0f,1.0f,1.0f,0.0f},
//	{0.0f,1.0f,-1.0f,1.0f,0.0f}
//};
//
//void loadTexture() {
//	AUX_RGBImageRec* pBottomImage = auxDIBImageLoad(L"images/bottom.bmp");
//
//	if (pBottomImage != NULL) {
//		glGenTextures(1, &g_textureID);
//		glBindTexture(GL_TEXTURE_2D, g_textureID);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		glTexImage2D(GL_TEXTURE_2D, 0, 3, pBottomImage->sizeX,
//			pBottomImage->sizeY, 0, GL_RGB,
//			GL_UNSIGNED_BYTE, pBottomImage->data);
//	}
//	if (pBottomImage) {
//		if (pBottomImage->data)
//			free(pBottomImage->data);
//		free(pBottomImage);
//	}
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

	//TOPWALL
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();

	//1Wall
	//front
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-20.5f, 0.0f, -21.0f);
	glVertex3f(-20.5f, 6.0f, -21.0f);

	//right
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(-20.5f, 6.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, -21.0f);
	glVertex3f(-20.5f, 6.0f, -21.0f);

	//bottom
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(-20.5f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, 21.0f);

	//back
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 6.0f, 21.0f);

	//top
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(-20.5f, 6.0f, 21.0f);
	glVertex3f(-20.5f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);

	//left
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glEnd();

	//2Wall
	glBegin(GL_QUADS);
	//front
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	//right
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -20.5f);
	glVertex3f(21.0f, 6.0f, -20.5f);
	//bottom
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(-21.0f, 0.0f, -20.5f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -20.5f);
	//back
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(-21.0f, 6.0f, -20.5f);
	glVertex3f(-21.0f, 0.0f, -20.5f);
	glVertex3f(21.0f, 0.0f, -20.5f);
	glVertex3f(21.0f, 6.0f, -20.5f);
	//top
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(-21.0f, 6.0f, -20.5f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -20.5f);
	//left
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -20.5f);
	glVertex3f(-21.0f, 6.0f, -20.5f);
	glEnd();

	//3Wall
	//front
	glBegin(GL_QUADS);
	glColor3f(0.5f, 1.0f, 1.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	//right
	glColor3f(0.5f, 1.0f, 1.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	//bottom
	glColor3f(0.5f, 1.0f, 1.0f);
	glVertex3f(20.5f, 0.0f, 21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	//back
	glColor3f(0.5f, 1.0f, 1.0f);
	glVertex3f(20.5f, 6.0f, 21.0f);
	glVertex3f(20.5f, 0.0f, 21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	//top
	glColor3f(0.5f, 1.0f, 1.0f);
	glVertex3f(20.5f, 6.0f, 21.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	//left
	glColor3f(0.5f, 1.0f, 1.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glEnd();


	//4Wall
	//front
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-7.0f, 6.0f, 20.5f);
	glVertex3f(-7.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 20.5f);
	//right
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.0, 6.0f, 20.5f);
	glVertex3f(21.0, 0.0f, 20.5f);
	glVertex3f(21.0, 0.0f, 21.0f);
	glVertex3f(21.0, 6.0f, 21.0f);
	//bottom
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	//back
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	//top
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
	glVertex3f(-7.0f, 6.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	//left
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-7.0, 6.0f, 20.5f);
	glVertex3f(-7.0, 0.0f, 20.5f);
	glVertex3f(-7.0, 0.0f, 21.0f);
	glVertex3f(-7.0, 6.0f, 21.0f);
	glEnd();


	//5Wall
	//front
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 6.0f, -7.0f);
	//right
	glColor3f(0.0f, 1.0f, 0.5f);
	glVertex3f(-6.5f, 6.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, 21.0f);
	glVertex3f(-6.5f, 6.0f, 21.0f);
	
	//bottom
	glColor3f(0.0f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, 21.0f);
	
	//back
	glColor3f(0.0f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-6.5f, 0.0f, 21.0f);
	glVertex3f(-6.5f, 6.0f, 21.0f);
	//top
	glColor3f(0.0f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(-6.5f, 6.0f, -7.0f);
	glVertex3f(-6.5f, 6.0f, 21.0f);
	//left
	glColor3f(0.0f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glEnd();

	//6Wall
	//front
	glBegin(GL_QUADS);
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 6.0f, -7.0f);
	//right
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(7.0f, 6.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -6.5f);
	glVertex3f(7.0f, 6.0f, -6.5f);
	
	//bottom
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 0.0f, -6.5f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -6.5f);
	
	//back
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 6.0f, -6.5f);
	glVertex3f(-7.0f, 0.0f, -6.5f);
	glVertex3f(7.0f, 0.0f, -6.5f);
	glVertex3f(7.0f, 6.0f, -6.5f);
	//top
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 6.0f, -6.5f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(7.0f, 6.0f, -7.0f);
	glVertex3f(7.0f, 6.0f, -6.5f);
	//left
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(-7.0f, 0.0f, -6.5f);
	glVertex3f(-7.0f, 6.0f, -6.5f);
	glEnd();

	//7Wall
	//front
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.0f, 0.5f);
	glVertex3f(6.5f, 6.0f, -7.0f);
	glVertex3f(6.5f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 6.0f, -7.0f);
	//right
	glColor3f(0.8f, 0.0f, 0.5f);
	glVertex3f(7.0f, 6.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, 7.0f);
	glVertex3f(7.0f, 6.0f, 7.0f);
	
	//bottom
	glColor3f(0.8f, 0.0f, 0.5f);
	glVertex3f(6.5f, 0.0f, 7.0f);
	glVertex3f(6.5f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, 7.0f);
	
	//back
	glColor3f(0.8f, 0.0f, 0.5f);
	glVertex3f(6.5f, 6.0f, 7.0f);
	glVertex3f(6.5f, 0.0f, 7.0f);
	glVertex3f(7.0f, 0.0f, 7.0f);
	glVertex3f(7.0f, 6.0f, 7.0f);
	//top
	glColor3f(0.8f, 0.0f, 0.5f);
	glVertex3f(6.5f, 6.0f, 7.0f);
	glVertex3f(6.5f, 6.0f, -7.0f);
	glVertex3f(7.0f, 6.0f, -7.0f);
	glVertex3f(7.0f, 6.0f, 7.0f);
	//left
	glColor3f(0.8f, 0.0f, 0.5f);
	glVertex3f(-6.5f, 6.0f, 7.0f);
	glVertex3f(-6.5f, 0.0f, 7.0f);
	glVertex3f(6.5f, 0.0f, 7.0f);
	glVertex3f(6.5f, 6.0f, 7.0f);
	glEnd();

	//TEMP Charactor
	glColor3f(1.0f, 1.0f, 0.0f);
	//glutSolidTeapot(0.5);
	glutWireTeapot(0.5);


	return;
}

