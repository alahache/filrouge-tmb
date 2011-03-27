#ifndef BRIQUE_H
#define BRIQUE_H

#include <SFML/Graphics.hpp>

#include "GameSprite.h"

class BreakOut;

class Brique : public GameSprite {
    public:
    	
    	// =================================== Constructors / Destructor
        Brique(sf::Image* img, int xinit, int yinit, BreakOut* pGame=0, int linitLife=1);
        ~Brique();
       	
       	// =================================== Public methods
       	void Init();
       	void SetLife(int laVie);
       	void Hit(); //touché par la balle
       	bool IsLiving();
    
    protected:
    
    	// =================================== Attributes
    	BreakOut* game;
        int life;
        int initLife;
};

#endif
