#pragma once

#include "Game.h"

using namespace vw::game;
class GameClient
{
	Game& game;


public:
	GameClient(Game& game)
		: game(game)
	{
	}

	void run()
	{
		game.play();
	}
};

