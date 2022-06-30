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
				class ComputerPlayer : public AbstractNimGamePlayer
				{

				public:


					ComputerPlayer(const std::string& name)
						: AbstractNimGamePlayer(name)
					{
					}


					auto do_move(size_t stones) const -> int override
					{
						const int zuege[] = { 3,1,1,2 };
						int move = zuege[stones % 4];
						write("Computer nimmt " + std::to_string(move) + " Steine");
						return move;
					}
				};



			}
		}
	}
}