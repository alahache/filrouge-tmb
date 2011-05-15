#ifndef BOMBE_H
#define BOMBE_H

#include <SFML/Graphics.hpp>


#include "GameSprite.h"
#include "Game.h"

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
       	void SetPosition(float x, float y);
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
        float criticDist;
        int xEye;
        int yEye;
        
        // Test if the ball is attach or not :
        bool bind;
        
        // =================================== Protected methods
        void limitMovement(int x, int y, float taille);
        void calculateDirection();
};

#endif
