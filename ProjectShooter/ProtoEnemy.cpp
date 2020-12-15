#include "ProtoEnemy.h"
/*

ProtoEnemy::ProtoEnemy()
{
}

ProtoEnemy::~ProtoEnemy()
{
}

/*void ProtoEnemy::UpdateLocation(float deltaTime, sf::Vector2f sizeWindow)
{
	if (this->sprite.getPosition().y <= 20) {
		isGoUp = false;
		GoDown(deltaTime);
	}
	else if (this->sprite.getPosition().y >= 1060) {
		isGoUp = true;
		GoUp(deltaTime);
	}
	else if (this->sprite.getPosition().y <= 1060 && !isGoUp) {
		GoDown(deltaTime);
	}
	else if (this->sprite.getPosition().y >= 20 && isGoUp) {
		GoUp(deltaTime);
	}
}

void ProtoEnemy::GoUp(float deltaTime)
{	
	this->sprite.setPosition(this->sprite.getPosition().y, this->sprite.getPosition().y + 2.f * deltaTime);
}

void ProtoEnemy::GoDown(float deltaTime)
{
	this->sprite.setPosition(this->sprite.getPosition().y, this->sprite.getPosition().y - 0.1f * deltaTime);
}

void ProtoEnemy::Fire()
{
	this->GI->CreateProjectile(EnnemyProjectile, startShootLocation, 2.f, 2.0f, sf::Vector2f(-1, 0));
}*/


