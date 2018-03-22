#pragma once
#include "GameState.h"
#include "LevelParser.h"
#include "Inventory.h"
#include "Chest.h"

class PlayState: public GameState {

private:
	SDL_Renderer* renderer;
	PlayState();
	static PlayState* s_pInstance;
	Level* pLevel = nullptr;

	Entity* player;

	int mapWidth;
	int mapHeight;

public:
	Entity* inventory;
	Entity* chest;
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	//PlayState();
	~PlayState();
	virtual void startState();
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual void handleInput(Uint32 time, SDL_Event& event);

	//Devuelve al jugador
	Entity* getPlayer() { return player; };
	int getMapWidth() { return mapWidth; };
	int getMapHeight() { return mapHeight; };
};

typedef PlayState PlayState;
