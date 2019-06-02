#include "Zombie.h"
#include <random>
#include <ctime>
#include <glm\gtx\rotate_vector.hpp>


Zombie::Zombie()
{
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;
}


Zombie::~Zombie()
{
}

void Zombie::init(float _speed, glm::vec2 _position)
{
	speed = _speed;
	position = _position;

	static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float>randDir(-1.0f, 1.0f);
	direction = glm::vec2(randDir(randomEngine), randDir(randomEngine));
	if (direction.length() == 0) {
		direction = glm::vec2(1.0f, 1.0f);
	}
	direction = glm::vec2(direction);
}

void Zombie::update(const std::vector<std::string>& leveldata,	std::vector<Human*> & humans,	std::vector<Zombie*>& zombies)
{
	static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float>
		randRotate(-40.0f, 40.0f);
	position += direction* speed;
	if (collideWithLevel(leveldata)) {
		direction =
			glm::rotate(direction, randRotate(randomEngine));
	}
}
