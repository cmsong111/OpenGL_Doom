//Windows
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Open GL
#include<glut.h>
#include<glu.h>
#include<gl.h>

//Sound
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>

//Header FIle
#include "location.h"
#include "map.h"

//SoundFIlePath
#define SOUND_FILE_GUN_FIRE "sounds/Gun_Fire.wav"
#define SOUND_FILE_GUN_RELOAD "sounds/Gun_reload.wav"
#define PI 3.1415

//Lookat 변수
double Camera_up[3] = { 0,1,0 };

//마우스 시점 이동 변수
GLint Camera_mouse[2] = { 0,0 };


GLint FullwindowX = 1600, FullwindowY = 900;
GLdouble screen_Sensitivity_X = 10000, screen_Sensitivity_Y = 0.00000005;


Location player(0, 4, 0);
Location player_target(0, 4, -1);

GLfloat yawX, pitchY; //카메라 y축, x축 기준  회전각 변화량
GLfloat CurrentX = 0.0f, CurrentY = 0.0f; //현재 마우스 좌표
GLfloat moveX = 0.0f, moveZ = 0.0f; // X,Z축 시점 이동변화량
GLfloat mX = 0.0f, mZ = 0.0f; // X,Z축 총 이동량
GLfloat rotX = 0.0f, rotY = 0.0f; //FpsView func 전달인자, 총 회전각


void FpsView(GLfloat yaw, GLfloat pitch) {
	gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
	glRotatef(yaw, 0.0, 1.0, 0.0);
	glRotatef(pitch, 1.0, 0.0, 0.0);
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	FpsView(rotX, rotY);
	glTranslated(mX, 0, mZ);
	Doom_map();
	glPopMatrix();
	glutSwapBuffers();
}

void MyReshape(int NW, int NH) {
	glViewport(0, 0, NW, NH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, NW / NH, 1, 22);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MyKeyBoard(unsigned char KeyPressed, int X, int Y) {
	printf("%c\n", KeyPressed);
	double movespeed = 0.1;
	switch (KeyPressed)
	{
	case 'w':
		moveX = sin((rotX) * (PI / 180));
		moveZ = cos((rotX) * (PI / 180));

		mX += -moveX;
		mZ += moveZ;
		break;
	case 'a':
		moveX = sin((rotX) * (PI / 180) + (PI / 2));
		moveZ = cos((rotX) * (PI / 180) + (PI / 2));

		mX += moveX;
		mZ += -moveZ;
		break;
	case 's':
		moveX = sin((rotX) * (PI / 180));
		moveZ = cos((rotX) * (PI / 180));

		mX += moveX;
		mZ += -moveZ;
		break;
	case 'd':
		moveX = sin((rotX) * (PI / 180) + (PI / 2));
		moveZ = cos((rotX) * (PI / 180) + (PI / 2));

		mX += -moveX;
		mZ += moveZ;
		break;

	case 'r':
		printf("GUN_RELOAD\n");
		PlaySound(TEXT(SOUND_FILE_GUN_RELOAD), NULL, SND_ASYNC);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void MySpecial(int key, int X, int Y) {

}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		printf("GUN_FIRE\n");
		PlaySound(TEXT(SOUND_FILE_GUN_FIRE), NULL, SND_ASYNC);
	}
}

void MyMouseMove(GLint X, GLint Y) {
	printf("%i, %i\n", X, Y);
}

//마우스로 시점 변환시 사용
void MyMousePassiveMove(GLint X, GLint Y) {
	printf("%i, %i\n", X, Y);
	yawX = X - CurrentX;
	//pitchY = Y-CurrentY;
	rotX += yawX * 0.5;
	//rotY += pitchY * 0.5;
	CurrentX = X;
	//CurrentY = Y;

	glutPostRedisplay();
}

void MyIdle() {

}

void MyTimer(int Value) {

}

void MenuProc(int entryID) {

}

void MenuFunc() {

}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1600, 900);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Doom");
	glClearColor(0.0, 0.0, 0.0, 1.0);


	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyBoard);
	//glutSpecialFunc(MySpecial);
	glutMouseFunc(MyMouseClick);
	//glutMotionFunc(MyMouseMove);
	glutPassiveMotionFunc(MyMousePassiveMove);
	//glutIdleFunc(MyIdle);
	//glutTimerFunc(40, MyTimer, 1);
	//MenuFunc();

	glutMainLoop();
	return 0;
}
