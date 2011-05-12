#ifndef ZombieGameGAME_H
#define ZombieGameGAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Interface.h"
#include "Game.h"

class ZombieGame : public Game {
    public:
    
    	static const int SCREEN_W = 800;
        static const int SCREEN_H = 600;
    	
    	// =================================== Constructors / Destructor
        BreakOut();
        ~BreakOut();
        
        // =================================== Redefined methods
        void Run();
        //GameSprite* CreateSprite(std::string type);
        
        // =================================== Getters / Setters
        void SetInterface(Interface* myInterface);
        Interface& GetInterface();
    
    protected:
    	// =================================== Redefined protected methods
        void loadRessources();
        void initGame();
        
        // =================================== Attributes
        Interface* interface;
};

#endif
