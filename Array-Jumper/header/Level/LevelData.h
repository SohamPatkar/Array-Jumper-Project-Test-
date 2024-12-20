#pragma once
#include "../../header/Level/BlockType.h"

namespace Level
{
	struct LevelData
	{
		static const int number_of_boxes = 10;
		BlockType level_boxes[number_of_boxes] = 
		{
			BlockType::THREE,
			BlockType::OBSTACLE_ONE,
			BlockType::OBSTACLE_TWO,
			BlockType::ONE,
			BlockType::TWO,
			BlockType::TARGET,
			BlockType::ONE,
			BlockType::TWO,
			BlockType::THREE,
			BlockType::TARGET
		};
	};
}