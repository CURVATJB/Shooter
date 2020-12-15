#pragma once
#include "I_MoveStyle.h"
class Move_Close_Bot :
	public I_MoveStyle
{
public:
	Move_Close_Bot();
	~Move_Close_Bot();

	virtual void move(float deltaTime, sf::Vector2f sizeWindow, sf::CircleShape* sprite, bool& isGoUp);
	float speed = 650;
};

