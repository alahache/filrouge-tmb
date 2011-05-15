
#include <iostream>
#include "Explosion.h"

using namespace std;

//================================================================ PUBLIC

Explosion::Explosion(sf::Image *pImg, float x, float y)
	: AnimatedSprite(pImg, 1, 5, 25, 85, 85)
{
    SetX(x - Width()/2);
    SetY(y - Height()/2);
    Play(0, 24, false);
}

Explosion::~Explosion() {
	// Nothing to delete
}

void Explosion::Update() {
	// Nothing
}

void Explosion::HitBy(GameSprite* pSpr) {
	// Nothing
}

void Explosion::End() {
	
}
