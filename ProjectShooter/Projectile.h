#pragma once
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	Projectile() = default;
	virtual ~Projectile() = default;

	float speed;
	sf::Vector2f direction;

	void UpdateLocation(float deltaTime, sf::Vector2f sizeWindow) override;
	void EventHit(GameObject* other) override;
	void InitializeProjectile(Label _tag, sf::Vector2f _location, float _size, float _speed, sf::Vector2f _direction);
};

