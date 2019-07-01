#include "EnemyA.h"
#include <SDL\SDL.h>


EnemyA::EnemyA(float agent_width,
	float agent_height,
	glm::vec2 position) :
	Agent(agent_width, agent_height, position, "Textures/enemyA.png")
{
	bulletFrequency = 18;
	shoot = false;
}

EnemyA::EnemyA(float agent_width,
	float agent_height,
	glm::vec2 position,
	InputManager* _inputmanager
) :Agent(agent_width, agent_height, position, "Textures/enemyA.png") 
{
	inputManager = _inputmanager;
	bulletFrequency = 18;
	shoot = false;
}

void EnemyA::update() {
		_position.y -= 2.0f;
		if (bulletFrequency < 18){
			shoot = true;
			bulletFrequency = 0;
		}
}

std::string EnemyA::getTexture() {
	return _texturePath;
}


EnemyA::~EnemyA()
{
}
