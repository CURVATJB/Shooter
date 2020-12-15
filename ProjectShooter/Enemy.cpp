#include "Enemy.h"
#include "GameInstance.h"

Enemy::~Enemy()
{
}

void Enemy::Action(float deltaTime)
{
	timerFire += deltaTime;
	if (timerFire >= fireRate) {
		pattern->shootStyle->shoot(startShootLocation, GI, &fireRate, hp);
		timerFire = 0;
	}
}

void Enemy::EventHit(GameObject* other)
{
	--this->hp;
	if (hp <= 0)
	{
		GI->CreateParticle(Label::Particles, this->sprite.getPosition(), 5.f, this->sprite.getRadius());
		GI->UpdateScore(10);
		ReInitialize();
	}
}

void Enemy::UpdateLocation(float deltaTime, sf::Vector2f sizeWindow)
{
	this->pattern->moveStyle->move(deltaTime, sizeWindow, &this->sprite, isGoUp);
	SpaceShip::UpdateLocation(deltaTime, sizeWindow);
}

void Enemy::InitializeEnemy(Label _tag, sf::Vector2f _location, float _size,int hp, GameInstance* _GI, Pattern* pattern)
{
	this->InitializeSpaceShip(_tag, _location, _size, _GI);
	this->pattern = pattern;
	this->hp = hp;
}


