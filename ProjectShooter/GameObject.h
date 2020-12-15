#pragma once
#include <SFML/Graphics.hpp>
#include "Index.h"
#include <list>

struct Collision
{
	float startAbscisse;
	float endAbscisse;
	std::list<Label> CantCollision;
};

class GameObject
{
public:

	GameObject() = default;
	virtual ~GameObject() = default;

	sf::CircleShape sprite;
	Collision collision;
	Label tag;
	int prioRender;
	bool instantiated = false;

public:

	virtual void Action(float deltaTime);
	virtual void UpdateLocation(float deltaTime, sf::Vector2f sizeWindow);
	virtual void EventHit(GameObject* other);
	virtual void Initialize(Label _tag, sf::Vector2f _location,float _size);
	virtual void Render(sf::RenderWindow* window);
	void ReInitialize();
};

