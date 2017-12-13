#pragma once
#include <vector>
#include "Food.h"
#include <ctime>

class Snake
{
public:
	struct position {
		int x;
		int y;
		position(int x, int y) {
			this->x = x;
			this->y = y;
		}
	};

	enum directions {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	std::vector<position> snake;
	directions direction = UP;

	Snake();
	~Snake();
	void drawSnake();
	void setDirection(int key, int x, int y);
	void move_to( void(*f)(Snake &snake_arg) );
	void move();
	void eat(class Food& food_arg);
	void updateSnake();
	void hitWall();
	bool eatItself();
};

