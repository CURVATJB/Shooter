#include "Shoot_Conic.h"
#include "GameInstance.h"

Shoot_Conic::Shoot_Conic()
{
}

void Shoot_Conic::shoot(sf::Vector2f startShootLocation, GameInstance* GI, float* fireRate, int hp)
{
	GI->CreateProjectile(EnnemyProjectile, startShootLocation, 2.f, 200.f, sf::Vector2f(-1.f, 0.2f));
	GI->CreateProjectile(EnnemyProjectile, startShootLocation, 2.f, 200.f, sf::Vector2f(-1.f, -0.2f));
}
