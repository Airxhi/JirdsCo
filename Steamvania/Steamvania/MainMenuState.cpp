#include "MainMenuState.h"

void MainMenuState::init() {
	// Display intro animation
}

void MainMenuState::cleanup() {
	// cleanup resources
}

void MainMenuState::pause() {
	// pause intro - why?
}

void MainMenuState::resume() {
	// resume intro
}

void MainMenuState::handleEvents(GameEngine* game) {

}

void MainMenuState::update(GameEngine* game) {
	// some cool shit
}

void MainMenuState::draw(GameEngine* game) {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.0f); // Blue
	glVertex2f(-0.5f, -0.5f);    // x, y
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(0.5f, -0.5f);
	glColor3f(0.0f, 0.0f, 1.0f); // Green
	glVertex2f(0.5f, 0.5f);
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex2f(-0.5f, 0.5f);
	glEnd();
}

