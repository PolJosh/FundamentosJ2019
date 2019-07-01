#pragma once
#include "IGameScreen.h"
#include "Camera2D.h"
#include "GLS_Program.h"
#include "Window.h"
#include "SpriteBatch.h"
#include "GLTexture.h"
#include "Gamer.h"
#include "EnemyA.h"
#include "Bullet.h"
#include "Background.h"

class PlayScreen: public IGameScreen
{
private:
	Background* background = nullptr;
	GLS_Program _program;
	Gamer* player;
	vector<EnemyA*> enemiesA;
	vector<Bullet*> bullets;
	Camera2D _camera2D;
	Window* _window = nullptr;
	SpriteBatch _spriteBatch;
	SpriteBatch _hudBach;
	Camera2D _hudCamera;
	void drawHUD();
	float timer=0;
public:
	PlayScreen(Window* window);
	virtual void build() override;
	virtual void destroy() override;
	virtual void onExit() override;
	virtual void onEntry() override;
	virtual void initGUI() override;
	virtual void draw() override;
	virtual void update()override;
	virtual void initSystem()override;
	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;
	virtual void checkInput() override;
	void PlayScreen::checkScreenExit();
	void PlayScreen::checkEnemyExit();
	void PlayScreen::checkTimer();
	~PlayScreen();
};

