#pragma once
#include "SpaceShip.h"
#include <iostream>


class Player : public SpaceShip
{
public:

	Player() = default;
	void Shoot();
	void UpdateLocation(float deltaTime, sf::Vector2f sizeWindow) override;
	void EventHit(GameObject* other) ;
	void Action(float deltaTime) override;
	void InitializePlayer(Label _tag, sf::Vector2f _location, float _size, GameInstance* _GI, float speed, float fireRate);

private:
	sf::Clock dernierTir{};
	float speed;
	float fireRate;
};

