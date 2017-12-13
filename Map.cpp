#include "stdafx.h"
#include "map.h"
#include <GL/glut.h>

Map::Map()
{
}


Map::~Map()
{
}

void Map::drawMap_grid() {
	for (int columns = 0; columns < Map::columns; columns++) {
		for (int rows = 0; rows < Map::rows; rows++)
		{
			glLoadIdentity();
			glColor3f(1.0, 0.0, 0.0);
			glLineWidth(1.0);
			glBegin(GL_LINES);
			glVertex2d(columns, rows); glVertex2d(columns + 1, rows);
			glVertex2d(columns + 1, rows); glVertex2d(columns + 1, rows + 1);
			glVertex2d(columns + 1, rows + 1); glVertex2d(columns, rows + 1);
			glVertex2d(columns, rows + 1); glVertex2d(columns, rows);
			glEnd();
		}
	}
}