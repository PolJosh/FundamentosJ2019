#pragma once
#include "Human.h"
#include "InputManager.h"

class Zombie: public Human
{
private:
	glm::vec2 direction;
public:
	Zombie();
	~Zombie();
	void init(float _speed, glm::vec2 _position);
	void update(const std::vector<std::string>& leveldata,
		std::vector<Human*> & humans,
		std::vector<Zombie*>& zombies);

};

