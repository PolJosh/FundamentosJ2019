#include "Gamer.h"
#include <SDL\SDL.h>


Gamer::Gamer(float agent_width,
	float agent_height,
	glm::vec2 position,
	std::string texture):
	Agent(agent_width,agent_height,position,texture)
{
	shoot = false;
	recovery = 0;
}

Gamer::Gamer(float agent_width,
	float agent_height,
	glm::vec2 position,
	std::string texture,
	InputManager* _inputmanager
) :Agent(agent_width, agent_height, position, texture) {
	inputManager = _inputmanager;
	shoot = false;
	recovery = 0;
}

void Gamer::update() {
	if (inputManager->isKeyDown(SDLK_w)) {
		_position.y += 8.0f;
	}

	if (inputManager->isKeyDown(SDLK_s)) {
		_position.y -= 8.0f;
	}

	if (inputManager->isKeyDown(SDLK_d)) {
		_position.x += 8.0f;
	}

	if (inputManager->isKeyDown(SDLK_a)) {
		_position.x -= 8.0f;
	}

	if (inputManager->isKeyDown(SDLK_SPACE) && recovery >= 8) {
		shoot = true;
		recovery == 0;
	}
	else { shoot = false; }

	if (recovery < 8)
		recovery++;
}

std::string Gamer::getTexture() {
	return _texturePath;
}


Gamer::~Gamer()
{
}
