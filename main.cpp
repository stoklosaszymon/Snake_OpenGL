// training_gl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glut.h>
#include "map.h"
#include "Snake.h"
#include "Food.h"
#include <iostream>
#include <string>



struct Messages {
	std::string gameOverText = "Game Over ";
	std::string restartText = "Press r to restart";
	std::string scores_text = "";
};

int scores = 0;
Map map;
Snake snake;
Food food;
Messages messages;

void drawTable() {
	glLoadIdentity();
	glColor3f(0.0, 1.0, 0.0);
	glLineWidth(1.0);

	glBegin(GL_LINES);
	glVertex2d(0, 0); glVertex2d(Map::columns, 0);
	glVertex2d(Map::columns, 0); glVertex2d(Map::columns, -5);
	glVertex2d(Map::columns, -5); glVertex2d(0, -5);
	glVertex2d(0, -5); glVertex2d(0, 0);
	glEnd();
}

void printScores() {

	if ( scores != snake.snake.size() ) {
		messages.scores_text = "Scores: ";
		messages.scores_text += std::to_string(scores);
	}

	scores = snake.snake.size() * 100;

	glColor3f(0.0, 1.0, 0.0);
	glRasterPos2f(2, -3.5);
	for (int i = 0; i < messages.scores_text.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, messages.scores_text[i]);
	}
}


void gameOverMessage() {
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(Map::columns / 4, Map::rows / 2 + 5);
	for (int i = 0; i < messages.gameOverText.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, messages.gameOverText[i]);
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
//	map.drawMap_grid();	
	if ( !snake.eatItself() ) {
		food.drawFood();
		snake.move();
		snake.eat(food);
		snake.hitWall();
		snake.drawSnake();
		snake.updateSnake();
		drawTable();
		printScores();
	}
	else {
		gameOverMessage();
	}
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLfloat)w, GLfloat(h));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, Map::columns, -5, Map::rows, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(100, timer_callback, 0);
}

void input(int key, int x, int y) {
	snake.setDirection(key, x, y);
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("SNAKE");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 6500);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(input);
	glutTimerFunc(100, timer_callback, 0);
	glutMainLoop();
	return 0;
}


