#pragma once
#include "GameState.h"
#include "LevelParser.h"
#include "Inventory.h"

class PlayState: public GameState {

private:
	SDL_Renderer* renderer;
	PlayState();
	static PlayState* s_pInstance;
public:
	Entity* inventory;
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
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual void handleInput(Uint32 time, SDL_Event& event);
};

typedef PlayState PlayState;
