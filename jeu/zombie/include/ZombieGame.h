#ifndef ZOMBIEGAME_H
#define ZOMBIEGAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Interface.h"
#include "Game.h"
#include "Bombe.h"
#include "Camera.h"
#include "AnimatedSprite.h"
#include "Catapulte.h"

class ZombieGame : public Game {
    public:
    
    	static const int SCREEN_W = 800;
        static const int SCREEN_H = 600;
    	
    	// =================================== Constructors / Destructor
        ZombieGame();
        ~ZombieGame();
        
        // =================================== Public methods
        sf::Vector2f GetMousePosition();
        
        // =================================== Redefined methods
        void Run();
        
        // =================================== Getters / Setters
        void SetInterface(Interface* myInterface);
        Interface& GetInterface();
        Camera& GetCamera();
    
    protected:
    	// =================================== Redefined protected methods
        void loadRessources();
        void initGame();
        
		// =================================== Attributes
		// Game engine :
		Interface* interface;
		Camera* camera;
		Bombe* bombe;
		Catapulte* catapulte;
				
		// Sprites :
		sf::Image* imgzombie;
		AnimatedSprite* sprzombie;
		sf::Image* imgfond;
		sf::Sprite* sprfond;
		sf::Image* imgterrain;
		sf::Sprite* sprterrain;
		sf::Image* imgbombe;
		GameSprite* sprbombe;
		int viewoffset;

};

#endif
