
#include <iostream>
#include "Explosion.h"

using namespace std;

//================================================================ PUBLIC

Explosion::Explosion(sf::Image *pImg, Game* _game)
	: AnimatedSprite(pImg, 1, 5, 25, 85, 85), game(_game)
{
}

Explosion::~Explosion() {
	// Nothing to delete
}

void Explosion::Place(float x, float y)
{
	SetX(x - Width()/2);
    SetY(y - Height()/2);
}

void Explosion::Update() {
	// Nothing
}

void Explosion::HitBy(GameSprite* pSpr) {
	// Nothing
}

void Explosion::End() {
	game->RemoveSprite(this);
}
