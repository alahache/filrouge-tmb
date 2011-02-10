
#include "Barre.h"
#include "BreakOut.h"

Barre::Barre(sf::Image* img, BreakOut* pGame)
	: GameSprite(img), game(pGame)
{
	// Type :
	type = "barre";
	
	// Position :
	SetX(game->GetBackground().GetSize().x / 2);
	SetY(530);
}

Barre::~Barre() {
	// Nothing to delete either
}

void Barre::Update() {
	// Update position of Barre
	float x = game->GetInterface().GetX() * game->GetBackground().GetSize().x;
	x -= Width()/2;
	
	SetX(x);
}
