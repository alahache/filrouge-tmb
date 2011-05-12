#ifndef BALLE_H
#define BALLE_H

#include <SFML/Graphics.hpp>

#include "GameSprite.h"

class BreakOut;

class Balle : public GameSprite {
    public:
    	
    	// =================================== Constructors / Destructor
        Balle(sf::Image* img, BreakOut* pGame=0);
        ~Balle();
        
        // =================================== Redefined methods from GameSprite
       	void Update();
       	
       	// =================================== Public methods
       	void Init();
    
    protected:
    
    	// =================================== Attributes
    	BreakOut* game;
        sf::Vector2f direction;
        
        // =================================== Protected methods
};

#endif
