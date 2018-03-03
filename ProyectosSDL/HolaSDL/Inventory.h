#pragma once
#include "ItemContainer.h"
#include <vector>
#include "Weapon.h"


using namespace std;

class Inventory : public ItemContainer
{
public:
	Weapon * equiped;

	Inventory(int tam, Texture* tex);
	~Inventory();

protected:
	bool debug;
	
public:

	virtual void update(Entity* e, Uint32 time);
	virtual void handleInput(Entity* e, Uint32 time, const SDL_Event& event);
	virtual void render(Entity* e, Uint32 time);

	void addItem(Item * item);

	//DEBUG METHODS
	void Debug_Mode_On() { debug = true; };
	void Debug_Mode_Off() { debug = false; };

	virtual bool checkItem(Item* item);
	virtual Item* ItemInPosition(int pos);
	void equipWeapon(int pos);
	
	Weapon* currentWeapon();

	

};


