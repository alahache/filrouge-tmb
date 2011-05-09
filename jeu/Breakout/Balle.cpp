#include <cmath>
#include <iostream>
#include <cassert>

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
	for(int i=0; i<game->NbSprites(); i++) {
	
		GameSprite* currentSpr = game->GetSprite(i);
		if(currentSpr == this) continue;
		
		// Collision test :
		if(!Hits(currentSpr)) continue;
		
		// Actions depending on Sprite's type :
		if(currentSpr->GetType()=="barre") {
		
			// direction control : (between 30 and 160 degrees)
			angle = (120.0/currentSpr->Width()) * ((currentSpr->X() + currentSpr->Width()) - (X() + (Width() / 2))) + 30.0;
			
			calculateDirection();
		}
		
		if(currentSpr->GetType() == "brique") {
		    if(!dynamic_cast<Brique*>(currentSpr)->IsLiving()) continue;
		    
		    double dx = cos(angle*PI/180);
		    double dy = sin(angle*PI/180);
		    double olddx = dx;
		    double olddy = dy;
		    float tmpx = currentSpr->X() + currentSpr->Width()/2;
		    float tmpy = currentSpr->Y() + currentSpr->Height()/2;
		    if(tmpx < X() || tmpx > X() + Width()/2) {
		        dx = -dx;
		        std::cout << "Change dx" << std::endl;
		    }
		    if(tmpy < Y() || tmpy > Y() + Height()/2) {
		        dy = -dy;
		        std::cout << "Change dy" << std::endl;
		    }
		    std::cout << atan(dy/dx) << std::endl;
		    SetAngle(tan(dy/dx)*180/PI);
		    //system("sleep 1");
		    //assert(dx != olddx && dy != olddy);
		    dynamic_cast<Brique*>(currentSpr)->Hit();
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
    speed = 15;
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
