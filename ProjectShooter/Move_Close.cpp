#include "Move_Close.h"



Move_Close::Move_Close()
{
}


Move_Close::~Move_Close()
{
}

void Move_Close::move(float deltaTime, sf::Vector2f sizeWindow, sf::CircleShape* sprite, bool& isGoUp)
{
	if (sprite->getPosition().y <= sprite->getRadius()) {
		isGoUp = false;
		GoDown(deltaTime, sprite, speed);
	}
	else if (sprite->getPosition().y >= (sizeWindow.y / 2) - sprite->getRadius()) {
		isGoUp = true;
		GoUp(deltaTime, sprite, speed);
	}
	else if (!isGoUp) {
		GoDown(deltaTime, sprite, speed);
	}
	else if (isGoUp) {
		GoUp(deltaTime, sprite, speed);
	}
}
