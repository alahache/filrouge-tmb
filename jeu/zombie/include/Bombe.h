#ifndef BOMBE_H
#define BOMBE_H

#include <SFML/Graphics.hpp>


#include "GameSprite.h"
#include "Game.h"
#include "Catapulte.h"
#include "Explosion.h"

class ZombieGame;

class Bombe : public GameSprite {
    public:
    
    	static const float POSX = 1565;
    	static const float POSY = 245;
    	 
    	static const float LIMIT = 250;
    	static const float EXPLOSIONLIMIT = 100;
    	    	
    	
    	// =================================== Constructors / Destructor
        Bombe(sf::Image* img, ZombieGame* pGame, Catapulte* _catapulte, sf::Image* _imgterrain, Explosion* _sprexplosion);
        ~Bombe();
        
        // =================================== Redefined methods from GameSprite
       	void Update();
       	
       	// =================================== Public methods
    
    protected:
    
    	// =================================== Attributes
    	ZombieGame* game;
    	Catapulte* catapulte;
    	sf::Image* imgterrain;
    	sf::Vector2f posOrigin;
    	Explosion* sprexplosion;
    	
        sf::Vector2f direction;
        float speed;
        float angle;
        
        // Test if the ball is attach or not :
        bool attached;
        bool drag;
        bool lancee;
        
        // =================================== Protected methods
        void calculateDirection();
        void explosion();
};

#endif
