#include "InsulationTape.h"
#include "Weapon.h"

InsulationTape::~InsulationTape()
{
}

void InsulationTape::use(Entity* e) {
	if (e->getComponent<Weapon>() != nullptr) {
		e->getComponent<Weapon>()->repair();
	}
}