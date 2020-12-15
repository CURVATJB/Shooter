#pragma once
#include "GameObject.h"

struct Particle
{
	sf::CircleShape sprite;
	sf::Vector2f direction;
};

class ParticleManager : public GameObject
{
public:
	ParticleManager();

private:
	std::vector<Particle> particles;
	float lifeTime;
	float speed;
	sf::Clock time;
public:
	void UpdateLocation(float deltaTime, sf::Vector2f sizeWindow) override;
	void InitializeParticle(Label _tag, sf::Vector2f _location, float _size, float _sizeObject);
	void Render(sf::RenderWindow* window) override;
};
