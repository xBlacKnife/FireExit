#pragma once
#include "Component.h"
const int MAX_FADE_ALPHA = 255;

class FadeManager :
	public Component
{
public:
	FadeManager();
	FadeManager(Texture* texture);
	virtual ~FadeManager();
	virtual void render(Entity* e, Uint32 time);
	virtual void handleInput(Entity* e, Uint32 time, const SDL_Event& event);
	Uint8 getAlphaFade() { return alpha_; };

private:
	Texture* fade_ = nullptr;
	Uint8 alpha_;
	Uint8 difAlpha_;
};

