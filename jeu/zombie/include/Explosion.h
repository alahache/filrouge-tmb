#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"
#include "Game.h"

class Explosion : public AnimatedSprite {
    public:
    	// =================================== Constructors / Destructor
        Explosion(sf::Image *pImg, Game* _game, float x, float y);
        ~Explosion();
        
        // =================================== Public methods
        
        // =================================== Redefined methods
        virtual void Update();
		virtual void HitBy(GameSprite* pSpr);
		virtual void End();
        
        // =================================== Getters / Setters
    
    protected:
        // =================================== Attributes
        Game* game;
};

#endif
