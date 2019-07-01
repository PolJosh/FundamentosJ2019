#pragma once
#include "Agent.h"
#include "InputManager.h"

class Bullet : public Agent
{
private:
	InputManager* inputManager;
	float _speed;
	int _direction;
	int origin;
public:
	Bullet(float agent_width,
		float agent_height,
		glm::vec2 position,
		int dir, float speed, int _origin);
	Bullet(float agent_width,
		float agent_height,
		glm::vec2 position,
		InputManager* _inputManager,
		int dir, float speed, int _origin);
	void update();
	void setPosition(glm::vec2 position) {
		_position = position;
	}
	glm::vec2 getPosition() {
		return _position;
	}
	float getWidth() {
		return _agent_width;
	}
	float getHeight() {
		return _agent_height;
	}
	std::string getTexture();
	void changeTexture(std::string texturePath) {
		_texturePath = texturePath;
	}
	~Bullet();
};

