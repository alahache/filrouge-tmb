#include <iostream>

#include "ZombieGame.h"
#include "Bombe.h"

#define sqr(x) (x)*(x)

using namespace std;

Bombe::Bombe(sf::Image *img, ZombieGame* pGame, Catapulte* _catapulte, sf::Image* _imgterrain, Explosion* _sprexplosion)
	: GameSprite(img), game(pGame), catapulte(_catapulte), imgterrain(_imgterrain), sprexplosion(_sprexplosion)
{
    // Type :
	type = "bombe";

	// Position :
	posOrigin.x = POSX;
	posOrigin.y = POSY;
	SetPosition(posOrigin);
	
	// HitBox :
    hitBox.Left 	= 10;
    hitBox.Top 		= 10;
    hitBox.Right 	= 40;
    hitBox.Bottom 	= 40;
	
	lancee = false;
	drag = false;
}

Bombe::~Bombe() {
}

void Bombe::Update() {
	if(lancee)
	{
		// La bombe est lancée :
		direction.y += 1;
		Move(direction);
		
		bool explode = false;
		
		// Collisions avec le terrain :
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
			explode = true;
		}
		else
		{
			// Collision avec les zombies :
			for(int i=0; i<game->NbSprites(); i++)
			{
				GameSprite* gs = game->GetSprite(i);
				if(gs->GetType()!="zombie") continue;
				if(Hits(gs))
				{
					explode = true;
					break;
				}
			}
		}
		
		if(explode)
		{
			// Collision avec les zombies :
			for(int i=0; i<game->NbSprites(); i++)
			{
				GameSprite* gs = game->GetSprite(i);
				if(gs->GetType()!="zombie") continue;
				float zx = gs->X() + gs->Width()/2;
				float zy = gs->Y() + gs->Height()/2;
				if((sqr(zx-X()) + sqr(zy-Y())) <= sqr(EXPLOSIONLIMIT))
				{
					gs->HitBy(this);
					cout << "boom" << endl;
				}
			}
			
			explosion();
			explode = true;
			lancee = false;
			game->GetCamera().Stop();
			SetPosition(posOrigin);
		}
	}
	else
	{
		// La bombe est attachée à la catapulte :
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
				catapulte->DrawLines(X() + Width()/2, Y() + Height()/2);
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

void Bombe::explosion()
{
	sprexplosion->Place(X() + Width()/2, Y() + Width()/2);
	game->AddSprite(sprexplosion);
	sprexplosion->Play(0, 24, false);
}

