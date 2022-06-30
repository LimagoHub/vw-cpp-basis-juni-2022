#pragma once
#include <iostream>
#include <vector>

#include "string"
#include "AbstractGame.h"
#include "Player.h"

namespace vw
{
	namespace game
	{
		namespace nim
		{

			using namespace vw::game::player;
			
			class NimGameImpl :
				public AbstractGame<size_t, int>
			{
					

				
			protected:

				auto update_board() -> void override
				{
					set_board(get_board() - get_move());
				}

				[[nodiscard]] auto is_move_valid() const noexcept ->bool override
				{
					return get_move() >= 1 && get_move() <= 3;
				}
				
				[[nodiscard]] auto is_gameover()const noexcept   -> bool override
				{
					return get_board() < 1 || get_players().empty();
				}
			
			public:


				NimGameImpl(Writer& writer)
					: AbstractGame<size_t, int>(writer)
				{
					set_board(23);
				}
			};
		}
	}
}


