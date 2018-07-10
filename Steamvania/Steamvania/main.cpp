#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "GraphicsSettings.h"
#include "GameEngine.h"
#include "IntroState.h"

int main()
{

	sf::Clock clock;
	sf::Time base_t = clock.getElapsedTime();
	sf::Time curr_t = clock.getElapsedTime();
	int counter = 0;

	GameEngine game; 

	game.init("Steamvania");

	game.changeState(IntroState::Instance());

	while (game.running())
	{
		game.handleEvents();	
		game.update();
		game.draw();

		counter += 1;
		curr_t = clock.getElapsedTime();
		if ((curr_t).asMilliseconds() > 1000) {
			std::cout << counter << "\n";
			counter = 0;
			clock.restart();
		}
	}

	return 0;
}

