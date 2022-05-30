#include "map.h"
#include <glut.h>
#include <glu.h>
#include <gl.h>
#include <GLAUX.H>
#include <windows.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint g_textureID = 1;
int width, height;


unsigned char* LoadMeshFromFile(const char* texFile)
{
	GLuint texture;
	glGenTextures(1, &texture);
	FILE* fp = NULL;
	if (fopen_s(&fp, texFile, "rb")) {
		printf("ERROR : No %s. \n fail to bind %d\n", texFile, texture);
		return (unsigned char*)false;
	}
	int channel;
	unsigned char* image = stbi_load_from_file(fp, &width, &height, &channel, 4);
	fclose(fp);
	return image;
}

// texture ¼³Á¤
void init()
{
	GLuint texID;

	unsigned char* bitmap;
	bitmap = LoadMeshFromFile((char*)"images/bottom.bmp");
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	free(bitmap);
}

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
	glEnd();
	//bottom
	glColor3f(0.0f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, 21.0f);
	glEnd();
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
	glEnd();
	//bottom
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 0.0f, -6.5f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -6.5f);
	glEnd();
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
	glEnd();
	//bottom
	glColor3f(0.8f, 0.0f, 0.5f);
	glVertex3f(6.5f, 0.0f, 7.0f);
	glVertex3f(6.5f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, 7.0f);
	glEnd();
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
