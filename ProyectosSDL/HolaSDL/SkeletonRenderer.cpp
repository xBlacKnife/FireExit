#include "SkeletonRenderer.h"
#include <algorithm>

SkeletonRendered::SkeletonRendered() :
		color_( { COLOR(0xffffffff) }) {
}

SkeletonRendered::SkeletonRendered(SDL_Color color) :
		color_(color) {
}

SkeletonRendered::~SkeletonRendered() {
}

void SkeletonRendered::render(GameObject *o, Uint32 time) {

	SDL_Renderer* renderer = Game::Instance()->getRenderer();

	// the rotation angle of the object wrt to
	double angle = Vector2D(0, -1).angle(o->getDirection());

	// assuming the (0,0) point is the middle of the object, the following are
	// vectors to the corners of its bounding rectangle
	Vector2D lu(-o->getWidth() / 2, -o->getHeight() / 2);
	Vector2D ru(o->getWidth() / 2, -o->getHeight() / 2);
	Vector2D rb(o->getWidth() / 2, o->getHeight() / 2);
	Vector2D lb(-o->getWidth() / 2, o->getHeight() / 2);

	// rotate the corners
	lu.rotate(angle);
	ru.rotate(angle);
	rb.rotate(angle);
	lb.rotate(angle);

	// the center of the object
	double x = o->getPosition().getX() + o->getWidth() / 2;
	double y = o->getPosition().getY() + o->getHeight() / 2;

	// draw lines between the corners, after shifting them by (x,y)
	SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);
	SDL_RenderDrawLine(renderer, int(lu.getX() + x), int(lu.getY() + y), int(ru.getX() + x), int(ru.getY() + y));
	SDL_RenderDrawLine(renderer, int(ru.getX() + x), int(ru.getY() + y), int(rb.getX() + x), int(rb.getY() + y));
	SDL_RenderDrawLine(renderer, int(rb.getX() + x), int(rb.getY() + y), int(lb.getX() + x), int(lb.getY() + y));
	SDL_RenderDrawLine(renderer, int(lb.getX() + x), int(lb.getY() + y), int(lu.getX() + x), int(lu.getY() + y));

	// draw direction vector
	SDL_SetRenderDrawColor(renderer, 255, 100, 100, 100);
	Vector2D dir = (o->getDirection()) * (o->getHeight() / 2);
	SDL_RenderDrawLine(renderer, int(x), int(y), int(dir.getX() + x), int(dir.getY() + y));

	// draw velocity vector
	SDL_SetRenderDrawColor(renderer, 100, 255, 100, 100);

	Vector2D vel = o->getVelocity();
	double wh = std::min(o->getHeight(), o->getWidth()) / 2; // minimum of width an height
	vel = vel * wh / 5; // why 5? i
	SDL_RenderDrawLine(renderer, int(x), int(y), int(vel.getX() + x), int(vel.getY() + y));
}
