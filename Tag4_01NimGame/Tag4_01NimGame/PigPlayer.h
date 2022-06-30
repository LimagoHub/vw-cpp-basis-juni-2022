#pragma once
#include <iostream>
#include <random>
#include <string>
#include "AbstractNimGamePlayer.h"
namespace vw
{
	namespace game
	{
		namespace nim
		{
			namespace player {
				class PigPlayer : public AbstractNimGamePlayer
				{

				public:


					PigPlayer(const std::string& name)
						: AbstractNimGamePlayer(name)
					{
						srand(5);
					}


					auto do_move(size_t stones) const -> int override
					{
						int move = (rand() % 4)  + 1;
						write("Schwein nimmt " + std::to_string(move) + " Steine");
						return move;
					}
				};



			}
		}
	}
}