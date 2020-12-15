#pragma once
#include "GameObject.h"

class GameInstance;

class SpaceShip : public GameObject
{
public:
	SpaceShip();
	virtual ~SpaceShip() = default;
	
	sf::Vector2f startShootLocation;
	GameInstance *GI = nullptr;

public:
	 void UpdateLocation(float deltaTime, sf::Vector2f sizeWindow) override;
	 void EventHit(GameObject* other) override;
	 void InitializeSpaceShip(Label _tag, sf::Vector2f _location, float _size, GameInstance *_GI);
};

