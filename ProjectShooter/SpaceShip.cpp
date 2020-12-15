#include "SpaceShip.h"
#include "Index.h"
#include <iostream>

SpaceShip::SpaceShip()
{
}

void SpaceShip::UpdateLocation(float deltaTime, sf::Vector2f sizeWindow)
{
	this->startShootLocation = sf::Vector2f((this->sprite.getPosition().x + this->sprite.getRadius() / 2), this->sprite.getPosition().y);
	GameObject::UpdateLocation(deltaTime, sizeWindow);
}

void SpaceShip::EventHit(GameObject* other)
{
}

void SpaceShip::InitializeSpaceShip(Label _tag, sf::Vector2f _location, float _size, GameInstance* _GI)
{
	GameObject::Initialize(_tag, _location, _size);
	this->GI = _GI;
	switch (_tag)
	{
	case Label::Character:
		this->sprite.setFillColor(sf::Color::Blue);
		this->startShootLocation = sf::Vector2f((_location.x + _size / 2), _location.y);
		break;
	case Label::HostileShip:
		this->sprite.setFillColor(sf::Color(150, 0, 255));
		this->startShootLocation = sf::Vector2f((_location.x - _size / 2), _location.y);
		break;
	default:
		break;
	}
}
