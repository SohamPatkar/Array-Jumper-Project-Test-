#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"

namespace Player
{
	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
	}

	PlayerController::~PlayerController()
	{
		destroy();
	}

	void PlayerController::initialize()
	{
		player_model->SetPlayerState(PlayerState::ALIVE);
		player_view->initialize();
	}

	void PlayerController::update()
	{
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	void PlayerController::destroy()
	{
		delete(player_model);
		delete(player_view);
	}

	PlayerState PlayerController::GetPlayerState()
	{
		return player_model->GetPlayerState();
	}

	void PlayerController::SetPlayerState(PlayerState player_state)
	{
		player_model->SetPlayerState(player_state);
	}

}