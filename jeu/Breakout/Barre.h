#ifndef BARRE_H
#define BARRE_H

#include <SFML/Graphics.hpp>

#include "GameSprite.h"

class BreakOut;

class Barre : public GameSprite {
    public:
    	
    	// =================================== Constructors / Destructor
        Barre(sf::Image* img, BreakOut* pGame=0);
        ~Barre();
        
        // =================================== Redefined methods from GameSprite
       	void Update();
       	
       	// =================================== Public methods
    
    protected:
    
    	// =================================== Attributes
    	BreakOut* game;
        
        // =================================== Protected methods
};

#endif
