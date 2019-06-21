#include "EnemyA.h"
#include <SDL\SDL.h>


EnemyA::EnemyA(float agent_width,
	float agent_height,
	glm::vec2 position) :
	Agent(agent_width, agent_height, position, "Textures/piedra.png"){
}

EnemyA::EnemyA(float agent_width,
	float agent_height,
	glm::vec2 position,
	InputManager* _inputmanager
) :Agent(agent_width, agent_height, position, "Textures/piedra.png") {
	inputManager = _inputmanager;
}

void EnemyA::update() {
		_position.y -= 2.0f;
}

std::string EnemyA::getTexture() {
	return _texturePath;
}


EnemyA::~EnemyA()
{
}
