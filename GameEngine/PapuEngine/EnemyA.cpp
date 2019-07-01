#include "EnemyA.h"
#include <SDL\SDL.h>


EnemyA::EnemyA(float agent_width,
	float agent_height,
	glm::vec2 position) :
	Agent(agent_width, agent_height, position, "Textures/enemyA.png")
{
	bulletTimer = 0;
	shoot = false;
}

EnemyA::EnemyA(float agent_width,
	float agent_height,
	glm::vec2 position,
	InputManager* _inputmanager
) :Agent(agent_width, agent_height, position, "Textures/enemyA.png") 
{
	inputManager = _inputmanager;
	bulletTimer = 0;
	shoot = false;
}

void EnemyA::update() {
		_position.y -= 0.5f;

		if (bulletTimer >= 10.0){
			bulletTimer = 0;
		}
		else {
			bulletTimer+= 0.1;
		}
}

void EnemyA::setTimer() {
	bulletTimer = 0;
}

std::string EnemyA::getTexture() {
	return _texturePath;
}


EnemyA::~EnemyA()
{
}
