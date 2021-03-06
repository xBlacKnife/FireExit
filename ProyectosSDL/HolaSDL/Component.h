#pragma once

#include "SDLGame.h"
#include "GameObject.h"
#include "checkML.h"


using namespace std;

class Entity;

class Component {

private:
	bool enabled_;
	float deltaTime;
	float lastTime;

protected:
	float getDeltaTime() { return deltaTime; }

public:
	void setEnabled(bool enabled) { enabled_ = enabled; };
	bool isEnabled() { return enabled_; };
	Component();
	virtual ~Component();

	void timing(Uint32 time);
	virtual void update(Entity* e, Uint32 time) {};
	virtual void handleInput(Entity* e, Uint32 time, const SDL_Event& event) {};
	virtual void render(Entity* e, Uint32 time) {};
	virtual void saveToFile(Entity* o) {};
	virtual void loadToFile(Entity* o) {};
};