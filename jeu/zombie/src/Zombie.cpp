#include <cstdlib>
#include <iostream>
#include "Zombie.h"
#include "ZombieGame.h"

using namespace std;

#define GAMEOVER 1600

//================================================================ PUBLIC

Zombie::Zombie(sf::Image *pImg, sf::Image *pFond)
	: AnimatedSprite(pImg, 5, 5, 5, 50, 88), fond(pFond)
{
	type = "zombie";
	
    //SetY(0);
    fcpt = 0;
    fcptMax = 2+rand()%3;
    
    // HitBox :
    hitBox.Left 	= 10;
    hitBox.Top 		= 10;
    hitBox.Right 	= 50;
    hitBox.Bottom 	= 88;
    
    int y = 0;
    while(fond->GetPixel(X()+Width()/2, y+Height()-3).a < 40) {
        y++;
    }
    SetY(y);
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
	
	if(X() > GAMEOVER)
	{
			game->GameOver();
			return;
	}
	
    if(fcpt > fcptMax) {
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
