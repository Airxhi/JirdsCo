#include "InputManager.h"
#include "GameEngine.h"
void InputManager::registerInputs(GameEngine* game) {
	InputManager::UP = false;
	InputManager::DOWN = false;
	InputManager::LEFT = false;
	InputManager::RIGHT = false;
	InputManager::ESC = false;
	InputManager::DASH = false;
	InputManager::RELOAD = false;
	InputManager::GRAPPLE = false;
	InputManager::SHOOT = false;
	InputManager::INTERACT = false;
	InputManager::SELECT = false;

	events.clear();
	sf::Event event;
	while (game->window->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed) {
			events.push_back(event);
		}

		if (event.type == sf::Event::Closed) {
			game->window->close();
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			switch (event.key.code) {
				case sf::Mouse::Left:	InputManager::SHOOT = true;
			}
		}

		else if (event.type == sf::Event::Resized) {
			// adjust the viewport when the window is resized
			glViewport(0, 0, event.size.width, event.size.height);
		}
	}
	sf::Vector2i position = sf::Mouse::getPosition();
	InputManager::MOUSE_X = ((float)position.x) / game->window->getSize().x;
	InputManager::MOUSE_Y = ((float)position.y) / game->window->getSize().y;

	mapInputs();
}

void InputManager::mapInputs() {
	for (sf::Event e : events) {
		switch (e.key.code) {
		case sf::Keyboard::W:		InputManager::UP = true;		break;
		case sf::Keyboard::A:		InputManager::LEFT = true;		break;
		case sf::Keyboard::S:		InputManager::DOWN = true;		break;
		case sf::Keyboard::D:		InputManager::RIGHT = true;		break;
		case sf::Keyboard::Escape:	InputManager::ESC = true;		break;
		case sf::Keyboard::R:		InputManager::RELOAD = true;	break;
		case sf::Keyboard::E:		InputManager::GRAPPLE = true;	break;
		case sf::Keyboard::LShift:	InputManager::DASH = true;		break;
		case sf::Keyboard::F:		InputManager::INTERACT = true;	break;
		case sf::Keyboard::Enter:	InputManager::SELECT = true;	break;
		default: break;
		}
	}
}

bool InputManager::UP = false;
bool InputManager::DOWN = false;
bool InputManager::LEFT = false;
bool InputManager::RIGHT = false;
bool InputManager::ESC = false;
bool InputManager::DASH = false;
bool InputManager::RELOAD = false;
bool InputManager::GRAPPLE = false;
bool InputManager::SHOOT = false;
bool InputManager::INTERACT = false;
bool InputManager::SELECT = false;

float InputManager::MOUSE_X = 0;
float InputManager::MOUSE_Y = 0;