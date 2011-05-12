#include <cmath>
#include <iostream>
#include <cassert>
#include <cstdlib>

#include "Balle.h"
#include "BreakOut.h"
#include "Brique.h"

#define PI 3.14159265

Balle::Balle(sf::Image *img, BreakOut* pGame)
	: GameSprite(img), game(pGame)
{
    Init();
}

Balle::~Balle() {
	// Nothing to delete either
}

void Balle::Update() {
	
	// Collisions with window edges :
	if(X() <= game->GetBackground().GetPosition().x || X() >= game->GetBackground().GetSize().x - Width()) {
		direction.x = -direction.x;
		//std::cout << "Change posx " << direction.x << std::endl;
		SetX( (X() <= game->GetBackground().GetPosition().x) ? game->GetBackground().GetPosition().x+1 : game->GetBackground().GetSize().x - Width() - 1); //Evite de rester bloqué sur un bord
	}
	if(Y() <= game->GetBackground().GetPosition().y) {
		direction.y = -direction.y;
		SetY(game->GetBackground().GetPosition().y+1); //Evite de rester bloqué sur un bord
		//std::cout << "Change posy" << direction.y << std::endl;
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
		
			// direction control : (between 30 and 160 degrees)
			angle = (120.0/curSpr->Width()) * ((curSpr->X() + curSpr->Width()) - (X() + (Width() / 2))) + 30.0;
			
			calculateDirection();
		}
		
		if(curSpr->GetType() == "brique") {
		    if(!dynamic_cast<Brique*>(curSpr)->IsLiving()) continue;
		    
		    double dx = cos(angle*PI/180);
		    double dy = sin(angle*PI/180);
		    //double olddx = dx;
		    //double olddy = dy;
            if (X() + dx < curSpr->X()+ curSpr->Width() &&
                    X() + Width() + dx > curSpr->X() &&
                    Y() + dy < curSpr->Y() + curSpr->Height() &&
                    Y() + Height() + dy > curSpr->Y()) { //Si collision
                
                if (abs(abs(X() - (curSpr->X() + curSpr->Width())) -
                             abs(X() + Width() -
                                      curSpr->X())) >
                    abs(abs(Y() - curSpr->Y() - curSpr->Height()) -
                             abs(Y() + Height() -
                                      curSpr->Y()))) {
                    dx = -dx;
                    std::cout << "change X" << std::endl;
                } else {
                    dy = -dy;
                    std::cout << "change Y" << std::endl;
                }
                
            }
		    
		    std::cout << atan(dy/dx) << std::endl;
		    SetAngle(atan(dy/dx)*180/PI + (dx<0 ? 180 : 0));
		    //system("sleep 1");
		    //assert(dx != olddx && dy != olddy);
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
	SetY(game->GetBackground().GetSize().y / 2);
    
    // Direction :
    angle = -45;
    speed = 10;
    calculateDirection();
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
