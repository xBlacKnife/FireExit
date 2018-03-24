#pragma once
#include "GameObject.h"
#include "Entity.h"
#include <list>
#include <memory>

using namespace std;

class Game;

class GameState {

protected:
	list<Entity*> stage_;
	list<Entity*> interactibles_;
	list<Entity*> characters_;
	list<Entity*> doors_;

	GameState();
	static unique_ptr<GameState> s_pInstance;

public:

	static GameState* Instance()
	{
		if (s_pInstance.get() == nullptr)
			s_pInstance.reset(new GameState());
		return s_pInstance.get();
	}

	virtual ~GameState();
	virtual void startState();
	virtual void render(Uint32 time);
	virtual void update(Uint32 time);
	virtual void handleInput(Uint32 time, SDL_Event& event);

	void pushEntities(Entity* e) { stage_.push_back(e); };
	list<Entity*>* getStage() { return &stage_; };
	list<Entity*>* getInteractibles() { return &interactibles_; };
	list<Entity*>* getCharacters() { return &characters_; };
	list<Entity*>* getDoors() { return &doors_; };
};


typedef GameState GameState;

