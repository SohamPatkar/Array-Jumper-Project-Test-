#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelController.h"
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
		box_image = new UI::UIElement::ImageView();
		target_overlay_image = new UI::UIElement::ImageView();
		letter_one_overlay_image = new UI::UIElement::ImageView();
		letter_two_overlay_image = new UI::UIElement::ImageView();
		letter_three_overlay_image = new UI::UIElement::ImageView();
		obstacle_one_overlay_image = new UI::UIElement::ImageView();
		obstacle_two_overlay_image = new UI::UIElement::ImageView();
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
		calculateBoxDimensions();
		background_image->initialize(Global::Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0,0));
		background_image->setImageAlpha(background_alpha);
		box_image->initialize(Global::Config::box_texture_path, box_dimensions.box_width,box_dimensions.box_height,sf::Vector2f(0,0));
		target_overlay_image->initialize(Global::Config::target_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_one_overlay_image->initialize(Global::Config::letter_one_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_two_overlay_image->initialize(Global::Config::letter_two_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_three_overlay_image->initialize(Global::Config::letter_three_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		obstacle_one_overlay_image->initialize(Global::Config::obstacle_01_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		obstacle_two_overlay_image->initialize(Global::Config::obstacle_02_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
	}

	void LevelView::calculateBoxDimensions()
	{
		if (!game_window)
		{
			return;
		}
		box_dimensions.box_width = 300.f;
		box_dimensions.box_height = 300.f;
	}

	void LevelView::updateImages()
	{
		background_image->update();
		box_image->update();
		target_overlay_image->update();
		letter_one_overlay_image->update();
		letter_two_overlay_image->update();
		letter_three_overlay_image->update();
		obstacle_one_overlay_image->update();
		obstacle_two_overlay_image->update();
	}

	void LevelView::drawLevel()
	{
		background_image->render();
		drawBox(sf::Vector2f(0, 0));
		BlockType blockTypeToDraw = level_controller->getCurrentBoxValue(0);
		drawBoxValue(sf::Vector2f(0, 0), blockTypeToDraw);
	}

	void LevelView::deleteImages()
	{
		delete(background_image);
		delete(box_image);
		delete(target_overlay_image);
		delete(letter_one_overlay_image);
		delete(letter_two_overlay_image);
		delete(letter_three_overlay_image);
		delete(obstacle_one_overlay_image);
		delete(obstacle_two_overlay_image);
	}

	UI::UIElement::ImageView* LevelView::getBoxOverlayImage(BlockType block_type)
	{
		switch (block_type)
		{
		case BlockType::OBSTACLE_ONE:
			return obstacle_one_overlay_image;

		case BlockType::OBSTACLE_TWO:
			return obstacle_two_overlay_image;

		case BlockType::ONE:
			return letter_one_overlay_image;

		case BlockType::TWO:
			return letter_two_overlay_image;

		case BlockType::THREE:
			return letter_three_overlay_image;

		case BlockType::TARGET:
			return target_overlay_image;
		}
		return nullptr;
	}

	void LevelView::drawBox(sf::Vector2f Position)
	{
		box_image->setPosition(Position);
		box_image->render();
	}

	void LevelView::drawBoxValue(sf::Vector2f Position, BlockType block_type)
	{
		UI::UIElement::ImageView* image = getBoxOverlayImage(block_type);
		image->setPosition(sf::Vector2f(0,0));
		image->render();
	}
}