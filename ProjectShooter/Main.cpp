#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "GameInstance.h"

int main()
{
	//auto player = new Player();
	//auto GI = new GameInstance(player);
	GameInstance GI(new Player());
	return 0;
}