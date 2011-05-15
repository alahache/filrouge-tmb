#include <iostream>

#include "ZombieGame.h"
#include "Bombe.h"

using namespace std;

Bombe::Bombe(sf::Image *img, ZombieGame* pGame, Catapulte* _catapulte, sf::Image* _imgterrain)
	: GameSprite(img), game(pGame), catapulte(_catapulte), imgterrain(_imgterrain)
{
    // Type :
	type = "bombe";

	// Position :
	posOrigin.x = POSX;
	posOrigin.y = POSY;
	SetPosition(posOrigin);
    
    // Direction :
    speed = 10;
    //angle = -45;
}

Bombe::~Bombe() {
	// Nothing to delete either
}

void Bombe::Update() {
	if(lancee)
	{
		direction.y += 1;
		Move(direction);
		if(X() < 0 || X() > imgterrain->GetWidth() || Y() > imgterrain->GetHeight())
		{
			lancee = false;
			game->GetCamera().Stop();
			SetPosition(posOrigin);
		}
	}
	else
	{
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
			
				SetX(pos.x - Width()/2);
				SetY(pos.y - Height()/2);
				catapulte -> DrawLines(pos.x, pos.y);
			}
		}
		else if(drag == true)
		{
			drag = false;
			lancee = true;
			direction = -(GetPosition() - posOrigin);
			direction.x = direction.x / 5;
			direction.y = direction.y / 5;
			game->GetCamera().Follow(this);
		}
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

