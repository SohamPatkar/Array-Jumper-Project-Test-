#include "../../header/Player/PlayerService.h"
#include "../../header/Player/PlayerController.h"

namespace Player
{
	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		destroy();
	}

	void PlayerService::initialize()
	{
		player_controller->initialize();
	}

	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::render()
	{
		player_controller->render();
	}

	void PlayerService::destroy()
	{
		delete(player_controller);
	}

	void PlayerService::resetPlayer()
	{
		player_controller->reset();
	}

	void PlayerService::takeDamage()
	{
		player_controller->takeDamage();
	}

	void PlayerService::levelComplete()
	{
		player_controller->reset();
	}

	int PlayerService::GetCurrentLives()
	{
		return player_controller->GetCurrentLives();
	}
}