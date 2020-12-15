#pragma once
#include "I_MoveStyle.h"
class Move_Far :
	public I_MoveStyle
{
public:
	Move_Far();
	~Move_Far();

	virtual void move(float deltaTime, sf::Vector2f sizeWindow, sf::CircleShape* sprite, bool& isGoUp);
	float speed = 1000;
};

