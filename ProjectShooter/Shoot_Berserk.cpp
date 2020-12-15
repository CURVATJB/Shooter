#include "Shoot_Berserk.h"
#include "GameInstance.h"

Shoot_Berserk::Shoot_Berserk()
{
}

void Shoot_Berserk::shoot(sf::Vector2f startShootLocation, GameInstance* GI, float* fireRate, int hp)
{
	if (hp <= 1 && *fireRate != 0.4f)
	{
		*fireRate = 0.4f;
	}
	GI->CreateProjectile(EnnemyProjectile, startShootLocation, 2.f, 250.f, sf::Vector2f(-1, 0));
}

