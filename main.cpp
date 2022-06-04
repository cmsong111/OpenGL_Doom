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
#include "map.h"

//SoundFIlePath
#define SOUND_FILE_GUN_FIRE "sounds/Gun_Fire.wav"
#define SOUND_FILE_GUN_RELOAD "sounds/Gun_reload.wav"
#define SOUND_FILE_GUN_NON "sounds/Gun_nonbullet.wav"

#define PI 3.1415


GLdouble sitdown = 4.0;


GLfloat yawX, pitchY; //카메라 y축, x축 기준  회전각 변화량
GLfloat CurrentX = 0.0f, CurrentY = 0.0f; //현재 마우스 좌표
GLfloat moveX = 0.0f, moveZ = 0.0f; // X,Z축 시점 이동변화량
GLfloat mX = 0.0f, mZ = 0.0f; // X,Z축 총 이동량
GLfloat rotX = 0.0f, rotY = 0.0f; //FpsView func 전달인자, 총 회전각

int bullet = 20, health = 100;
float angle = 0;
int botstate[4] = { 1,1,1,1 }; // 1번 살아있음 0번 죽음

//함수 원형 선언
void JumpTimer(int value);
void init();
void flashlight1();

void FpsView(GLfloat yaw, GLfloat pitch) {
	gluLookAt(0, sitdown, 0, 0, sitdown, -1, 0, 1, 0);
	glRotatef(yaw, 0.0, 1.0, 0.0);
	glRotatef(pitch, 1.0, 0.0, 0.0);
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	FpsView(rotX, rotY);
	glTranslated(mX, 0, mZ);
	Doom_map();
	if(botstate[0])
		makebot(angle, 2, 4, -5.5, 19, 5);
	if (botstate[1])
		makebot(angle, 1, 5, 19, 0, 6);
	if (botstate[2])
		makebot(angle, 1, 5, -19, -19, 7);
	if (botstate[3])
		makebot(angle, 2.5, 4, 19, 19, 8);
	glPopMatrix();
	glutSwapBuffers();
}

