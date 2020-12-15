#include "Move_Close_top.h"


Move_Close_Top::Move_Close_Top()
{
}


Move_Close_Top::~Move_Close_Top()
{
}

void Move_Close_Top::move(float deltaTime, sf::Vector2f sizeWindow, sf::CircleShape* sprite, bool& isGoUp)
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
