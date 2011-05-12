#ifndef BOMBE_H
#define BOMBE_H

#include <SFML/Graphics.hpp>

#include "GameSprite.h"
#include "game.h"

class ZombieGame;

class Bombe : public GameSprite {
    public:
    	
    	// =================================== Constructors / Destructor
        Bombe(sf::Image* img, ZombieGame* pGame=0);
        ~Bombe();
        
        // =================================== Redefined methods from GameSprite
       	void Update();
       	
       	sf::Vector2f GetPosBombe();
       	float GetSizeBombe();
       	
       	// =================================== Public methods
       	void Init();
       	void SetSpeed(float anySpeed);
       	void SetAngle(float anyAngle);
    
    protected:
    
    	// =================================== Attributes
    	ZombieGame* game;
        sf::Vector2f direction;
        
        float speed;
        float angle;
        
        // Define the limits :
        float sizeCircleMove;
        int xEye;
        int yEye;
        
        // Test if the ball is attach or not :
        bool bind;
        
        // =================================== Protected methods
        void limitMovement();
        void calculateDirection();
};

#endif
