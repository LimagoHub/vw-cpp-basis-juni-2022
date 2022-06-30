#pragma once
#include <iostream>
#include "AbstractPlayer.h"
namespace vw
{
	namespace game
	{
		namespace nim
		{
			namespace player {
				class AbstractNimGamePlayer : public game::player::AbstractPlayer<size_t,int>
				{
				public:
					AbstractNimGamePlayer(const std::string& name)
						: AbstractPlayer<unsigned, int>(name)
					{
					}
				};

				

			}
		}
	}
}