#include <cmath>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include "Balle.h"
#include "BreakOut.h"
#include "Brique.h"

#define PI 3.14159265

using namespace std;

Balle::Balle(sf::Image *img, BreakOut* pGame)
	: GameSprite(img), game(pGame)
{
    Init();
    srand ( time(NULL) );
}

Balle::~Balle() {
	// Nothing to delete either
}

void Balle::Update() {
	
	// Collisions with window edges :
	if(X() <= game->GetBackground().GetPosition().x || X() >= game->GetBackground().GetSize().x - Width()) {
		direction.x = -direction.x;
		SetX( (X() <= game->GetBackground().GetPosition().x) ? game->GetBackground().GetPosition().x+1 : game->GetBackground().GetSize().x - Width() - 1); //Evite de rester bloqué sur un bord
	}
	if(Y() <= game->GetBackground().GetPosition().y) {
		direction.y = -direction.y;
		SetY(game->GetBackground().GetPosition().y+1); //Evite de rester bloqué sur un bord
	}
    if(Y() >= game->GetBackground().GetSize().y - Height())
        game->Lost();
		
	// Collisions with any Sprite :
	for(unsigned int i=0; i<game->NbSprites(); i++) {
	
		GameSprite* curSpr = game->GetSprite(i);
		if(curSpr == this) continue;
		
		// Collision test :
		if(!Hits(curSpr)) continue;
		
		// Actions depending on Sprite's type :
		if(curSpr->GetType()=="barre") {
		
			direction.y = -abs(direction.y);
			direction.x = direction.x + (X() + Width()/2 - (curSpr->X() + curSpr->Width()/2))/10;
			if(direction.x > 10)
			    direction.x = 10;
			if(direction.x < -10)
			    direction.x = -10;
		}
		
		if(curSpr->GetType() == "brique") {
		    if(!dynamic_cast<Brique*>(curSpr)->IsLiving()) continue;
		    
		    float dx = direction.x;
		    float dy = direction.y;
		    
		    if((X() + Width()/2 < curSpr->X() + curSpr->Width()/2 && dx < 0)
		            || (X() + Width()/2 > curSpr->X() + curSpr->Width()/2 && dx > 0)) {
		        dy = -dy;
		        //cout << "BAAAM" << endl;
		    } else if (abs(abs(X() - (curSpr->X() + curSpr->Width())) -
                         abs(X() + Width() -
                                  curSpr->X())) >
                abs(abs(Y() - curSpr->Y() - curSpr->Height()) -
                         abs(Y() + Height() -
                                  curSpr->Y()))) {
                dx = -dx;
                //cout << "change X" << endl;
            } else {
                dy = -dy;
                //cout << "change Y" << endl;
            }
		    
		    direction.x = dx;
		    direction.y = dy;
		    dynamic_cast<Brique*>(curSpr)->Hit();
		}
	}
	
	// Move the sprite :
	Move(direction);
	
}

void Balle::Init() {
    // Type :
	type = "balle";

	// Position :
	SetX(game->GetBackground().GetSize().x / 2);
	SetY(3*game->GetBackground().GetSize().y / 4);
    
    // Direction :
    int r = rand() % 4;
    direction.x = (rand()%2 ? r+3 : -r-3);
    
    direction.y = -6;
}
