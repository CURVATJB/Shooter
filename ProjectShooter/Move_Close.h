#pragma once
#include "I_MoveStyle.h"
class Move_Close :
	public I_MoveStyle
{
public:
	Move_Close();
	~Move_Close();

	virtual void move(float deltaTime, sf::Vector2f sizeWindow, sf::CircleShape* sprite, bool& isGoUp);
	float speed = 650;
};

