#include "map.h"
#include <glut.h>
#include <glu.h>
#include <gl.h>
#include <GLAUX.H>

//p.351
//void loadTexture() {
//	AUX_RGBImageRec* pBottomImage = auxDIBImageLoad("/images/bottom.jpg");
//}

void Doom_map() {
	//Bottpom
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();


    return;
}

