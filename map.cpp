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
int channel;
const char* imagefiles[4] = { "images/bottom.bmp" ,"images/brown_wall.bmp" ,"images/greem_wall.bmp" ,"images/black_wall.bmp" };//가져올 이미지
GLuint texID[4]; //텍스처 저장공간

unsigned char* LoadMeshFromFile(const char* texFile) //이미지 정보 읽어오는 함수
{
	GLuint texture;
	glGenTextures(1, &texture);
	FILE* fp = NULL;
	if (fopen_s(&fp, texFile, "rb")) {
		printf("ERROR : No %s. \n fail to bind %d\n", texFile, texture);
		return (unsigned char*)false;
	}
	
	unsigned char* image = stbi_load_from_file(fp, &width, &height, &channel, 4); //이미지 너비, 높이, 컬러채널의 수
	fclose(fp);
	return image;
}

// texture 설정
void init()
{
	
	glEnable(GL_TEXTURE_2D);
	glGenTextures(4, texID); //(텍스처 개수, 텍스처 저장공간)
	for (int i = 0; i < 4; i++)
	{
		unsigned char* bitmap;
		bitmap = LoadMeshFromFile((char*)imagefiles[i]); 
		glBindTexture(GL_TEXTURE_2D, texID[i]);
		//gluBuild2DMipmaps(GL_TEXTURE_2D, channel, width, height, 4, GL_UNSIGNED_BYTE, bitmap);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //2D 텍스처, 확대될 때 LINEAR필터적용(픽셀이 덜 보여 매끄러운 결과 산출)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //2D 텍스처, 축소될 때 LINEAR필터적용(픽셀이 덜 보여 매끄러운 결과 산출)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);

		free(bitmap);
	}

}

