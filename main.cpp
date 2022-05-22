//Windows
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
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

//Lookat 변수
double Camera_up[3] = { 0,1,0 };

//마우스 시점 이동 변수
GLint Camera_mouse[2] = { 0,0 };

GLint FullwindowX = 1600, FullwindowY = 900;
GLdouble screen_Sensitivity_X = 10000, screen_Sensitivity_Y = 0.00000005;

Location player(0, 4, 0);
Location player_target(0, 4, -1);


GLfloat pitchX, yawY; //카메라 x축, y축 회전각
int FirstMouseMove = 1;
GLfloat CurrentX, CurrentY; //현재 마우스 좌표


void FpsView(GLfloat pitch, GLfloat yaw) {

	glRotatef(pitch, 0.0, 1.0, 0.0);
	glRotatef(yaw, 1.0, 0.0, 0.0);

}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	Doom_map();

	gluLookAt( // x,y,z
		player.x, player.y, player.z, //eye
		player_target.x, player_target.y, player_target.z, //center
		Camera_up[0], Camera_up[1], Camera_up[2] //up
	);

	glutSwapBuffers();
}

void MyReshape(int NW, int NH) {
	GLfloat nRange = 3.0f;

	if (NH == 0) {
		NH = 1;
	}

	glViewport(0, 0, NW, NH);
	gluLookAt(0, 0, 21, 0, 0, -10, 0, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (NW <= NH) {
		glOrtho(-nRange, nRange, -nRange * NH / NW, nRange * NH / NW, -nRange, nRange);
	}
	else {
		glOrtho(-nRange * NW / NH, nRange * NW / NH, -nRange, nRange, -nRange, nRange);
	}
	gluPerspective(60, (NH / NW) / 2, -25, 21);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void MyKeyBoard(unsigned char KeyPressed, int X, int Y) {
	printf("%c\n", KeyPressed);
	double movespeed = 0.1;
	switch (KeyPressed)
	{
	case 'w':
		player.z -= movespeed;
		player_target.z -= movespeed;
		break;
	case 'a':
		player.x -= movespeed;
		player_target.x -= movespeed;
		break;
	case 's':
		player.z += movespeed;
		player_target.z += movespeed;

		break;
	case 'd':
		player.x += movespeed;
		player_target.x += movespeed;
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

	if (FirstMouseMove) {
		CurrentX = X;
		CurrentY = Y;
		FirstMouseMove = 0;
	}
	pitchX = (X - CurrentX) * 0.3;

	yawY = (Y - CurrentY) * 0.3;
	if (yawY >= 60)
		yawY = 60;
	else if (yawY <= -60)
		yawY = -60;



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
