#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include <vector>
#include "GraphicsSettings.h"
using namespace std;

class GameState;
class InputManager;

class GameEngine
{
public:
	// Initialise gameengine object - call immediately after declaration
	void init(const char* title, int width = 640, int height = 480, int bpp = 0, bool fullscreen = false);
	void cleanup();							// cleanup memory, save etc.
	void changeState(GameState* state);		// change to a different game state
	void pushState(GameState* state);		// push a new state onto the stack
	void popState();						// pop a game state from the stack

	void handleEvents();					// call the handleEvents method in the gameState
	void update();							// "
	void draw();							// "

	bool running() { return m_running; }	
	void quit() { m_running = false; }

	sf::Window* window;

private:
	vector<GameState*> states;
	InputManager* im;

	bool m_running;
	bool m_fullscreen;
};
