#include "IntroState.h"
#include "MainMenuState.h"

IntroState IntroState::m_IntroState;

void IntroState::init() {
	// Display intro animation
}

void IntroState::cleanup() {
	// cleanup resources
}

void IntroState::pause() {
	// pause intro - why?
}

void IntroState::resume() {
	// resume intro
}

void IntroState::handleEvents(GameEngine* game) {
	// handle events
	if (InputManager::UP) { printf("Up has been pressed\n"); }
	if (InputManager::DOWN) { printf("Down has been pressed\n"); }
	if (InputManager::LEFT) { printf("Left has been pressed\n"); }
	if (InputManager::RIGHT) { printf("Right has been pressed\n"); }

	if (InputManager::SELECT) { changeState(game, new MainMenuState()); }

}

void IntroState::update(GameEngine* game) {
	// some cool shit
}

void IntroState::draw(GameEngine* game) {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.5f, -0.5f);    // x, y
	glColor3f(0.0f, 1.0f, 0.0f); // Blue
	glVertex2f(0.5f, -0.5f);
	glColor3f(0.0f, 0.0f, 1.0f); // Green
	glVertex2f(0.5f, 0.5f);
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex2f(-0.5f, 0.5f);
	glEnd();
}


