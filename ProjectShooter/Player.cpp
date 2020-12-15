#include "Player.h"
#include "GameInstance.h"



void Player::Shoot()
{
	this->GI->CreateProjectile(PlayerProjectile, this->startShootLocation, 5, 1000, sf::Vector2f(1, 0));
}

void Player::UpdateLocation(float deltaTime, sf::Vector2f sizeWindow)
{
	sf::Vector2f direction(0, 0);

	//Identification de l'input 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction.x = direction.x + 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction.x = direction.x - 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction.y = direction.y - 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction.y = direction.y + 1;		
	}

	this->sprite.setPosition(this->sprite.getPosition() + direction * this->speed * deltaTime);

	//Empêche le joueur de sortir de la fenêtre 
	if (sprite.getPosition().x < this->sprite.getRadius()) {
		sprite.setPosition(this->sprite.getRadius(), sprite.getPosition().y);
	}

	if (sprite.getPosition().x > sizeWindow.x - this->sprite.getRadius()) {
		sprite.setPosition(sizeWindow.x - this->sprite.getRadius(), sprite.getPosition().y);
	}

	if (sprite.getPosition().y < this->sprite.getRadius()) {
		sprite.setPosition(sprite.getPosition().x, this->sprite.getRadius());
	}

	if (sprite.getPosition().y > sizeWindow.y- this->sprite.getRadius()) {
		sprite.setPosition(sprite.getPosition().x, sizeWindow.y - this->sprite.getRadius());
	}
	
	SpaceShip::UpdateLocation(deltaTime, sizeWindow);
}

void Player::Action(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && dernierTir.getElapsedTime().asSeconds() > fireRate) {
		this->Shoot();
		dernierTir.restart();
	}
}

void Player::InitializePlayer(Label _tag, sf::Vector2f _location, float _size, GameInstance* _GI, float speed, float fireRate)
{
	this->InitializeSpaceShip(_tag,  _location,  _size, _GI);
	this->speed = speed;
	this->fireRate = fireRate;
}

void Player::EventHit(GameObject* other)
{
	this->instantiated = false;
}


