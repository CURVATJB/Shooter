#include "ParticleManager.h"

ParticleManager::ParticleManager()
{
}

void ParticleManager::UpdateLocation(float deltaTime, sf::Vector2f sizeWindow)
{
	//lifeTime -= deltaTime;
	//if(lifeTime <= 0)
	//{
	//	this->ReInitialize();
	//}
	if (this->time.getElapsedTime().asSeconds() > this->lifeTime)
	{
		this->ReInitialize();
	}
	else
	{
		for (int i = 0; i < this->particles.size(); i++)
		{
			particles[i].sprite.setPosition(particles[i].sprite.getPosition() + this->speed * particles[i].direction * deltaTime);
		}
	}
}

void ParticleManager::InitializeParticle(Label _tag, sf::Vector2f _location, float _size, float _sizeObject)
{
	this->Initialize(_tag, _location, _size);
	this->particles.resize(8);
	this->particles[0].sprite.setPosition(_location.x + _sizeObject, _location.y);
	this->particles[0].direction = sf::Vector2f(1, 0);
	this->particles[1].sprite.setPosition(_location.x - _sizeObject, _location.y);
	this->particles[1].direction = sf::Vector2f(-1, 0);
	this->particles[2].sprite.setPosition(_location.x, _location.y + _sizeObject);
	this->particles[2].direction = sf::Vector2f(0, 1);
	this->particles[3].sprite.setPosition(_location.x, _location.y - _sizeObject);
	this->particles[3].direction = sf::Vector2f(0, -1);
	this->particles[4].sprite.setPosition(_location.x + _sizeObject, _location.y + _sizeObject);
	this->particles[4].direction = sf::Vector2f(1, 1);
	this->particles[5].sprite.setPosition(_location.x + _sizeObject, _location.y - _sizeObject);
	this->particles[5].direction = sf::Vector2f(1, -1);
	this->particles[6].sprite.setPosition(_location.x - _sizeObject, _location.y + _sizeObject);
	this->particles[6].direction = sf::Vector2f(-1, 1);
	this->particles[7].sprite.setPosition(_location.x - _sizeObject, _location.y - _sizeObject);
	this->particles[7].direction = sf::Vector2f(-1, -1);
	for (int i = 0; i < 8; i++)
	{
		this->particles[i].sprite.setRadius(_size);
		this->particles[i].sprite.setFillColor(sf::Color::White);
	}
	this->lifeTime = 3;
	this->speed = 100;
	time.restart();
}

void ParticleManager::Render(sf::RenderWindow* window)
{
	for (int i = 0; i < this->particles.size(); i++)
	{
		window->draw(this->particles[i].sprite);
	}
}
