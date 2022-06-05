#include<glut.h>
#include<glu.h>
#include<gl.h>
#include "map.h"

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

