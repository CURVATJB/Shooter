#pragma once
#include "I_ShootStyle.h"
class Shoot_Berserk :
	public I_ShootStyle
{
public:
	Shoot_Berserk();

	virtual void shoot(sf::Vector2f startShootLocation, GameInstance* GI, float* fireRate, int hp);
};

