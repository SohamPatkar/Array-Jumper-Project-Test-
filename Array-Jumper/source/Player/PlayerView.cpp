#include "../../header/Player/PlayerView.h"



using namespace UI::UIElement;
using namespace Global;

namespace Player
{
	PlayerView::PlayerView()
	{
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
		drawPlayer();
	}

	void PlayerView::calculatePlayerDimensions()
	{
		player_width = 1000.0f;
		player_height = 1000.0f;
	}

	void PlayerView::initializePlayerImage()
	{
		player_image->initialize(Config::character_texture_path, player_width, player_height, sf::Vector2f(2,0));
	}

	void PlayerView::loadPlayer()
	{
		calculatePlayerDimensions();
		initializePlayerImage();
	}

	sf::Vector2f PlayerView::calculatePlayerPosition()
	{
		return sf::Vector2f(0, 0);
	}

	void PlayerView::updatePlayerPosition()
	{
		player_image->setPosition(calculatePlayerPosition());
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