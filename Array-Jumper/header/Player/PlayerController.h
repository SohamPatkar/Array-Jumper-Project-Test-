#pragma once
#include "../../header/Event/EventService.h"

namespace Player
{
	enum class PlayerState;
	class PlayerView;
	class PlayerModel;
	enum MovementDirection;

	class PlayerController
	{
	private:
		PlayerView* player_view;
		PlayerModel* player_model;
		Event::EventService* event_service;

		void destroy();
	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();
		void move(MovementDirection direction);
		void readInput();

		int getCurrentPosition();
		bool isPositionInBound(int targetPosition);

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState player_state);
	};
}
