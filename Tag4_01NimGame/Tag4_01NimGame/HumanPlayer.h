#pragma once
#include <iostream>
#include "AbstractNimGamePlayer.h"
namespace vw
{
	namespace game
	{
		namespace nim
		{
			namespace player {
				class HumanPlayer : public AbstractNimGamePlayer
				{
					
				public:


					HumanPlayer(const std::string& name)
						: AbstractNimGamePlayer(name)
					{
					}


					auto do_move(size_t stones) const -> int override
					{
						int move;
						write("Es gibt " + std::to_string(stones) + " Steine. Bitte nehmen Sie 1,2 oder 3!");
						std::cin >> move;
						return move;
					}
				};



			}
		}
	}
}