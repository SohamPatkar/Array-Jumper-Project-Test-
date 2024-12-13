#include "../../header/Player/PlayerView.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Global/Config.h"

using namespace UI::UIElement;
using namespace Global;

namespace Player
{
	PlayerView::PlayerView(PlayerController* controller)
	{
		calculatePlayerDimensions();
		player_controller = controller;
		game_window = nullptr;
		player_image = new ImageView();
	}

	PlayerView::~PlayerView()
	{

	}

	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		loadPlayer();
	}

	void PlayerView::update()
	{
		updatePlayerPosition();
	}

	void PlayerView::render()
	{
		switch (player_controller->GetPlayerState())
		{
			case PlayerState::ALIVE:
				drawPlayer();
			break;
		}
	}

	void PlayerView::calculatePlayerDimensions()
	{
		player_width = 1000.f;
		player_height = 1000.f;
	}

	void PlayerView::initializePlayerImage()
	{
		player_image->initialize(Config::character_texture_path, player_width, player_height, sf::Vector2f(100, 100));
	}

	void PlayerView::loadPlayer()
	{
		calculatePlayerDimensions();
		initializePlayerImage();
	}

	sf::Vector2f PlayerView::calculatePlayerPosition()
	{
		return sf::Vector2f(100, 100);
	}

	void PlayerView::updatePlayerPosition()
	{
		player_image->setPosition(calculatePlayerPosition());
	}

	void PlayerView::drawPlayer()
	{
		player_image->render();
	}
}