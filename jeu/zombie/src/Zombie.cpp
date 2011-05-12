
#include <iostream>
#include "Zombie.h"

using namespace std;

//================================================================ PUBLIC

Zombie::Zombie(sf::Image *pImg)
	: AnimatedSprite(pImg, 5, 5, 5, 50, 88)
{
}

Zombie::~Zombie() {
	// Nothing to delete
}

void Zombie::Update() {
	// To be redefined if necessary
}

void Zombie::HitBy(GameSprite* pSpr) {
	// To be redefined if necessary
}
