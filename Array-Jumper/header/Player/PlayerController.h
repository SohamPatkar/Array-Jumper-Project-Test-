#pragma once

namespace Player
{
	enum class PlayerState;
	class PlayerView;
	class PlayerModel;

	class PlayerController
	{
	private:
		PlayerView* player_view;
		PlayerModel* player_model;

		void destroy();
	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState player_state);
	};
}
