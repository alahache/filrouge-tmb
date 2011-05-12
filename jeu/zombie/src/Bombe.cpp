
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
	return (Bombe.GetSize().y);
}


void Bombe::Init() {
    // Type :
	type = "bombe";

	// Position :
	// TODO :
	SetX();
	SetY();
    
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
	criticDist = Bombe.GetSizeBombe()/2-sizeCircleMove/2-5;
}

void updateLimit() {
	angle = atan((GetY()-yEye) / (GetX()-xEye));
	if((GetX()-xEye) * (GetX()-superxEye)
			+ (GetY()-yEye) * (GetY()-yEye)
			>= criticDist * criticDist) {
		direction.x = xEye + criticDist*cos(angle);
		direction.y = yEye + criticDist*sin(angle);
	} else {
		direction.x = GetX();
		direction.y = GetY();
	}
}

void Bombe::calculateDirection() {
	// Simulate the translation :
	direction.x += 1;
	// Simulate the fall :
	direction.y = - speed + 0.5;
}

