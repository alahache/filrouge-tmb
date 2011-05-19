#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"

class ZombieGame;

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
        ZombieGame* game;
        sf::Image* fond;
        int fcpt;
        int fcptMax;
        bool dead;
};

#endif
