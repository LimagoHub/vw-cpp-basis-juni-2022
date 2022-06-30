#pragma once
namespace vw {
	namespace game {
		namespace player {
			template<class BOARD, class MOVE>
			class Player
			{
			public:
				virtual auto get_name() const noexcept -> std::string = 0;
				virtual auto do_move(BOARD board) const -> MOVE = 0;
			};
		}
	}
}

