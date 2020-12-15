#include "Move_Far.h"



Move_Far::Move_Far()
{
}


Move_Far::~Move_Far()
{
}

void Move_Far::move(float deltaTime, sf::Vector2f sizeWindow, sf::CircleShape* sprite, bool& isGoUp)
{

	if (sprite->getPosition().y <= sprite->getRadius()) {
		isGoUp = false;
		GoDown(deltaTime, sprite, speed);
	}
	else if (sprite->getPosition().y >= sizeWindow.y - sprite->getRadius()) {
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
