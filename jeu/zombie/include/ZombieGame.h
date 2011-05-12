#ifndef ZombieGameGAME_H
#define ZombieGameGAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Interface.h"
#include "Game.h"
#include "AnimatedSprite.h"

class ZombieGame : public Game {
    public:
    
    	static const int SCREEN_W = 800;
        static const int SCREEN_H = 600;
    	
    	// =================================== Constructors / Destructor
        ZombieGame();
        ~ZombieGame();
        
        // =================================== Redefined methods
        void Run();
        
        // =================================== Getters / Setters
        void SetInterface(Interface* myInterface);
        Interface& GetInterface();
    
    protected:
    	// =================================== Redefined protected methods
        void loadRessources();
        void initGame();
        
        // =================================== Attributes
        Interface* interface;
        sf::Image* imgzombie;
        AnimatedSprite* sprzombie;
        sf::Image* imgfond;
        sf::Sprite* sprfond;
        int offset;
};

#endif
