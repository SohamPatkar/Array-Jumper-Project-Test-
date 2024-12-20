#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	GameplayController::GameplayController()
	{

	}

	GameplayController::~GameplayController(){}

	void GameplayController::initialize()
	{

	}

	void GameplayController::update()
	{

	}

	void GameplayController::render()
	{

	}

	void GameplayController::processobstacle()
	{
		Global::ServiceLocator::getInstance()->getPlayerService()->takeDamage();
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
	}

	bool GameplayController::isObstacle(Level::BlockType value)
	{
		if (value == Level::BlockType::OBSTACLE_ONE || value == Level::BlockType::OBSTACLE_TWO)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void GameplayController::onPositionChanged(int position)
	{
		Level::BlockType currentBoxValue = Global::ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValueFromController(position);

		if (isObstacle(currentBoxValue))
		{
			processobstacle();
		}
	}
}