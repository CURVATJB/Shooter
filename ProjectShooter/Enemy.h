#pragma once
#include "SpaceShip.h"
#include "Pattern.h"

class Enemy : public SpaceShip
{
public:
	Enemy() = default;
	virtual ~Enemy();

	Pattern* pattern;
	bool isGoUp = false;
	int hp;
	float fireRate = 1;

	void Action(float deltaTime) override;
	void EventHit(GameObject* other);
	void UpdateLocation(float delteTime, sf::Vector2f sizeWindow) override;
	void InitializeEnemy(Label _tag, sf::Vector2f _location, float _size, int hp, GameInstance* _GI, Pattern* pattern);

private:
	float timerFire = 0;
};

