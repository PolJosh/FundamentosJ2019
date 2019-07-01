#pragma once
#include "Agent.h"
#include "InputManager.h"

class EnemyA : public Agent
{
private:
	InputManager* inputManager;
	float bulletTimer;
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
	float getTimer() {
		return bulletTimer;
	}
	void setTimer();
	std::string getTexture();
	void changeTexture(std::string texturePath) {
		_texturePath = texturePath;
	}
	~EnemyA();

};

