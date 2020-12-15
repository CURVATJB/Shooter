#include "GameObject.h"
#include "Index.h"
#include <iostream>

void GameObject::Action(float deltaTime)
{
}

void GameObject::UpdateLocation(float deltaTime, sf::Vector2f sizeWindow)
{
	this->collision.startAbscisse = this->sprite.getPosition().x - this->sprite.getRadius() / 2;
	this->collision.endAbscisse = this->sprite.getPosition().x + this->sprite.getRadius() / 2;
}

void GameObject::EventHit(GameObject* other)
{
}

void GameObject::Initialize(Label _tag, sf::Vector2f _location, float _size)
{
	this->sprite.setPosition(_location);
	this->sprite.setRadius(_size);
	this->sprite.setOrigin(_size, _size);
	this->tag = _tag;

	switch (_tag)
	{
	case Label::Character:
		this->collision.CantCollision = std::list<Label>{ Label::PlayerProjectile };
		this->prioRender = 5;
		break;
	case Label::HostileShip:
		this->collision.CantCollision = std::list<Label>{ Label::HostileShip, Label::EnnemyProjectile };
		this->prioRender = 4;
		break;
	case Label::PlayerProjectile:
		this->collision.CantCollision = std::list<Label>{ Label::Character, Label::PlayerProjectile, Label::EnnemyProjectile };
		this->prioRender = 2;
		break;
	case Label::EnnemyProjectile:
		this->collision.CantCollision = std::list<Label>{ Label::EnnemyProjectile, Label::HostileShip,  Label::PlayerProjectile };
		this->prioRender = 2;
		break;
	case Label::Particles:
		this->prioRender = 1;
	default:
		break;
	}

	this->collision.startAbscisse = _location.x - _size;
	this->collision.endAbscisse = _location.x + _size;
	this->instantiated = true;
}

void GameObject::Render(sf::RenderWindow * window)
{
	window->draw(this->sprite);
}

void GameObject::ReInitialize()
{
	instantiated = false;
}
