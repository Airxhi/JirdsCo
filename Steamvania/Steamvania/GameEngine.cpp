#include "GameEngine.h"
#include "GameState.h"

void GameEngine::init(const char* title, int width, int height, int bpp, bool fullscreen) {
	// init some shit
	GraphicsSettings graphics_settings;
	window = new sf::Window(sf::VideoMode(graphics_settings.width, graphics_settings.height), "Steamvania", graphics_settings.style);
	window->setActive(true);
	window->setFramerateLimit(60);
	
	m_running = true;

	printf("GameEngine init\n");
}

void GameEngine::cleanup() {
	while (!states.empty()) {
		states.back()->cleanup();
		states.pop_back();
	}
	printf("GamneEngine cleanup\n");
}

void GameEngine::changeState(GameState* state) {
	// cleanup the current state
	if (!states.empty()) {
		states.back()->cleanup();
		states.pop_back();
	}

	states.push_back(state);
	states.back()->init();
}

void GameEngine::pushState(GameState* state)
{
	// pause current state
	if (!states.empty()) {
		states.back()->pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->init();
}

void GameEngine::popState()
{
	// cleanup the current state
	if (!states.empty()) {
		states.back()->cleanup();
		states.pop_back();
	}

	// resume previous state
	if (!states.empty()) {
		states.back()->resume();
	}
}

void GameEngine::handleEvents() {
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		else if (event.type == sf::Event::Resized) {
			// adjust the viewport when the window is resized
			glViewport(0, 0, event.size.width, event.size.height);
		}
	}

	// let the states handles the events
	states.back()->handleEvents(this);
}

void GameEngine::update() {
	states.back()->update(this);
}

void GameEngine::draw() {
	states.back()->draw(this);
	window->display();
}