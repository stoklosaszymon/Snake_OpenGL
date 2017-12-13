#include "stdafx.h"
#include "Snake.h"
#include <GL/glut.h>
#include "map.h"


Snake::Snake()
{
	this->snake.push_back(position(10, 10));
}


Snake::~Snake()
{
}

void Snake::updateSnake() {
		for (int i = snake.size() - 1; i >= 1; --i) {
			this->snake[i].x = snake[i - 1].x;
			this->snake[i].y = snake[i - 1].y;
		}
}

void Snake::drawSnake() {
	for (auto part : snake) {
		glLoadIdentity();
		glColor3f(0.0, 1.0, 0.0);
		
		glBegin(GL_QUADS);
		glVertex2d(part.x, part.y);		glVertex2d(part.x + 1, part.y);
		glVertex2d(part.x + 1, part.y);		glVertex2d(part.x + 1, part.y + 1);
		glVertex2d(part.x + 1, part.y + 1);		glVertex2d(part.x, part.y + 1);
		glVertex2d(part.x, part.y + 1);		glVertex2d(part.x, part.y);
		glEnd();
	}
}

void Snake::setDirection(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
		if (direction != DOWN) {
			direction = UP;
		}
		break;
	case GLUT_KEY_DOWN:
		if (direction != UP) {
			direction = DOWN;
		}
		break;
	case GLUT_KEY_RIGHT:
		if (direction != LEFT) {
			direction = RIGHT;
		}
		break;
	case GLUT_KEY_LEFT:
		if (direction != RIGHT) {
			direction = LEFT;
		}
		break;
	}
}

void Snake::move_to(void(*move)(Snake &snake_arg))
{
	Snake *snakePtr = this;
	move(*snakePtr);
}

void Snake::move() {
	switch (direction)
	{
	case UP:
		move_to( [](Snake &snake_arg) { snake_arg.snake.front().y += 1; });
		break;
	case DOWN:
		move_to( [](Snake &snake_arg) { snake_arg.snake.front().y -= 1; });
		break;
	case LEFT:
		move_to( [](Snake &snake_arg) { snake_arg.snake.front().x -= 1; });
		break;
	case RIGHT:
		move_to( [](Snake &snake_arg) { snake_arg.snake.front().x += 1; });
		break;
	default:
		break;
	}
}


void Snake::eat(Food &food_arg) {
	if (snake.front().x == food_arg.x && snake.front().y == food_arg.y) {
		snake.push_back(position(100, 110));
		srand( time(NULL) );
		food_arg.x = rand() % 40;
		food_arg.y = rand() % 40;
	}
}

void Snake::hitWall() {
	if (snake.front().x >= Map::rows) {
		snake.front().x = 0;
	}
	else if (snake.front().y >= Map::columns) {
		snake.front().y = 0;
	}
	else if (snake.front().x < 0) {
		snake.front().x = Map::rows;
	} 
	else if (snake.front().y < 0) {
		snake.front().y = Map::columns - 1;
	}
}

bool Snake::eatItself() {
	for (int i = snake.size() - 1; i > 1; --i) {
		if (snake.front().x == snake[i].x && snake.front().y == snake[i].y) {
			return true;
		}
	}
	return false;
}
