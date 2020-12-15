#include "EnemyManager.h"
#include <random>
#include <math.h>
#include "GameInstance.h"
#include <iostream>

EnemyManager::EnemyManager(GameInstance* GI)
{	
	this->GI = GI;
	
	allPatterns.resize(6);
	allPatterns[0].InitializePattern("Linear Top", E_ShootLinear, E_MoveCloseTop);
	allPatterns[1].InitializePattern("Linear Bot", E_ShootLinear, E_MoveCloseBot);
	allPatterns[2].InitializePattern("Conic Far", E_ShootConic, E_MoveFar);
	allPatterns[3].InitializePattern("Conic Top", E_ShootConic, E_MoveFar);
	allPatterns[4].InitializePattern("Conic Bot", E_ShootConic, E_MoveFar);
	allPatterns[5].InitializePattern("Berserk", E_ShootBerserk, E_MoveFar);

	currentPatternsUse.resize(1);
	currentPatternsUse[0] = &allPatterns[0];
}

EnemyManager::~EnemyManager()
{
}


void EnemyManager::Action(float deltaTime, sf::Vector2f sizeWindow)
{
	UpdatePattern(deltaTime);
	UpdateEnemySpawn(deltaTime, sizeWindow);
	UpdateHp(deltaTime);
}

int EnemyManager::GetRandY(sf::Vector2f sizeWindow)
{
	int maxY = sizeWindow.y - 20;
	return rand() % maxY + 20;
}

int EnemyManager::GetRandX(sf::Vector2f sizeWindow)
{
	int maxX = sizeWindow.x - 100;
	int minX = sizeWindow.x - 500;
	return rand() % 300 + 1500;
}

int EnemyManager::GetRandHp()
{
	if (hp >= maxHp) {
		return maxHp;
	}
	return rand() % hp + 1;
}

void EnemyManager::UpdateHp(float deltaTime)
{
	timerHp += deltaTime;
	if (timerHp >= hpChangeRate)
	{
		hp++;
		timerHp = 0;
	}
}

void EnemyManager::UpdateEnemySpawn(float deltaTime, sf::Vector2f sizeWindow)
{
	timerSpawnEnnemy += deltaTime;
	if (timerSpawnEnnemy >= spawnRateEnemy)
	{
		GI->CreateEnemy(HostileShip, sf::Vector2f(GetRandX(sizeWindow), GetRandY(sizeWindow)), 20.f, GetRandHp(), getRandomPattern(currentPatternsUse.size()));
		timerSpawnEnnemy = 0;
	}
}

void EnemyManager::UpdatePattern(float deltaTime)
{
	time += deltaTime;
	currentTrunc = trunc(time) / patternChangeRate;
	if (currentTrunc > lastTrunc && currentTrunc <= 3) {
		lastTrunc = currentTrunc;
		currentPatternsUse.resize(currentTrunc + 1);
		currentPatternsUse[currentTrunc] = &allPatterns[currentTrunc];
	}
}

Pattern* EnemyManager::getRandomPattern(int size)
{
	if (size == 0) {
		return currentPatternsUse[0];
	}
	else if (size > allPatterns.size()) {
		size = allPatterns.size();
	}
	return currentPatternsUse[rand() % size];
}
