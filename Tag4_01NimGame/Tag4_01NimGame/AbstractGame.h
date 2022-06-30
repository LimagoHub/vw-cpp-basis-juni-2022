#pragma once
#include "Game.h"
#include "Player.h"
#include "Writer.h"
namespace vw {
	namespace game {
		

			template<class BOARD, class MOVE>
			class AbstractGame:public Game
			{
				using GenericPlayer = player::Player<BOARD, MOVE>;
				
				std::vector<const GenericPlayer *> players;
				BOARD board;
				MOVE move;
				Writer& writer_;

				const GenericPlayer* current_player;


				const GenericPlayer* get_current_player() const
				{
					return current_player;
				}

				void set_current_player(const GenericPlayer* current_player)
				{
					this->current_player = current_player;
				}

				auto execute_roundbased_turns() -> void
				{
					for (const GenericPlayer* player: get_players())
					{
						prepare_single_turn(player);
					}
				}

				auto prepare_single_turn(const GenericPlayer* player) -> void
				{
					if (is_gameover()) return;
					set_current_player(player);
					execute_single_turn();
				}

				auto execute_single_turn() -> void
				{
					execute_move_for_current_player();
					terminate_move();

				}

				auto terminate_move() -> void
				{
					update_board();
					print_gameovermessage_if_game_is_over();
				}
				
				auto execute_move_for_current_player() -> void
				{

					do
					{
						set_move(get_current_player()->do_move(get_board()));

					} while (players_turn_is_invalid());
				}

				[[nodiscard]] auto players_turn_is_invalid() const noexcept -> bool
				{
					if (is_move_valid())
						return false;
					write("ungueltiger zug");
					return true;
				}


				auto print_gameovermessage_if_game_is_over() const noexcept -> void
				{
					if (is_gameover())
						write("Spieler " + get_current_player()->get_name() + " hat verloren");

				}

			protected:


				AbstractGame(Writer& writer)
					: writer_(writer)
				{
				}

			
				virtual [[nodiscard]] auto is_gameover()const noexcept  -> bool = 0;
				virtual [[nodiscard]] auto is_move_valid() const noexcept ->bool = 0;
				virtual auto update_board() -> void = 0;
				
				BOARD get_board() const
				{
					return board;
				}

				void set_board(const BOARD& board)
				{
					this->board = board;
				}

				MOVE get_move() const
				{
					return move;
				}

				void set_move(const MOVE& move)
				{
					this->move = move;
				}

				auto get_players() const -> std::vector<const GenericPlayer*>
				{
					return players;
				}

				auto write(std::string message)const noexcept  -> void
				{
					writer_.write(message);
				}


				
				
			
			public:

				
				
				auto add_player(const GenericPlayer* player)
				{
					players.push_back(player);
				}
				
				auto play() -> void override
				{
					while (!is_gameover())
						execute_roundbased_turns();

				}
			};

	}
}


