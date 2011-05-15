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

void Bombe::Update()
{
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
	bind = true;

	// Position :
	direction.x = 350;
	direction.y = 350;
    
    // Direction :
    speed = 10;
    //angle = -45;
    limitMovement(5,5,60);
    calculateDirection();
}


void Bombe::SetPosition(float x, float y)
{
	direction.x = x;
	direction.y = y;
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

void Bombe::calculateDirection() {
	if(!bind)
	{
		// Simulate the translation :
		direction.x += 1;
		// Simulate the fall :
		direction.y = - speed + 0.5;
	}
}

