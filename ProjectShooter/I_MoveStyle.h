#pragma once
#include "SFML/Graphics.hpp"
class I_MoveStyle
{
public:
	virtual ~I_MoveStyle() {}
	virtual void move(float deltaTime, sf::Vector2f sizeWindow, sf::CircleShape* sprite, bool& isGoUp) = 0;
	void GoUp(float deltaTime, sf::CircleShape* sprite, float speed);
	void GoDown(float deltaTime, sf::CircleShape* sprite, float speed);
};