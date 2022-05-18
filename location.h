#ifndef __LOACTION_H__
#define __LOACTION_H__

#include<GL/glut.h>

class Location {

public:
	double x, y, z;
	Location(double x, double y, double z) {
		this->x = x;
		this->x = y;
		this->x = z;
	}
};

#endif