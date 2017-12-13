#include "stdafx.h"
#include "Food.h"


Food::Food()
{
	srand( time(NULL) );
	this->x = rand() % 40;
	this->y = rand() % 40;
}



Food::~Food()
{
}

void Food::drawFood() {
	glLoadIdentity();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(x, y);	glVertex2d(x + 1, y);
	glVertex2d(x + 1, y);		glVertex2d(x + 1, y + 1);
	glVertex2d(x + 1, y + 1);	 glVertex2d(x, y + 1);
	glVertex2d(x, y + 1);		glVertex2d(x, y);
	glEnd();
}

