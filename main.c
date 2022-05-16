#ifdef _WIN32
#include <windows.h>
#include<glut.h>
#include<glu.h>
#include<gl.h>
#ifdef _WIN64
#include <windows.h>
#include<glut.h>
#include<glu.h>
#include<gl.h>
#endif
#elif __APPLE__
#include "TargetConditionals.h"
#if TARGET_IPHONE_SIMULATOR
#include<GLUT/glut.h>
#elif TARGET_OS_IPHONE
#include<GLUT/glut.h>
#elif TARGET_OS_MAC
#include<GLUT/glut.h>
#else
#   error "Unknown Apple platform"
#endif
#elif __linux__
// linux
#elif __unix__ // all unices not caught above
// Unix`
#elif defined(_POSIX_VERSION)
// POSIX
#else
#   error "Unknown compiler"
#endif

#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>;



#define SOUND_FILE_GUN_FIRE "sounds/Gun_Fire.wav"
#define SOUND_FILE_GUN_RELOAD "sounds/Gun_reload.wav"


//Lookat 변수
GLdouble Camera_eye[3] = { 0,0,0 }, Camera_center[3] = { 0,0,-1 }, Camera_up[3] = { 0,1,0 };
//마우스 시점 이동 변수
GLint Camera_mouse[2] = { 0,0 };

GLint FullwindowX = 1600, FullwindowY = 900;
GLfloat screen_Sensitivity_X = 10000, screen_Sensitivity_Y = 0.00000005;



void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	Doom_map();
	gluLookAt(
		Camera_eye[0], Camera_eye[1], Camera_eye[2], //eye
		Camera_center[0], Camera_center[1], Camera_center[2], //center
		Camera_up[0], Camera_up[1], Camera_up[2] //up
	);

	glutSwapBuffers();
}

void MyReshape(int NW, int NH) {
	GLfloat nRange = 3.0f;
	FullwindowX = NW;
	FullwindowY = NH;



	if (NH == 0) {
		NH = 1;
	}
	glViewport(0, 0, NW, NH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (NW <= NH) {
		glOrtho(-nRange, nRange, -nRange * NH / NW, nRange * NH / NW, -nRange, nRange);
	}
	else {
		glOrtho(-nRange * NW / NH, nRange * NW / NH, -nRange, nRange, -nRange, nRange);
	}
	gluPerspective(50.0f, (GLfloat)NW / (GLfloat)NH, 1.0, 40.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	
	
}

void MyKeyBoard(unsigned char KeyPressed, int X, int Y) {
	printf("%c\n", KeyPressed);
	switch (KeyPressed)
	{
	case 'w':
		Camera_eye[2] -= 0.0001;
		break;
	case 'a':
		Camera_eye[1] -= 0.0001;
		break;
	case 's':
		Camera_eye[2] += 0.0001;
		break;
	case 'd':
		Camera_eye[1] += 0.0001;
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
	//printf("%i, %i\n", X, Y);

	//if (X > Camera_mouse[0]) {
	//	//오른쪽으로 시점이동
	//	printf("오른쪽으로 시점이동\n");
	//	Camera_center[0] += 0.00005;
	//}
	//else {
	//	printf("왼쪽으로 시점이동\n");
	//	Camera_center[0] -= 0.00005;
	//}
	//if (Y < Camera_mouse[1]) {
	//	printf("위로 시점이동\n");
	//	Camera_center[1] += 0.00005;
	//}
	//else {
	//	printf("아래로 시점이동\n");
	//	Camera_center[1] -= 0.00005;
	//}


	//Camera_mouse[0] = X;
	//Camera_mouse[1] = Y;


	printf("%lf\n", (double)X / screen_Sensitivity_X - (double)FullwindowX / screen_Sensitivity_X / 2);

	Camera_center[0] = (double)X / screen_Sensitivity_X - (double)FullwindowX / screen_Sensitivity_X / 2;


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

void userinit() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1600, 900);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Doom");
	glClearColor(0.0, 0.0, 0.0, 1.0);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	userinit();

	//콜백 함수 등록
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyBoard);
	glutMouseFunc(MyMouseClick);
	glutPassiveMotionFunc(MyMousePassiveMove);
	//glutSpecialFunc(MySpecial);
	//glutMotionFunc(MyMouseMove);
	//glutIdleFunc(MyIdle);
	//glutTimerFunc(40, MyTimer, 1);
	//MenuFunc();
	glutMainLoop();

	return 0;
}