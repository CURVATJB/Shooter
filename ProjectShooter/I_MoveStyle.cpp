#include "I_MoveStyle.h"

void I_MoveStyle::GoUp(float deltaTime, sf::CircleShape* sprite, float speed)
{
	sprite->setPosition(sprite->getPosition().x, sprite->getPosition().y - 0.1f * deltaTime * speed);
}

void I_MoveStyle::GoDown(float deltaTime, sf::CircleShape* sprite, float speed)
{
	sprite->setPosition(sprite->getPosition().x, sprite->getPosition().y + 0.1f * deltaTime * speed);
}
