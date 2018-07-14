#pragma once
#include "GameEngine.h"
class InputManager
{
public:
	void registerInputs(GameEngine* game);
	static bool UP;
	static bool DOWN;
	static bool LEFT;
	static bool RIGHT;
	static bool ESC;
	static bool DASH; // dodge?
	static bool RELOAD;
	static bool GRAPPLE;
	static bool SHOOT;
	static bool INTERACT;
	static bool SELECT;

	static float MOUSE_X;
	static float MOUSE_Y;
private:
	void mapInputs();
	std::vector<sf::Event> events;
};

