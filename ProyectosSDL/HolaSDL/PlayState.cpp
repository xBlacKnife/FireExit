#include "PlayState.h"
#include "Game.h"

PlayState* PlayState::s_pInstance = 0;

PlayState::PlayState(): GameState(){ //Constructora de nueva partida
	

	inventory = new Entity(0, 0);
	Inventory* invtComp = new Inventory();
	inventory->addComponent(invtComp);
	stage_.push_back(inventory);
			
	//Item
	Entity* palo = new Entity(10, 20);
	palo->addComponent(new Weapon(ItemType::Stick,"Stick"));
	stage_.push_back(palo);
	palo->getComponent<Weapon>()->attack();
	palo->getComponent<Weapon>()->attack();
	palo->getComponent<Weapon>()->attack();
	palo->getComponent<Weapon>()->attack();

	Entity* palo2 = new Entity(10, 20);
	palo2->addComponent(new Weapon(ItemType::Lever,"Lever"));
	stage_.push_back(palo2);

	Entity* insulationTape = new Entity(15, 25);
	insulationTape->addComponent(new InsulationTape("InsulationTape"));
	stage_.push_back(insulationTape);
	insulationTape->getComponent<InsulationTape>()->use(palo);

	invtComp->addItem(insulationTape);
	invtComp->addItem(palo2);
	invtComp->addItem(palo);

}


PlayState::~PlayState() {
	
}

void PlayState::update(Uint32 time)
{
	GameState::update(time);
	Game::Instance()->getLevel()->update(time);
}

void PlayState::render(Uint32 time)
{
	//SDL_SetRenderDrawColor(game_->getRenderer(), COLOR(0x2222222FF)); //Color de fondo
	SDL_RenderClear(Game::Instance()->getRenderer());
	Game::Instance()->getLevel()->render(time);
	GameState::render(time);
	SDL_RenderPresent(Game::Instance()->getRenderer());

	
}

void PlayState::handleInput(Uint32 time, SDL_Event & event)
{
	Game::Instance()->getLevel()->handleInput(time, event);
	GameState::handleInput(time, event);
}
