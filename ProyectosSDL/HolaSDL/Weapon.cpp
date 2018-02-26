#include "Weapon.h"



Weapon::Weapon(ItemType type) : Item(type)
{
	weaponType(type);
}


Weapon::~Weapon()
{
}

void Weapon::weaponType(ItemType type) {
	switch (type)
	{
	case Palo:
		hits = 5;
	case Plancha:
		hits = 10;
	case Tuberia:
		hits = 15;
	case Hacha:
		hits = 20;
		damage = 2;
		
	default:
		break;
	}
}

void Weapon::update() {

}