#pragma once
#include "SFML/Graphics.hpp"

class GameInstance;
class I_ShootStyle
{
public:
	virtual ~I_ShootStyle() {}
	virtual void shoot(sf::Vector2f startShootLocation, GameInstance* GI, float* fireRate, int hp) = 0;
}; 