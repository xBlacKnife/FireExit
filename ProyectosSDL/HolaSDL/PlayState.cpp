#include "PlayState.h"
#include "Game.h"
#include "PlayerLight.h"
#include "LightManager.h"
#include "Light.h"
#include "SRMap.h"
#include "MessageRenderer.h"
#include "MessageTimer.h"

unique_ptr<PlayState> PlayState::s_pInstance = nullptr;

PlayState::PlayState(): GameState(){ //Constructora de nueva partida
	
}


PlayState::~PlayState() {
	
}

void PlayState::startState()
{
	LevelParser levelParser;
	string fileMap = FOLDER + string("levels/Mapa.tmx");
	pLevel = levelParser.parseLevel(fileMap.c_str());

	for (Entity* e : stage_)
		cout << e->getName() << endl;

	mapWidth = levelParser.mapWidth;
	mapHeight = levelParser.mapHeight;

	player = Game::Instance()->getEntityWithComponent<Player>();
	Camera::Instance()->setTarget(player);

	for (Entity* e : stage_)
	{
		if (e->getComponent<Enemy>() != nullptr)
			e->getComponent<Enemy>()->addPlayer(player);
	}

	//PROBAR LOS MOVIBLES:
		//Descomentar estas dos lineas, la linea 76 del EntityCreator.h y comentar la 77 del EntityCreator.h
	//Movable* movableComp = Game::Instance()->getEntityWithComponent<Movable>()->getComponent<Movable>();
	//movableComp->addPlayer(player);

	//M�sica
	//Game::Instance()->getResourceManager()->getMusic("SafeRoom")->play();

	//CURSORº
	cursor_ = new Entity();
	cursor_->setHeight(50);
	cursor_->setWidth(50);
	cursor_->addComponent(new StaticImageRender(Game::Instance()->getResourceManager()->getTexture("Cursor")));
	cursor_->addComponent(new MouseInputComponent());
	cursor_->setActive(false);

	//Item
	/*Entity* palo = new Entity(10, 20);
	palo->addComponent(new Weapon(ItemType::STICK, "Stick"));
	stage_.push_back(palo);
	palo->getComponent<Weapon>()->attack();
	palo->getComponent<Weapon>()->attack();
	palo->getComponent<Weapon>()->attack();
	palo->getComponent<Weapon>()->attack();

	Entity* palo2 = new Entity(10, 20);
	palo2->addComponent(new Weapon(ItemType::CROWBAR, "Crowbar"));
	stage_.push_back(palo2);

	Entity* insulationTape = new Entity(15, 25);
	insulationTape->addComponent(new InsulationTape("InsulationTape"));
	stage_.push_back(insulationTape);
	insulationTape->getComponent<InsulationTape>()->use(palo);*/

	//Iluminacion -------------------------------------------------------------
	//Entity* playerLight = new Entity(0, 0);
	//playerLight->addComponent(new PlayerLight());
	//stage_.push_back(playerLight);

	Entity* lightManagerEntity = new Entity(0, 0);
	LightManager* lightManager = new LightManager();
	lightManagerEntity->addComponent(lightManager);
	lightManagerEntity->setHeight(Game::Instance()->getWindowHeight());
	lightManagerEntity->setWidth(Game::Instance()->getWindowWidth());
	stage_.push_back(lightManagerEntity);

	lightManager->addLight(new Light(Game::Instance()->getResourceManager()->getTexture("PointLight"), 4200, 5500));
	lightManager->addLight(new Light(Game::Instance()->getResourceManager()->getTexture("PointLight"), 4800, 5500));

	//MessageRenderer----------------------------------------------------------
	messageRenderer = new Entity(0, 0);
	messageRenderer->addComponent(new MessageRenderer());
	messageRenderer->addComponent(new MessageTimer());
	stage_.push_back(messageRenderer);

	craft = new Entity(0, 0);
	Craft* craftComp = new Craft();
	craft->addComponent(craftComp);
	craft->setActive(false);
	stage_.push_back(craft);

	chest = new Entity(0, 0);
	Chest* chestComp = new Chest();
	chest->addComponent(chestComp);
	chest->setActive(false);
	stage_.push_back(chest);

	inventory = new Entity(0, 0);
	Inventory* invtComp = new Inventory();
	inventory->addComponent(invtComp);
	inventory->setActive(false);
	stage_.push_back(inventory);

	/*invtComp->addItem(insulationTape);
	invtComp->addItem(palo2);
	invtComp->addItem(palo);*/

	//Registro (nota de texto) de prueba ---------------------------------------------
	/*Entity* textTest = new Entity(20, 20);
	textTest->addComponent(new TextNote(Game::Instance(), "textNotes/Archivo1.txt", 410, 110, Game::Instance()->getResourceManager()->getTexture("BgRegistro")));
	stage_.push_back(textTest);*/
}

void PlayState::update(Uint32 time)
{
	pLevel->update(time);
	GameState::update(time);
	pLevel->update(time);
}

void PlayState::render(Uint32 time)
{
	SDL_RenderClear(Game::Instance()->getRenderer());
	pLevel->render();
	GameState::render(time);
	SDL_RenderPresent(Game::Instance()->getRenderer());
}

void PlayState::handleInput(Uint32 time, SDL_Event & event)
{
	pLevel->handleInput(time, event);
	GameState::handleInput(time, event);
}

void PlayState::saveToFile()
{
	if (saveGame)
	{
		GameState::saveToFile();
		saveGame = false;
	}

}

void PlayState::loadToFile()
{
	if (loadGame)
	{
		GameState::loadToFile();
		loadGame = false;
	}
}
