#include "../../header/Player/PlayerModel.h"

namespace Player
{
	int PlayerModel::GetCurrentPosition()
	{
		return current_position;
	}

	void PlayerModel::SetCurrentPosition(int new_position)
	{
		current_position = new_position;
	}

	PlayerState PlayerModel::GetPlayerState()
	{
		return player_state;
	}

	void PlayerModel::SetPlayerState(PlayerState new_player_state)
	{
		player_state = new_player_state;
	}
}	