#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"

class Zombie : public AnimatedSprite {
    public:
    	// =================================== Constructors / Destructor
        Zombie(sf::Image *pImg);
        ~Zombie();
        
        // =================================== Public methods
        
        // =================================== Redefined methods
        void Update();
		void HitBy(GameSprite* pSpr);
        
        // =================================== Getters / Setters
    
    protected:
        // =================================== Attributes
        
};

#endif
