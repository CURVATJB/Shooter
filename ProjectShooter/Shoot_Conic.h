#pragma once
#include "I_ShootStyle.h"
class Shoot_Conic :
	public I_ShootStyle
{
public:
	Shoot_Conic();

	virtual void shoot(sf::Vector2f startShootLocation, GameInstance* GI, float* fireRate, int hp);
};

