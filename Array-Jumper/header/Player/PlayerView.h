#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

namespace Player
{
	class PlayerView
	{

	private:
		UI::UIElement::ImageView* player_image;
		sf::RenderWindow* game_window;

		float player_height;
		float player_width;

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		void calculatePlayerDimensions();
		void updatePlayerPosition();
		sf::Vector2f calculatePlayerPosition();

	public:
		PlayerView();
		~PlayerView();

		void initialize();
		void update();
		void render();
	};
}