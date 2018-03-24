#pragma once
#include "Component.h"
#include "Game.h"
#include "Entity.h"
#include "Collisions.h"
#include <iostream>

class KeyBoardInputComponent :
	public Component
{
public:
	KeyBoardInputComponent();		
	KeyBoardInputComponent(SDL_Scancode left, SDL_Scancode right, SDL_Scancode up, SDL_Scancode down, SDL_Scancode interact, SDL_Scancode attack, 
		SDL_Scancode inventory, SDL_Scancode chest, SDL_Scancode pause, SDL_Scancode enter);
	virtual ~KeyBoardInputComponent();
	virtual void handleInput(Entity* o, Uint32 time, const SDL_Event& event);

private:
	SDL_Scancode left_;
	SDL_Scancode right_;
	SDL_Scancode up_;
	SDL_Scancode down_;
	SDL_Scancode interact_;
	SDL_Scancode attack_;
	SDL_Keycode inventory_;
	SDL_Keycode chest_;
	SDL_Scancode pause_;
	SDL_Scancode enter_;

	//VARIABLE PARA EVITAR EL PARPADEO DEL INVENTARIO Y PARA CUADRAR QUE SE ABRAN LAS 
	//INTERFACES CORRECTAS SIN QUE SE ABRAN Y CIERREN DE FORMAS DESIGUALES
	bool inventoryPressed = false, chestPressed = false, invOpen = false, cstOpen = false;
	Entity* inv = nullptr;
	Entity* cst = nullptr;
	bool chestOpen() { return cstOpen; };
	bool InventoryOpen() { return invOpen; };
};

