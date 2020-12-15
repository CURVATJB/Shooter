#pragma once
#include <list>
#include <vector>
#include "GameObject.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Player.h"
#include "Pattern.h"
#include "ParticleManager.h"
#include "EnemyManager.h"

class GameInstance
{
public:
	GameInstance(Player* _player);

	const int MaxEnemy = 100;
	const int MaxProjectile = 10000;
	const int MaxParticle = 110;

	int score;
	float deltaTime;
	Player* player;
	EnemyManager* enemyManager;
	sf::RenderWindow* window;
	sf::Vector2f sizeWindow;

private:
	std::vector<GameObject*> abscisse;
	std::vector<GameObject*> renderedObject;
	std::vector<Enemy> enemies;
	std::vector<Projectile> projectiles;
	std::vector<ParticleManager> particles;
	sf::Font font;
	sf::Text text;
	sf::Text endText;

public:
	void Update();
	void CheckAction(float deltaTime);
	void UpdateLocation(float deltaTime, sf::Vector2f sizeWindow);
	void UpdateCollision();
	void Render();
	void TestCollision(GameObject* a, GameObject* b);
	void CreateProjectile(Label _tag, sf::Vector2f _location, float _size, float _speed, sf::Vector2f _direction);
	void CreateEnemy(Label _tag, sf::Vector2f _location, float _size, int _hp, Pattern* _pattern);
	void CreateParticle(Label _tag, sf::Vector2f _location, float _size, float _objectSize);
	void UpdateScore(int point);
private:
	void SortByRender(std::vector<GameObject*> &renderTab);
	void SortByAbscisse(std::vector<GameObject*> &abscisseTab);
};
