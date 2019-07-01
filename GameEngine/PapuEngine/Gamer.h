#pragma once
#include "Agent.h"
#include "InputManager.h"

class Gamer : public Agent
{
private:
	InputManager* inputManager;
	bool shoot;
	int recovery;
public:
	Gamer(float agent_width,
			float agent_height,
		glm::vec2 position,
		std::string texture);
	Gamer(float agent_width,
		float agent_height,
		glm::vec2 position,
		std::string texture,
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
	void changeTexture(std::string texturePath) {
		_texturePath = texturePath;
	}
	std::string getTexture();
	~Gamer();
};

