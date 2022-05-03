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

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

void MyResahpe(int NewWidth, int NewHeight) {

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
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(1600, 900);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("제목");
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glutDisplayFunc(MyDisplay);
	//glutReshapeFunc(MyResahpe);
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