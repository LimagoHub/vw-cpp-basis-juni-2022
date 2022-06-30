// Tag4_01NimGame.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "ConsoleWrite.h"
#include "NimGameImpl.h"
#include "GameClient.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "PigPlayer.h"
using namespace vw::game;


int main()
{
	ConsoleWrite writer;
    nim::NimGameImpl game{writer};
	nim::player::HumanPlayer human{ "Human" };
	nim::player::ComputerPlayer computer{ "Computer" };
	nim::player::PigPlayer pig{ "Miss Piggy" };
	game.add_player(&human);
	game.add_player(&pig);
	game.add_player(&computer);
	
	GameClient client{ game };
	client.run();
	
}

