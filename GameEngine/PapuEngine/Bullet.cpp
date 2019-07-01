#include "Bullet.h"
#include "ResourceManager.h"
#include "GLTexture.h"

Bullet::Bullet(float agent_width,
	float agent_height,
	glm::vec2 position,
	int dir, float speed, int _origin):
	Agent(agent_width, agent_height, position, "Textures/bullet.png")
{
	_direction = dir;
	_speed = speed;
}

Bullet::Bullet(float agent_width,
	float agent_height,
	glm::vec2 position,
	InputManager* _inputmanager,
	int dir, float speed, int _origin) :
	Agent(agent_width, agent_height, position, "Textures/bullet.png")
{
	inputManager = _inputmanager;
	_direction = dir;
	_speed = speed;
}

void Bullet::update() {
	_position.y -= (2.0f * -_direction);
}

std::string Bullet::getTexture() {
	return _texturePath;
}


Bullet::~Bullet()
{
}
