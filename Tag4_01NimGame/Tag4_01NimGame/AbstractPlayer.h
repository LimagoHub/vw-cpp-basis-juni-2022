#pragma once
#include <iostream>
#include "Player.h"
namespace vw
{
	namespace game
	{
		
			namespace player {
				template<class BOARD, class MOVE>
				class AbstractPlayer : public Player<BOARD, MOVE>
				{
					std::string name;


				protected:
					auto write(std::string message) const -> void
					{
						std::cout << message << std::endl;
					}

				public:
					AbstractPlayer(const std::string& name)
						: name(name)
					{
					}


					auto get_name() const noexcept -> std::string override
					{
						return name;
					}
				};



			}
		
	}
}