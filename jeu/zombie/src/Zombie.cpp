
#include <iostream>
#include "Zombie.h"

using namespace std;

//================================================================ PUBLIC

Zombie::Zombie(sf::Image *pImg, sf::Image *pFond)
	: AnimatedSprite(pImg, 5, 5, 5, 50, 88), fond(pFond)
{
	type = "zombie";
	
    SetY(0);
    fcpt = 0;
    
    // HitBox :
    hitBox.Left 	= 10;
    hitBox.Top 		= 10;
    hitBox.Right 	= 50;
    hitBox.Bottom 	= 88;
    
    dead = false;
}

Zombie::~Zombie() {
	// Nothing to delete
}

void Zombie::Kill() {
	dead = true;
}

bool Zombie::IsDead() {
	return dead;
}

void Zombie::Update() {
    if(fcpt > 3) {
        fcpt = 0;
	    const int max = 1;
	    int sum = 0;
	    while(sum < max) {
	        SetX(X()+1);
	        sum++;
	        if(fond->GetPixel(X()+Width()/2, Y()+Height()-3).a < 40) {
	            while(fond->GetPixel(X()+Width()/2, Y()+Height()-3).a < 40) {
	                SetY(Y()+1);
	                sum++;
	            }
	        } else {
	            while(fond->GetPixel(X()+Width()/2, Y()+Height()-3).a > 40) {
	                SetY(Y()-1);
	                sum++;
	            }
	        }
	    }
	}
	fcpt++;
}

void Zombie::HitBy(GameSprite* pSpr) {
	if(pSpr->GetType()=="bombe")
		Kill();
}