void MyReshape(int NW, int NH) {

	glViewport(0, 0, NW, NH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, NW / NH, 1, 50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MyKeyBoard(unsigned char KeyPressed, int X, int Y) {
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
		PlaySound(TEXT(SOUND_FILE_GUN_RELOAD), NULL, SND_ASYNC);
		bullet = 20;
		break;
	case 32:
		glutTimerFunc(10, JumpTimer, 1);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void MySpecial(int key, int X, int Y) {
	if (key == 114) {
		if (sitdown == 4) {
			sitdown = 2;
		}
		else {
			sitdown = 4;
		}
	}
	glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		if (bullet >= 0) {
			PlaySound(TEXT(SOUND_FILE_GUN_FIRE), NULL, SND_ASYNC);
			bullet--;
			if (0 < mX && mX < 6 && -13 > mZ && mZ > -17) {
				botstate[0] = 0;
			}
			if (-11 > mX && mX > -20 && -16 > mZ && mZ > -20) {
				botstate[3] = 0;
			}
			if (10 < mX && mX < 20 && 16 < mZ && mZ < 20) {
				botstate[2] = 0;
			}
			if (-19 < mX && mX < 15 && -4 < mZ && mZ < 2) {
				botstate[1] = 0;
			}
		}
		if (bullet < 0) {
			PlaySound(TEXT(SOUND_FILE_GUN_NON), NULL, SND_ASYNC);
		}

	}
}

void MyMouseMove(GLint X, GLint Y) {
	printf("%i, %i\n", X, Y);
}

//마우스로 시점 변환시 사용
void MyMousePassiveMove(GLint X, GLint Y) {
	yawX = X - CurrentX;
	//pitchY = Y-CurrentY;
	rotX += yawX * 0.7;
	//rotY += pitchY * 0.5;
	CurrentX = X;
	//CurrentY = Y;

	glutPostRedisplay();
}



void AngleTimer(int Value) {
	angle = rand() % 360;
	glutPostRedisplay();
	glutTimerFunc(1600, AngleTimer, 1);
}

void statusTimer(int Value) {

	system("cls");
	printf("====Key Manual====\n");
	printf("move key = wasd\tangle = mouse move\n");
	printf("sitdown : ctrl\tjump : spacebar\n");
	printf("shot gun : mouse left click\treload : r\n");
	printf("\n====Status====\n");
	printf("bullet : %d\n", bullet);

	if (bullet < 0) {
		printf("\n====Warning====\n");
		printf("You need reload\n");
	}

	printf("\n====Timer====\n");
	printf("%d min %d sec", Value / 1000 / 60, Value / 1000);

	printf("\n====== loacte ======\n");
	printf("x = %f, z = %f\n", mX, mZ);

	glutTimerFunc(500, statusTimer, Value + 500);
}

void MenuProc(int entryID) {

}

void MenuFunc() {

}

void JumpTimer(int value) {
	if (value == 1 && sitdown <= 5.4) {
		sitdown += 0.1;
		glutTimerFunc(10, JumpTimer, 1);
	}
	else if (value == 1 && sitdown >= 5.4) {
		glutTimerFunc(10, JumpTimer, -1);
	}
	else if (value == -1 && sitdown >= 4) {
		sitdown -= 0.1;
		glutTimerFunc(10, JumpTimer, -1);
	}
	glutPostRedisplay();
}

void flashlight1() {
	GLfloat Light1_pos[] = { 0.0,0.0,0.0,1.0 };
	GLfloat Light1_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat Light1_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat Light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat Light1_direction[] = { 0.0,0.0,-1.0 };
	GLfloat Light1_Cutoff[] = { 10.0 };
	GLfloat Light1_Exponent[] = { 1.0 };

	glLightfv(GL_LIGHT1, GL_POSITION, Light1_pos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, Light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Light1_specular);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Light1_direction);
	glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, Light1_Cutoff);
	glLightfv(GL_LIGHT1, GL_SPOT_EXPONENT, Light1_Exponent);


	glEnable(GL_LIGHT1);
}

void flashlight2() {
	GLfloat Light2_pos[] = { 0.0,0.0,0.0,1.0 };
	GLfloat Light2_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat Light2_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat Light2_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat Light2_direction[] = { 0.0,0.0,1.0 };
	GLfloat Light2_Cutoff[] = { 10.0 };
	GLfloat Light2_Exponent[] = { 1.0 };

	glLightfv(GL_LIGHT2, GL_POSITION, Light2_pos);
	glLightfv(GL_LIGHT2, GL_AMBIENT, Light2_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Light2_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, Light2_specular);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, Light2_direction);
	glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, Light2_Cutoff);
	glLightfv(GL_LIGHT2, GL_SPOT_EXPONENT, Light2_Exponent);


	glEnable(GL_LIGHT2);
}
void InitIight() {
	GLfloat Global_ambient_Color[] = { 1.0,0.8,0.8,1.0 };
	GLfloat Light0_pos[] = { 0.0,5.9,0.0,1.0 };
	GLfloat Light0_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat Light0_diffuse[] = { 0.7, 0.1, 0.1, 1.0 };
	GLfloat Light0_specular[] = { 1.0, 0.2, 0.2, 1.0 };

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	flashlight1();
	flashlight2();
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_POSITION, Light0_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, Light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Light0_specular);

	glEnable(GL_LIGHT0);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Global_ambient_Color);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);


}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1600, 900);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Doom");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	InitIight();

	init();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyBoard);
	glutSpecialFunc(MySpecial);
	glutMouseFunc(MyMouseClick);
	//glutMotionFunc(MyMouseMove);
	glutPassiveMotionFunc(MyMousePassiveMove);
	glutTimerFunc(1600, AngleTimer, 1);
	glutTimerFunc(500, statusTimer, 0);
	//MenuFunc();

	glutMainLoop();
	return 0;
}
