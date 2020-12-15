#pragma once
#include <vector>
#include "Pattern.h"
#include "Index.h"


class GameInstance;
class EnemyManager
{
public:
	EnemyManager(GameInstance* GI);
	~EnemyManager();

	std::vector<Pattern> listPattern;
	GameInstance *GI = nullptr;
	
	void Action(float deltaTime, sf::Vector2f sizeWindow);

private:
	float time = 0;
	float timerSpawnEnnemy = 0;
	float spawnRateEnemy = 1.5;
	int currentTrunc;
	int lastTrunc = 0;
	int patternChangeRate = 15;
	float hpChangeRate = 20;
	float timerHp;
	int hp = 1;
	int maxHp = 4;
	std::vector<Pattern> allPatterns;
	std::vector<Pattern*> currentPatternsUse;
	std::vector<I_ShootStyle*> shootStyles;
	std::vector<I_MoveStyle*> moveStyles;

	int GetRandY(sf::Vector2f sizeWindow);
	int GetRandX(sf::Vector2f sizeWindow);
	int GetRandHp();
	void UpdateHp(float deltaTime);
	void UpdateEnemySpawn(float deltaTime, sf::Vector2f sizeWindow);
	void UpdatePattern(float deltaTime);

	Pattern* getRandomPattern(int size);
};

