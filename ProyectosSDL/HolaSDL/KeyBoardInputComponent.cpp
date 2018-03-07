#include "KeyBoardInputComponent.h"
#include "ImageRenderer.h"


KeyBoardInputComponent::KeyBoardInputComponent()
{
}

KeyBoardInputComponent::KeyBoardInputComponent(SDL_Scancode left, SDL_Scancode right, SDL_Scancode up, SDL_Scancode down, SDL_Scancode interact, SDL_Scancode attack, SDL_Scancode inventory, SDL_Scancode pause, SDL_Scancode enter) :
	left_(left), right_(right), up_(up), down_(down), interact_(interact), attack_(attack), inventory_(inventory), pause_(pause), enter_(enter) {
}

KeyBoardInputComponent::~KeyBoardInputComponent()
{
}

void KeyBoardInputComponent::handleInput(Entity* o, Uint32 time, const SDL_Event& event) {

	Vector2D velocity = o->getVelocity();
	Vector2D direction = o->getDirection();
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[left_]) {
		velocity.setX(-10);
		direction.setX(-1);
	}
	else if (state[right_]) {
		velocity.setX(10);
		direction.setX(1);
	}
	else {
		velocity.setX(0);
		direction.setX(0);
	}
	if (state[up_]) {
		velocity.setY(-10);
		direction.setY(1);
	}
	else if (state[down_]) {
		velocity.setY(10);
		direction.setY(-1);
	}
	else if (state[interact_]) {
		if (event.type == SDL_KEYDOWN) {
			SDL_Rect playerRect = { o->getPosition().getX(), o->getPosition().getX(), o->getWidth(), o->getHeight() };
			for (Entity* e : *Game::Instance()->stateMachine_.currentState()->getInteractibles()) {
				SDL_Rect intRect = { e->getPosition().getX(), e->getPosition().getX(), e->getWidth(), e->getHeight() };
				if (Collisions::RectRect(&playerRect, &intRect)) {
					if (e->getComponent<Interactible>() != nullptr) {
						e->getComponent<Interactible>()->interact(e, dynamic_cast<PlayState*>(Game::Instance()->stateMachine_.currentState())->inventory->getComponent<Inventory>());
						e->delComponent(e->getComponent<ImageRenderer>());
					}
					else std::cout << "Esta entidad no tiene el componegnte Interactible." << std::endl; // DEBUG
				}
			}
		}
	}
	/*else if (state[interact_]) {
		SDL_Rect playerRect = { o->getPosition().getX(), o->getPosition().getX(), o->getWidth(), o->getHeight() };
		for (Entity* e : *Game::Instance()->stateMachine_.currentState()->getInteractibles()) {
			SDL_Rect intRect = { e->getPosition().getX(), e->getPosition().getX(), e->getWidth(), e->getHeight() };
			if (Collisions::RectRect(&playerRect, &intRect)) {
				if (e->getComponent<Interactible>() != nullptr) {
					e->getComponent<Interactible>()->interact();				}			}		}	}*/
	else {
		velocity.setY(0);
		direction.setY(0);
	}

	o->setVelocity(velocity);
	o->setDirection(direction);

}
