#pragma once

namespace Level
{
	class LevelModel;
	class LevelView;
	enum  BlockType;

	class LevelController
	{
	private:
		LevelModel* level_model;
		LevelView* level_view;

	public:
		LevelController();
		~LevelController();

		BlockType getCurrentBoxValue(int currentPosition);

		void initialize();
		void update();
		void render();
	};
}