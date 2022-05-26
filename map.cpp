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
	//Bottom
	
	glBegin(GL_POLYGON);
	glColor3f(0.349f, 0.231f, 0.145f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();

<<<<<<< Updated upstream
	//1Wall
	//front
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//TOPWALL
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();

	//1Wall
	//front
	glColor3f(1.0f, 0.5f, 1.0f);
	glBegin(GL_QUADS);
	//glColor3f(1.0f, 0.5f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-20.5f, 0.0f, -21.0f);
	glVertex3f(-20.5f, 6.0f, -21.0f);
	//right
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(1.0f, 0.5f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(-20.5f, 6.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, -21.0f);
	glVertex3f(-20.5f, 6.0f, -21.0f);
	glEnd();
	//bottom
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(1.0f, 0.5f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(-20.5f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glEnd();
	//back
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(1.0f, 0.5f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 0.0f, 21.0f);
	glVertex3f(-20.5f, 6.0f, 21.0f);
	glEnd();
	//top
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(1.0f, 0.5f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(-20.5f, 6.0f, 21.0f);
	glVertex3f(-20.5f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glEnd();
	//left
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(1.0f, 0.5f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(-21.0f, 6.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, 21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glEnd();

	//2Wall
<<<<<<< Updated upstream
	//front
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	glColor3f(1.0f, 1.0f, 0.5f);
	glBegin(GL_QUADS);
	//front
	//glColor3f(1.0f, 1.0f, 0.5f);
>>>>>>> Stashed changes
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glEnd();
	//right
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(1.0f, 1.0f, 0.5f);
>>>>>>> Stashed changes
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -20.5f);
	glVertex3f(21.0f, 6.0f, -20.5f);
	glEnd();
	//bottom
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(1.0f, 1.0f, 0.5f);
>>>>>>> Stashed changes
	glVertex3f(-21.0f, 0.0f, -20.5f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -20.5f);
	glEnd();
	//back
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(1.0f, 1.0f, 0.5f);
>>>>>>> Stashed changes
	glVertex3f(-21.0f, 6.0f, -20.5f);
	glVertex3f(-21.0f, 0.0f, -20.5f);
	glVertex3f(21.0f, 0.0f, -20.5f);
	glVertex3f(21.0f, 6.0f, -20.5f);
	glEnd();
	//top
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(1.0f, 1.0f, 0.5f);
>>>>>>> Stashed changes
	glVertex3f(-21.0f, 6.0f, -20.5f);
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -20.5f);
	glEnd();
	//left
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(1.0f, 1.0f, 0.5f);
>>>>>>> Stashed changes
	glVertex3f(-21.0f, 6.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -21.0f);
	glVertex3f(-21.0f, 0.0f, -20.5f);
	glVertex3f(-21.0f, 6.0f, -20.5f);
	glEnd();

	//3Wall
	//front
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	glColor3f(0.5f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	//glColor3f(0.5f, 1.0f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glEnd();
	//right
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(0.5f, 1.0f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glEnd();
	//bottom
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(0.5f, 1.0f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(20.5f, 0.0f, 21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, -21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();
	//back
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(0.5f, 1.0f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(20.5f, 6.0f, 21.0f);
	glVertex3f(20.5f, 0.0f, 21.0f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//top
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(0.5f, 1.0f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(20.5f, 6.0f, 21.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, -21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//left
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
=======
	//glColor3f(0.5f, 1.0f, 1.0f);
>>>>>>> Stashed changes
	glVertex3f(20.5f, 6.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(20.5f, 0.0f, -21.0f);
	glVertex3f(20.5f, 6.0f, -21.0f);
	glEnd();


	//4Wall
	//front
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-13.5f, 6.0f, -21.0f);
	glVertex3f(-13.5f, 0.0f, -21.0f);
=======
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	//glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-7.0f, 6.0f, 20.5f);
	glVertex3f(-7.0f, 0.0f, 20.5f);
>>>>>>> Stashed changes
	glVertex3f(21.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 20.5f);
	glEnd();
	//right
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(14.0f, 6.0f, 21.0f);
	glVertex3f(14.0f, 0.0f, 21.0f);
	glVertex3f(13.5f, 0.0f, 20.5f);
	glVertex3f(13.5f, 6.0f, 20.5f);
	glEnd();
	//bottom
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 0.0f, 21.0f);
	glVertex3f(-13.5f, 0.0f, 20.5f);
=======
	//glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(21.0, 6.0f, 20.5f);
	glVertex3f(21.0, 0.0f, 20.5f);
	glVertex3f(21.0, 0.0f, 21.0f);
	glVertex3f(21.0, 6.0f, 21.0f);
	//bottom
	//glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, 20.5f);
>>>>>>> Stashed changes
	glVertex3f(21.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();
	//back
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 6.0f, -21.0f);
	glVertex3f(-14.0f, 0.0f, -21.0f);
=======
	//glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
>>>>>>> Stashed changes
	glVertex3f(21.0f, 0.0f, 21.0f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//top
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 6.0f, 21.0f);
	glVertex3f(-13.5f, 6.0f, 20.5f);
=======
	//glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
	glVertex3f(-7.0f, 6.0f, 20.5f);
>>>>>>> Stashed changes
	glVertex3f(21.0f, 6.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//left
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 6.0f, 21.0f);
	glVertex3f(-14.0f, 0.0f, 21.0f);
	glVertex3f(-13.5f, 0.0f, 20.5f);
	glVertex3f(-13.5f, 6.0f, 20.5f);
=======
	//glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-7.0, 6.0f, 20.5f);
	glVertex3f(-7.0, 0.0f, 20.5f);
	glVertex3f(-7.0, 0.0f, 21.0f);
	glVertex3f(-7.0, 6.0f, 21.0f);
>>>>>>> Stashed changes
	glEnd();


	//5Wall
	//front
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 6.0f, -7.0f);
	glEnd();
	//right
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-6.5f, 6.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, 21.0f);
	glVertex3f(-6.5f, 6.0f, 21.0f);
	//glEnd();
	//bottom
<<<<<<< Updated upstream
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 0.0f, 21.0f);
	glVertex3f(-13.5f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 20.5f);
	glVertex3f(21.0f, 0.0f, 21.0f);
	glEnd();
	//back
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 6.0f, 21.0f);
	glVertex3f(-14.0f, 0.0f, 21.0f);
	glVertex3f(-13.5f, 0.0f, 21.0f);
	glVertex3f(-13.5f, 6.0f, 21.0f);
	glEnd();
=======
	glColor3f(0.0f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, -7.0f);
	glVertex3f(-6.5f, 0.0f, 21.0f);
	//glEnd();
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
	//glEnd();
	//bottom
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 0.0f, -6.5f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -6.5f);
	//glEnd();
	//back
	glColor3f(0.8f, 1.0f, 0.5f);
	glVertex3f(-7.0f, 6.0f, -6.5f);
	glVertex3f(-7.0f, 0.0f, -6.5f);
	glVertex3f(7.0f, 0.0f, -6.5f);
	glVertex3f(7.0f, 6.0f, -6.5f);
>>>>>>> Stashed changes
	//top
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-14.0f, 6.0f, 21.0f);
	glVertex3f(-13.5f, 6.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 20.5f);
	glVertex3f(21.0f, 6.0f, 21.0f);
	glEnd();
	//left
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 5.0f, 1.0f);
	glVertex3f(-7.0f, 6.0f, -7.0f);
	glVertex3f(-7.0f, 0.0f, -7.0f);
<<<<<<< Updated upstream
	glVertex3f(-7.0f, 0.0f, 21.0f);
	glVertex3f(-7.0f, 6.0f, 21.0f);
=======
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
	//glEnd();
	//bottom
	glColor3f(0.8f, 0.0f, 0.5f);
	glVertex3f(6.5f, 0.0f, 7.0f);
	glVertex3f(6.5f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, -7.0f);
	glVertex3f(7.0f, 0.0f, 7.0f);
	//glEnd();
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
>>>>>>> Stashed changes
	glEnd();

	//TEMP Charactor
	glColor3f(1.0f, 1.0f, 0.0f);
	//glutSolidTeapot(0.5);
	glutWireTeapot(0.5);


    return;
}


