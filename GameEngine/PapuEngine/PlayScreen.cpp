#include "PlayScreen.h"
#include "Game.h"
#include "MyScreens.h"
#include "EnemyA.h"
#include "Bullet.h"
#include <random>


PlayScreen::PlayScreen(Window* window):_window(window)
{
}


PlayScreen::~PlayScreen()
{
}

void PlayScreen::initGUI() {
	_hudBach.init();
	_hudCamera.init(_window->getScreenWidth(),
		_window->getScreenHeight());
	_hudCamera.setPosition(glm::vec2(
		_window->getScreenWidth() / 2.0f,
		_window->getScreenHeight() / 2.0f));
	background = new Background("Textures/game.png");
}

void PlayScreen::initSystem() {
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}

void PlayScreen::destroy() {
	delete background;
	enemiesA.clear();
}

void PlayScreen::onExit() {}

void PlayScreen::onEntry() {
	initSystem();
	_camera2D.init(_window->getScreenWidth(),
		_window->getScreenHeight());
	_camera2D.setPosition(glm::vec2(
		_window->getScreenWidth() / 2.0f,
		_window->getScreenHeight() / 2.0f));
	_spriteBatch.init();

	player = new Gamer(50, 40,
		glm::vec2(200, 200), "Textures/Player.png", 
		&_game->_inputManager);

	initGUI();
	
}

void PlayScreen::checkScreenExit() {
	
	if (player->getPosition().x + player->getWidth() < 0) {
		glm::vec2 newPos;
		newPos.x = _window->getScreenWidth() - 1;
		newPos.y = player->getPosition().y;
		player->setPosition(newPos);
	}
	if (player->getPosition().x >= _window->getScreenWidth()) {
		glm::vec2 newPos;
		newPos.x = 1 - player->getWidth();
		newPos.y = player->getPosition().y;
		player->setPosition(newPos);
	}
}

void PlayScreen::checkEnemyExit() {
	for (int i = 0; i < enemiesA.size(); i++) {
		if (enemiesA[i]->getPosition().y + enemiesA[i]->getHeight() < 0) {
			enemiesA.erase(enemiesA.begin() + i);
		}
	}
}

void PlayScreen::checkTimer() {
	timer += 0.01;
	int r = 1 + (rand() % static_cast<int>(_window->getScreenWidth() - 60 + 1));
	if (timer >= 2) {
		enemiesA.push_back(new EnemyA(60,40,
			glm::vec2(r, 400),
			&_game->_inputManager));
		timer = 0;
	}
}

void PlayScreen::update(){
	_camera2D.update();
	player->update();

	if (player->getShoot()) {
		glm::vec2 bulPos = player->getPosition();
		bulPos.x += player->getWidth() / 2;
		bulPos.y += player->getHeight();
		bullets.push_back(new Bullet(10, 10,bulPos,
			&_game->_inputManager,1,2.0f,0));
	}

	for (size_t i = 0; i < enemiesA.size(); i++)
	{
		enemiesA[i]->update();
	}
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i]->update();
	}
	checkTimer();
	checkEnemyExit();
	checkScreenExit();
	checkInput();
}

void PlayScreen::checkInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		_game->onSDLEvent(event);
	}
}

void PlayScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();
	glActiveTexture(GL_TEXTURE0);
	GLuint pLocation = _program.getUniformLocation("P");
	glm::mat4 cameraMatrix = _camera2D.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	_spriteBatch.begin();
	background->draw(_spriteBatch);
	for (size_t i = 0; i < enemiesA.size(); i++)
	{
		enemiesA[i]->draw(_spriteBatch);
	}
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i]->draw(_spriteBatch);
	}
	player->draw(_spriteBatch);
	_spriteBatch.end();
	_spriteBatch.renderBatch();
	drawHUD();
	glBindTexture(GL_TEXTURE_2D, 0);
	_program.unuse();
}

void PlayScreen::drawHUD() {
	GLuint pLocation = _program.getUniformLocation("P");
	glm::mat4 cameraMatrix = _camera2D.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	char buffer[256];
	_hudBach.begin();

	_hudBach.end();
	_hudBach.renderBatch();
}

void PlayScreen::build() {}

int PlayScreen::getPreviousScreen() const {
	return SCREEN_INDEX_MENU;
}

int PlayScreen::getNextScreen() const {
	return SCREEN_INDEX_OVER;
}
