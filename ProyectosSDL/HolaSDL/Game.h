#pragma once
#include "SDLGame.h"

#include <vector>

#include "SDLGame.h"
#include "GameObject.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Weapon.h"
#include "FirstAid.h"
#include "InsulationTape.h"
#include "GameStateMachine.h"
#include "PlayState.h"

class Game : public SDLGame {

public:
	Game();
	virtual ~Game();

	GameStateMachine stateMachine_;

	// from SDLGame
	void start();
	void stop();

private:
	void initGame();
	void closeGame();
	void handleInput(Uint32 time);
	//void update(Uint32 time);
	//void render(Uint32 time);

	const static int _WINDOW_WIDTH_ = 1280;
	const static int _WINDOW_HEIGHT_ = 720;
	bool exit_;
	std::vector<Entity*> actors_;

};
