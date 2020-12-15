#pragma once
#include "I_ShootStyle.h"
class Shoot_Linear :
	public I_ShootStyle
{
public:
	Shoot_Linear();
	~Shoot_Linear();

	virtual void shoot(sf::Vector2f startShootLocation, GameInstance* GI, float* fireRate, int hp);
};

