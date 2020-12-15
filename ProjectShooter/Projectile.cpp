#include "Projectile.h"
#include "Index.h"
#include <iostream>


void Projectile::UpdateLocation(float deltaTime, sf::Vector2f sizeWindow)
{
	this->sprite.setPosition(this->sprite.getPosition() + direction * this->speed * deltaTime);
	if (this->sprite.getPosition().x > sizeWindow.x || this->sprite.getPosition().x < 0 || this->sprite.getPosition().y > sizeWindow.y || this->sprite.getPosition().y < 0) {
		this->ReInitialize();
	}
	GameObject::UpdateLocation(deltaTime, sizeWindow);
}

void Projectile::EventHit(GameObject* other)
{
	this->instantiated = false;
}

void Projectile::InitializeProjectile(Label _tag, sf::Vector2f _location, float _size, float _speed, sf::Vector2f _direction)
{
	this->Initialize(_tag, _location, _size);
	
	this->speed = _speed;
	this->direction = _direction;
	
	switch (_tag)
	{
	case Label::PlayerProjectile:
		this->sprite.setFillColor(sf::Color::Green);
		break;
	case Label::EnnemyProjectile:
		this->sprite.setFillColor(sf::Color::Red);
		break;
	default:
		break;
	}
}
