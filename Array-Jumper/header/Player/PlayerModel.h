#pragma once

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private:
		int current_position;
		PlayerState player_state;

	public:
		int GetCurrentPosition();
		PlayerState GetPlayerState();
		void SetCurrentPosition(int new_position);
		void SetPlayerState(PlayerState new_player_state);
	};
}