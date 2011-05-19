#ifndef ZOMBIEGAME_H
#define ZOMBIEGAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Interface.h"
#include "Game.h"
#include "Camera.h"
#include "AnimatedSprite.h"
#include "Catapulte.h"
#include "Zombie.h"
#include "Explosion.h"
#include "Bombe.h"

class ZombieGame : public Game {
    public:
    
    	static const int SCREEN_W = 800;
        static const int SCREEN_H = 600;
    	
    	// =================================== Constructors / Destructor
        ZombieGame();
        ~ZombieGame();
        
        // =================================== Public methods
        sf::Vector2f GetMousePosition();
        void GameOver();
        
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
		bool gameover;
		
		// Sprites :
		sf::Image* imgzombie;
		std::vector<Zombie*> sprzombies;
		sf::Image* imgfond;
		sf::Sprite* sprfond;
		sf::Image* imgterrain;
		sf::Sprite* sprterrain;
		sf::Image* imgbombe;
		Bombe* sprbombe;
		sf::Image* imgexplosion;
		Explosion* sprexplosion;
		Catapulte* catapulte;
};

#endif
