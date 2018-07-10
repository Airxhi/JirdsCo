#pragma once
#include "GameState.h"
class IntroState :
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

	static IntroState* Instance() {
		return &m_IntroState;
	}
private:
	static IntroState m_IntroState;
};

