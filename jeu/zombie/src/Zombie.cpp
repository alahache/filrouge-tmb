
#include <iostream>
#include "Zombie.h"

using namespace std;

//================================================================ PUBLIC

Zombie::Zombie(sf::Image *pImg, sf::Image *pFond)
	: AnimatedSprite(pImg, 5, 5, 5, 50, 88), fond(pFond)
{
    SetY(0);
    fcpt = 0;
}

Zombie::~Zombie() {
	// Nothing to delete
}

void Zombie::Update() {
    if(fcpt > 3) {
        fcpt = 0;
	    const int max = 1;
	    int sum = 0;
	    std::cout << Y() << std::endl;
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
	// To be redefined if necessary
}
