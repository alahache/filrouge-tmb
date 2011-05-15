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
		else if(Y() < 0)
		{
			// TODO Afficher position en haut
		}
		else if(X() < 1440 && imgterrain->GetPixel(X()+Width()/2, Y()+Height()-3).a > 40)
		{
			cout << X()+Width()/2 << "," << Y()+Height()-3 << endl;
			lancee = false;
			game->GetCamera().Stop();
			SetPosition(posOrigin);
			// TODO Boooom
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
				// Limites cercle
				angle = atan((pos.y-POSY) / (pos.x-POSX));
				if((pos.x-POSX) * (pos.x-POSX) + (pos.y-POSY) * (pos.y-POSY) >= LIMIT * LIMIT) {
					if( (pos.x-POSX) > 0 ) {
						SetX(POSX - Width()/2 + LIMIT*cos(angle));
						SetY(POSY - Height()/2 + LIMIT*sin(angle));
					} else {
						SetX(POSX - Width()/2 - LIMIT*cos(angle));
						SetY(POSY - Height()/2 - LIMIT*sin(angle));
					}
				} else {
					SetX(pos.x - Width()/2);
					SetY(pos.y - Height()/2);
				}
				catapulte -> DrawLines(X(), Y());
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

void Bombe::calculateDirection() {
	// Simulate the translation :
	direction.x += 1;
	// Simulate the fall :
	direction.y = - speed + 0.5;
}

