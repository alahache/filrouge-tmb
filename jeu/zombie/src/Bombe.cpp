#include <iostream>

#include "ZombieGame.h"
#include "Bombe.h"

using namespace std;

Bombe::Bombe(sf::Image *img, ZombieGame* pGame, Catapulte* _catapulte)
	: GameSprite(img), game(pGame), catapulte(_catapulte)
{
    Init();
}

Bombe::~Bombe() {
	// Nothing to delete either
}

void Bombe::eye()
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


void Bombe::Init() {
    // Type :
	type = "bombe";
	attached = true;

	// Position :
	direction.x = 350;
	direction.y = 350;

	SetX(POSX);
	SetY(POSY);

    
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


void Bombe::Update() {
	if(game->GetInterface().isMousePressed())
	{
		sf::Vector2f pos = game->GetMousePosition();
		sf::FloatRect r1 = GetHitBox();
			r1.Left		+= X();
			r1.Right	+= X();
			r1.Top		+= Y();
			r1.Bottom	+= Y();
		if(r1.Contains(pos.x, pos.y))
		{
			drag = true;
		}
		
		if(drag == true)
		{
			// TODO : limites cercle
			eye();
			
			SetX(pos.x - Width()/2);
			SetY(pos.y - Height()/2);
			catapulte -> DrawLines(pos.x, pos.y);
		}
	}
	else if(drag == true)
	{
		drag = false;
		// TODO calculer direction
		calculateDirection();
	}
	else
	{
		// Move the sprite :
		// TODO maj direction
		calculateDirection();
		Move(direction);
	}
	
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
	criticDist = Width()/2-sizeCircleMove/2-5;
}

void Bombe::calculateDirection() {
	if(!attached)
	{
		// Simulate the translation :
		direction.x += 1;
		// Simulate the fall :
		direction.y = - speed + 0.5;
	}
}