void Doom_map() {
	
	
		
	//Bottom
	glBindTexture(GL_TEXTURE_2D, texID[0]);
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	glColor3f(0.349f, 0.231f, 0.145f);
	glTexCoord2d(1.0, 1.0);
	glVertex3f(21.0f, 0.0f, -21.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(-21.0f, 0.0f, -21.0f);

	glTexCoord2d(0.0, 0.0);
	glVertex3f(-21.0f, 0.0f, 21.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();

	//TOPWALL
	/*glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();*/

	//1Wall
	//front
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-20.5f, 0.0f, -21.0f);
	glVertex3f(-20.5f, 6.0f, -21.0f);
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);
	glTexCoord2d(0.0, 0.0);
	glVertex3f(-20.5f, 6.0f, 21.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(-20.5f, 0.0f, 21.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(-20.5f, 0.0f, -21.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(-20.5f, 6.0f, -21.0f);
	glEnd();

	//bottom
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(-20.5f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 6.0f, 21.0f);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(-20.5f, 6.0f, 21.0f);
	glVertex3f(-20.5f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glEnd();

	//left
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);
	glTexCoord2d(0.0, 0.0);
	glVertex3f(-21.0f, 6.0f, 21.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(-21.0f, 0.0f, 21.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(-21.0f, 0.0f, -21.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glEnd();

	//2Wall
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	//front
	glNormal3f(-1.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 0.5f);
	glTexCoord2d(0.0, 0.0);
	glVertex3f(-21.0f, 6.0f, -21.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(-21.0f, 0.0f, -21.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(21.0f, 0.0f, -21.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glEnd();
	//right
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -20.5f);
	glVertex3f(21.0f, 6.0f, -20.5f);
	glEnd();
	//bottom
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(-21.0f, 0.0f, -20.5f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -20.5f);
	glEnd();
	//back
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.5f);
	glTexCoord2d(0.0, 0.0);
	glVertex3f(-21.0f, 6.0f, -20.5f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(-21.0f, 0.0f, -20.5f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(21.0f, 0.0f, -20.5f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(21.0f, 6.0f, -20.5f);
	glEnd();
	//top
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(-21.0f, 6.0f, -20.5f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -20.5f);
	glEnd();
	//left
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -20.5f);
	glVertex3f(-21.0f, 6.0f, -20.5f);
	glEnd();

	//3Wall
	//front
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glNormal3f(-1.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 0.5f);

	glTexCoord2d(0.0, 0.0);
	glVertex3f(21.0f, 6.0f, -21.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(21.0f, 0.0f, -21.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(21.0f, 0.0f, 21.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//bottom
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.5f);

	glTexCoord2d(0.0, 0.0);
	glVertex3f(20.5f, 0.0f, 21.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(20.5f, 0.0f, -21.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(21.0f, 0.0f, -21.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();
	//back
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(20.5f, 6.0f, 21.0f);
	glVertex3f(20.5f, 0.0f, 21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//top
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(20.5f, 6.0f, 21.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//left
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glEnd();


	//4Wall
	//front
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
	glColor3f(0.349f, 0.231f, 0.145f);
	glTexCoord2d(0.0, 0.0);
	glVertex3f(21.0f, 6.0f, 20.5f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(21.0f, 0.0f, 20.5f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(-7.0f, 0.0f, 20.5f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(-7.0f, 6.0f, 20.5f);
	glEnd();
	//right
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);
	glVertex3f(21.0, 6.0f, 20.5f);
	glVertex3f(21.0, 0.0f, 20.5f);
	glVertex3f(21.0, 0.0f, 21.0f);
	glVertex3f(21.0, 6.0f, 21.0f);
	glEnd();
	//bottom
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();
	//back
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);

	glTexCoord2d(0.0, 0.0);
	glVertex3f(-7.0f, 6.0f, 21.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(-7.0f, 0.0f, 21.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(21.0f, 0.0f, 21.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//top
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
	glVertex3f(-7.0f, 6.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//left
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);
	glVertex3f(-7.0, 6.0f, 20.5f);
	glVertex3f(-7.0, 0.0f, 20.5f);
	glVertex3f(-7.0, 0.0f, 21.0f);
	glVertex3f(-7.0, 6.0f, 21.0f);
	glEnd();


	//5Wall
	//front
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 6.0f, -7.0f);
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glNormal3f(1.0, 0.0, 0.0);
	glColor3f(0.349f, 0.231f, 0.145f);

	glTexCoord2d(0.0, 0.0);
	glVertex3f(-6.5f, 6.0f, -7.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(-6.5f, 6.0f, -7.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(-6.5f, 0.0f, 21.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(-6.5f, 0.0f, 21.0f);
	glEnd();
	
	//bottom
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, 21.0f);
	glEnd();
	
	//back
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-6.5f, 0.0f, 21.0f);
	glVertex3f(-6.5f, 6.0f, 21.0f);
	glEnd();
	//top
	
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(-6.5f, 6.0f, -7.0f);
	glVertex3f(-6.5f, 6.0f, 21.0f);
	glEnd();
	//left
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glNormal3f(-1.0, 0.0, 0.0);
	glColor3f(0.349f, 0.231f, 0.145f);

	glTexCoord2d(0.0, 0.0);
	glVertex3f(-7.0f, 6.0f, 21.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(-7.0f, 0.0f, 21.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(-7.0f, 0.0f, -7.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glEnd();

	//6Wall
	//front
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
	glColor3f(0.349f, 0.231f, 0.145f);

	glTexCoord2d(0.0, 0.0);
	glVertex3f(-7.0f, 6.0f, -7.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(-7.0f, 0.0f, -7.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(7.0f, 0.0f, -7.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(7.0f, 6.0f, -7.0f);
	glEnd();
	//right
	glBegin(GL_QUADS);
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(7.0f, 6.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -6.5f);
	glVertex3f(7.0f, 6.0f, -6.5f);
	glEnd();
	
	//bottom
	glBegin(GL_QUADS);
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 0.0f, -6.5f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -6.5f);
	glEnd();
	
	//back
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
	glColor3f(0.349f, 0.231f, 0.145f);

	glTexCoord2d(0.0, 0.0);
	glVertex3f(-7.0f, 6.0f, -6.5f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(-7.0f, 0.0f, -6.5f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(7.0f, 0.0f, -6.5f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(7.0f, 6.0f, -6.5f);
	glEnd();
	//top
	glBegin(GL_QUADS);
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 6.0f, -6.5f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(7.0f, 6.0f, -7.0f);
	glVertex3f(7.0f, 6.0f, -6.5f);
	glEnd();
	//left
	glBegin(GL_QUADS);
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
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glNormal3f(1.0, 0.0, 0.0);
	glColor3f(0.349f, 0.231f, 0.145f);

	glTexCoord2d(0.0, 0.0);
	glVertex3f(7.0f, 6.0f, -7.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(7.0f, 0.0f, -7.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(7.0f, 0.0f, 7.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(7.0f, 6.0f, 7.0f);
	glEnd();
	
	//bottom
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glNormal3f(-1.0, 0.0, 0.0);
	glColor3f(0.349f, 0.231f, 0.145f);

	glTexCoord2d(0.0, 0.0);
	glVertex3f(6.5f, 0.0f, 7.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(6.5f, 0.0f, -7.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(7.0f, 0.0f, -7.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(7.0f, 0.0f, 7.0f);
	glEnd();
	
	//back
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
	glColor3f(0.349f, 0.231f, 0.145f);

	glTexCoord2d(0.0, 0.0);
	glVertex3f(6.5f, 6.0f, 7.0f);

	glTexCoord2d(1.0, 0.0);
	glVertex3f(6.5f, 0.0f, 7.0f);

	glTexCoord2d(1.0, 1.0);
	glVertex3f(7.0f, 0.0f, 7.0f);

	glTexCoord2d(0.0, 1.0);
	glVertex3f(7.0f, 6.0f, 7.0f);
	glEnd();
	//top
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.0f, 0.5f);
	glVertex3f(6.5f, 6.0f, 7.0f);
	glVertex3f(6.5f, 6.0f, -7.0f);
	glVertex3f(7.0f, 6.0f, -7.0f);
	glVertex3f(7.0f, 6.0f, 7.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	
	//left
	/*glBegin(GL_QUADS);
	glColor3f(0.8f, 0.0f, 0.5f);
	glVertex3f(-6.5f, 6.0f, 7.0f);
	glVertex3f(-6.5f, 0.0f, 7.0f);
	glVertex3f(6.5f, 0.0f, 7.0f);
	glVertex3f(6.5f, 6.0f, 7.0f);
	glEnd();*/

	//TEMP Charactor
	glColor3f(1.0f, 1.0f, 0.0f);
	//glutSolidTeapot(0.5);
	glutWireTeapot(0.5);


	
}

