#include <cmath>

#include "Balle.h"
#include "BreakOut.h"

#define PI 3.14159265

Balle::Balle(sf::Image *img, BreakOut* pGame)
	: GameSprite(img), game(pGame)
{
	SetX(game->GetBackground().GetSize().x / 2);
	SetY(game->GetBackground().GetSize().y / 2);
    
    // Direction :
    angle = -45;
    speed = 10;
    calculateDirection();
}

Balle::~Balle() {
	// Nothing to delete either
}

void Balle::Update() {
	
	// Collisions with window edges :
	if(X() <= game->GetBackground().GetPosition().x || X() >= game->GetBackground().GetSize().x)
		direction.x = -direction.x;
	if(Y() <= game->GetBackground().GetPosition().y || Y() >= game->GetBackground().GetSize().y)
		direction.y = -direction.y;
		
	// Collisions with any Sprite :
	for(int i=0; i<game->NbSprites(); i++) {
	
		GameSprite* currentSpr = game->GetSprite(i);
		if(currentSpr == this) continue;
		
		// Collision test :
		if(!Hits(currentSpr)) continue;
		
		// Actions depending on Sprite's type :
		if(currentSpr == &(game->GetBarre())) {
		
			// direction control : (between 30 and 160 degrees)
			angle = (120.0/currentSpr->Width()) * ((currentSpr->X() + currentSpr->Width()) - (X() + (Width() / 2))) + 30.0;
			
			calculateDirection();
		}
	}
	
	// Move the sprite :
	Move(direction);
	
}

void Balle::SetSpeed(float unSpeed) {
	speed = unSpeed;
	calculateDirection();
}

void Balle::SetAngle(float unAngle) {
	angle = unAngle;
	calculateDirection();
}

void Balle::calculateDirection() {
	float angleRadian = angle*PI/180.0;
	direction.x = speed * cos(angleRadian);
	direction.y = - speed * sin(angleRadian);
}
