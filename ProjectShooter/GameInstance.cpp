#include "GameInstance.h"
#include "SFML/Graphics.hpp"
#include <iostream>

GameInstance::GameInstance(Player* _player) : player(_player)
{
	this->sizeWindow.x = 1920.0f;
	this->sizeWindow.y = 1080.0f;
	this->enemies.resize(this->MaxEnemy);
	this->projectiles.resize(this->MaxProjectile);
	this->particles.resize(this->MaxParticle);
	this->renderedObject.resize(this->MaxProjectile + this->MaxEnemy + MaxParticle + 1);
	this->abscisse.resize(this->MaxProjectile + this->MaxEnemy + 1);
	this->renderedObject[0] = this->player;
	this->abscisse[0] = this->player;
	this->score = 0;
	this->deltaTime = 0;
	this->window = new sf::RenderWindow(sf::VideoMode(this->sizeWindow.x, this->sizeWindow.y), "Title", sf::Style::Fullscreen);
	this->window->setVerticalSyncEnabled(true);
	this->enemyManager = new EnemyManager(this);
	this->player->InitializePlayer(Label::Character, sf::Vector2f(100, 500), 10, this, 300.0f, 0.25f);
	this->font.loadFromFile("Font/arial.ttf");
	this->text.setFont(this->font);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(50);
	this->text.setPosition(20, 10);
	this->endText.setFont(this->font);
	this->endText.setFillColor(sf::Color::White);
	this->endText.setCharacterSize(100);
	this->endText.setPosition(this->sizeWindow.x / 4, this->sizeWindow.y / 4);

	unsigned int compteur = 1;

	for (unsigned int i = 0; i < this->enemies.size(); i++)
	{
		this->abscisse[i + compteur] = &this->enemies[i];
		this->renderedObject[i + compteur] = &this->enemies[i];
	}
	compteur += this->MaxEnemy;
	for (unsigned int i = 0; i < this->projectiles.size(); i++)
	{
		this->abscisse[i + compteur] = &this->projectiles[i];
		this->renderedObject[i + compteur] = &this->projectiles[i];
	}
	compteur += this->MaxProjectile;
	for (int i = 0; i < this->particles.size(); i++)
	{
		this->renderedObject[i + compteur] = &this->particles[i];
	}

	this->SortByAbscisse(this->abscisse);
	this->SortByRender(this->renderedObject);
	this->Update();
}

void GameInstance::Update()
{
	sf::Event event;
	sf::Clock clock;
	this->deltaTime = 0;

	while (window->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window->close();
		}
		if (this->player->instantiated == true)
		{
			this->CheckAction(deltaTime);
			this->SortByRender(this->renderedObject);
			this->UpdateLocation(deltaTime, this->sizeWindow);
			this->SortByAbscisse(this->abscisse);
			this->UpdateCollision();
			this->SortByAbscisse(this->abscisse);
			this->SortByRender(this->renderedObject);
			this->text.setString("Score : " + std::to_string(this->score));
			this->Render();
		}
		else
		{
			this->endText.setString("         Fin de partie            \n            Score:" + std::to_string(this->score) + "             \n Appuyer sur echap pour quitter");
			this->window->clear();
			this->window->draw(this->endText);
			this->window->display();
		}
	}
}

void GameInstance::CheckAction(float deltaTime)
{
	for (int i = 0; i < this->renderedObject.size(); i++)
	{
		if (!this->renderedObject[i]->instantiated)
		{
			break;
		}
		this->renderedObject[i]->Action(deltaTime);
	}
	this->enemyManager->Action(deltaTime, this->sizeWindow);
}

void GameInstance::UpdateLocation(float deltaTime, sf::Vector2f sizeWindow)
{
	for (int i = 0; i < this->renderedObject.size(); ++i)
	{
		if (!this->renderedObject[i]->instantiated)
		{
			break;
		}
		this->renderedObject[i]->UpdateLocation(deltaTime, sizeWindow);
	}
}

void GameInstance::UpdateCollision()
{
	for (int i = 0; i < this->abscisse.size(); i++)
	{
		if (!this->abscisse[i]->instantiated)
		{
			break;
		}
		for (unsigned int y = i + 1; y < this->abscisse.size(); y++)
		{
			if (this->abscisse[i]->collision.endAbscisse > this->abscisse[y]->collision.startAbscisse && this->abscisse[y]->instantiated)
			{
				this->TestCollision(this->abscisse[i], this->abscisse[y]);
			}
			else break;
		}
	}
}

void GameInstance::Render()
{
	this->window->clear();
	for (int i = 0; i < this->renderedObject.size(); ++i)
	{
		if (!this->renderedObject[i]->instantiated)
		{
			break;
		}
		this->renderedObject[i]->Render(this->window);
	}
	this->window->draw(this->text);
	this->window->display();
}

void GameInstance::TestCollision(GameObject* a, GameObject* b)
{
	for (Label tag : a->collision.CantCollision)
	{
		if (tag == b->tag)
		{
			return;
		}
	}
	sf::Vector2f const dist(abs(a->sprite.getPosition().x - b->sprite.getPosition().x), abs(a->sprite.getPosition().y - b->sprite.getPosition().y));
	const float minDist = a->sprite.getRadius() + b->sprite.getRadius();
	if (dist.x < minDist && dist.y < minDist)
	{
		a->EventHit(b);
		b->EventHit(a);
	}
}

void GameInstance::CreateProjectile(Label _tag, sf::Vector2f _location, float _size, float _speed, sf::Vector2f _direction)
{
	for (int i = 0; i < this->MaxProjectile; i++)
	{
		if (!this->projectiles[i].instantiated)
		{
			this->projectiles[i].InitializeProjectile(_tag, _location, _size, _speed, _direction);
			break;
		}
	}
}

void GameInstance::CreateEnemy(Label _tag, sf::Vector2f _location, float _size, int _hp, Pattern* _pattern)
{
	for (int i = 0; i < this->MaxEnemy; i++)
	{
		if (!this->enemies[i].instantiated)
		{
			this->enemies[i].InitializeEnemy(_tag, _location, _size, _hp, this, _pattern);
			break;
		}
	}
}

void GameInstance::CreateParticle(Label _tag, sf::Vector2f _location, float _size, float _objectSize)
{
	for (int i = 0; i < this->MaxParticle; i++)
	{
		if (!this->particles[i].instantiated)
		{
			this->particles[i].InitializeParticle(_tag, _location, _size, _objectSize);
			break;
		}
	}
}

void GameInstance::UpdateScore(int point)
{
	this->score += point;
}

void GameInstance::SortByRender(std::vector<GameObject*> &renderTab)
{
	auto renderSort = [](GameObject* const g1, GameObject* const g2) -> bool
	{
		if (g1->instantiated != g2->instantiated) return g1->instantiated > g2->instantiated;
		else return g1->prioRender < g2->prioRender;
	};
	std::sort(renderTab.begin(), renderTab.end(), renderSort);
}

void GameInstance::SortByAbscisse(std::vector<GameObject*> &abscisseTab)
{
	auto abscisseSort = [](GameObject* const g1, GameObject* const g2) -> bool
	{
		if (g1->instantiated != g2->instantiated) return g1->instantiated > g2->instantiated;
		else return (g1->collision.startAbscisse) < (g2->collision.startAbscisse);
	};
	std::sort(abscisseTab.begin(), abscisseTab.end(), abscisseSort);
}
