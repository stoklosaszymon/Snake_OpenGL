#pragma once
#include "Snake.h"
#include <cstdlib>
#include <GL/glut.h>
#include <ctime>

class Food
{
public:
	int x;
	int y;
	Food();
	~Food();
	void drawFood();
	void newPos();
};

