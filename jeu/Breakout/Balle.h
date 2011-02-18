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
       	void SetSpeed(float anySpeed);
       	void SetAngle(float anyAngle);
    
    protected:
    
    	// =================================== Attributes
    	BreakOut* game;
        sf::Vector2f direction;
        float speed;
        float angle;
        
        // =================================== Protected methods
        void calculateDirection();
};

#endif
