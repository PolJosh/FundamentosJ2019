#pragma once
#include "Agent.h"
#include "InputManager.h"

class EnemyA : public Agent
{
private:
	InputManager* inputManager;
	int bulletFrequency;
	bool shoot;
public:
	EnemyA(float agent_width,
		float agent_height,
		glm::vec2 position);
	EnemyA(float agent_width,
		float agent_height,
		glm::vec2 position,
		InputManager* _inputManager);
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
	bool getShoot() {
		return shoot;
	}
	std::string getTexture();
	void changeTexture(std::string texturePath) {
		_texturePath = texturePath;
	}
	~EnemyA();

};

