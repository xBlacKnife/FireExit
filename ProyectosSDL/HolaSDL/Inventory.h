#pragma once
#include "ItemContainer.h"
#include <vector>
#include "Weapon.h"
#include "Chest.h"
#include <list>
#include "Key.h"

using namespace std;


class Inventory : public ItemContainer
{
public:
	Entity * equiped;
	Chest* cofre = nullptr;
	coord EquippedCoord = { 750, 343 };
	void setChestMode(bool a) { chestMode = a; }


	Inventory();
	~Inventory();

protected:
	bool debug;

public:

	virtual void update(Entity* e, Uint32 time);
	virtual void handleInput(Entity* e, Uint32 time, const SDL_Event& event);
	virtual void render(Entity* e, Uint32 time);

	void addItem(Entity * item);

	//DEBUG METHODS
	void Debug_Mode_On() { debug = true; };
	void Debug_Mode_Off() { debug = false; };

	virtual bool checkItem(Entity* item);
	virtual Entity* ItemInPosition(int pos);
	void equipWeapon(int pos);
	virtual bool fullInventory();
	void renderItem(int i, Entity* e, SDL_Rect DestRect);

	Entity* currentWeapon();

	bool chestMode = false;

	vector<Entity*> getKeys() { return keys; };
	
private:
	vector<Entity*> keys;
};



