#include "../../header/Level/LevelModel.h"
#include "../../header/Level/BlockType.h"

namespace Level
{
	LevelModel::LevelModel()
	{
		
	}

	LevelModel::~LevelModel()
	{

	}

	BlockType LevelModel::getBoxValue(int currentPosition)
	{
		return current_level_data.level_boxes[currentPosition];
	}
}