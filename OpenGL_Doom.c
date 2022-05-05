#ifdef _WIN32
#include<glut.h>
#include<glu.h>
#include<gl.h>
#ifdef _WIN64
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

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	Doom_map();
	glutSwapBuffers();
}

void MyReshape(int NW, int NH) {
	GLfloat nRange = 3.0f;

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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MyKeyBoard(unsigned char KeyPressed, int X, int Y) {

}

void MySpecial(int key, int X, int Y) {

}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {

}

void MyMouseMove(GLint X, GLint Y) {

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
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(1600, 900);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Doom");
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	//glutKeyboardFunc(MyKeyBoard);
	//glutSpecialFunc(MySpecial);
	//glutMouseFunc(MyMouseClick);
	//glutMotionFunc(MyMouseMove);
	//glutIdleFunc(MyIdle);
	//glutTimerFunc(40, MyTimer, 1);
	//MenuFunc();

	glutMainLoop();
	return 0;
}