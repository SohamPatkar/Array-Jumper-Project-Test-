#pragma once

namespace Level
{
	class LevelController;
	struct BoxDimensions;
	enum BlockType;

	class LevelService 
	{
	private:
		LevelController* level_controller;

		void destroy();
	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		BlockType getCurrentBoxValueFromController(int currentPosition);
		BoxDimensions getBoxDimensionsFromController();
	};
}