#pragma once
#include "I_MoveStyle.h"
class Move_Close_Top :
	public I_MoveStyle
{
public:
	Move_Close_Top();
	~Move_Close_Top();

	virtual void move(float deltaTime, sf::Vector2f sizeWindow, sf::CircleShape* sprite, bool& isGoUp);
	float speed = 650;
};

