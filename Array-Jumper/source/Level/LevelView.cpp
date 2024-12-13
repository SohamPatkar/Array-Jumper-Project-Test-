#include "../../header/Level/LevelView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

namespace Level
{
	LevelView::LevelView(LevelController* controller)
	{
		level_controller = controller;
		game_window = nullptr;
		createImages();
	}

	LevelView::~LevelView()
	{
		deleteImages();
	}

	void LevelView::createImages()
	{
		background_image = new UI::UIElement::ImageView();
	}

	void LevelView::initialize()
	{
		game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeImages();
	}

	void LevelView::update()
	{
		updateImages();
	}

	void LevelView::render()
	{
		drawLevel();
	}

	void LevelView::initializeImages()
	{
		background_image->initialize(Global::Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0,0));
		background_image->setImageAlpha(background_alpha);
	}

	void LevelView::updateImages()
	{
		background_image->update();
	}

	void LevelView::drawLevel()
	{
		background_image->render();
	}

	void LevelView::deleteImages()
	{
		delete(background_image);
	}
}