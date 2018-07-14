#pragma once
#include "GameState.h"
class MainMenuState :
	public GameState
{
public:
	void init();
	void cleanup();

	void pause();
	void resume();

	void handleEvents(GameEngine* game);
	void update(GameEngine* game);
	void draw(GameEngine* game);
};

