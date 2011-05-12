#include "ZombieGame.h"
#include "Bombe.h"

Bombe::Bombe(sf::Image *img, ZombieGame* pGame)
	: GameSprite(img), game(pGame)
{
    Init();
}

Bombe::~Bombe() {
	// Nothing to delete either
}

void Bombe::Update() {
	
	// Define the movement posibilities :
	
	
	// Move the sprite :
	Move(direction);
	
}

sf::Vector2f Bombe::GetPosBombe()
{
	return direction;
}

float Bombe::GetSizeBombe()
{
	return (Width());
}


void Bombe::Init() {
    // Type :
	type = "bombe";

	// Position :
	direction.x = 0;
	direction.y = 0;
    
    // Direction :
    speed = 10;
    //angle = -45;
    calculateDirection();
}

void Bombe::SetSpeed(float unSpeed) {
	speed = unSpeed;
}

void Bombe::SetAngle(float unAngle) {
	angle = unAngle;
}


void Bombe::limitMovement(int x, int y, float taille) {
	xEye = x;
	yEye = y;
	sizeCircleMove = taille;
	angle = 0;
	criticDist = GetSizeBombe()/2-sizeCircleMove/2-5;
}

void Bombe::updateLimit() {
	angle = atan((game->GetInterface().GetY()-yEye) / (game->GetInterface().GetX()-xEye));
	if((game->GetInterface().GetX()-xEye) * (game->GetInterface().GetX()-xEye)
			+ (game->GetInterface().GetY()-yEye) * (game->GetInterface().GetY()-yEye)
			>= criticDist * criticDist) {
		direction.x = xEye + criticDist*cos(angle);
		direction.y = yEye + criticDist*sin(angle);
	} else {
		direction.x = game->GetInterface().GetX();
		direction.y = game->GetInterface().GetY();
	}
}

void Bombe::calculateDirection() {
	// Simulate the translation :
	direction.x += 1;
	// Simulate the fall :
	direction.y = - speed + 0.5;
}

