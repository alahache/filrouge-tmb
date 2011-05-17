#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"

class Zombie : public AnimatedSprite {
    public:
    	// =================================== Constructors / Destructor
        Zombie(sf::Image *pImg, sf::Image *pFond);
        ~Zombie();
        
        // =================================== Public methods
        void Kill();
        bool IsDead();
        
        // =================================== Redefined methods
        virtual void Update();
		virtual void HitBy(GameSprite* pSpr);
        
        // =================================== Getters / Setters
    
    protected:
        // =================================== Attributes
        sf::Image* fond;
        int fcpt;
        bool dead;
};

#endif
