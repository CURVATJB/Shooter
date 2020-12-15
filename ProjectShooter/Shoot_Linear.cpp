#include "Shoot_Linear.h"
#include "GameInstance.h"


Shoot_Linear::Shoot_Linear()
{
}


Shoot_Linear::~Shoot_Linear()
{
}

void Shoot_Linear::shoot(sf::Vector2f startShootLocation, GameInstance* GI, float* fireRate, int hp)
{
	GI->CreateProjectile(EnnemyProjectile, startShootLocation, 2.f, 250.f, sf::Vector2f(-1, 0));
}
