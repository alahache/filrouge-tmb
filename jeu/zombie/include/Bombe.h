#ifndef BOMBE_H
#define BOMBE_H

#include <SFML/Graphics.hpp>


#include "GameSprite.h"
#include "Game.h"
#include "Catapulte.h"

class ZombieGame;

class Bombe : public GameSprite {
    public:
    
    	static const float POSX = 1600;
    	static const float POSY = 300;
    	
    	// =================================== Constructors / Destructor
        Bombe(sf::Image* img, ZombieGame* pGame, Catapulte* _catapulte);
        ~Bombe();
        
        // =================================== Redefined methods from GameSprite
       	void Update();
       	
       	// =================================== Public methods
       	void SetSpeed(float anySpeed);
       	void SetAngle(float anyAngle);
    
    protected:
    
    	// =================================== Attributes
    	ZombieGame* game;
    	Catapulte* catapulte;
    	
        sf::Vector2f direction;
        float speed;
        float angle;
        
        // Define the limits :
        float sizeCircleMove;
        float criticDist;
        int xEye;
        int yEye;
        
        // Test if the ball is attach or not :
        bool attached;
        bool drag;
        
        // =================================== Protected methods
        void limitMovement(int x, int y, float taille);
        void updateLimit();
        void calculateDirection();
};

#endif
