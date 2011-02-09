#ifndef BREAKOUT
#define BREAKOUT

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "GameSprite.h"

class Game {
    public:
    
    	// =================================== Constructors / Destructor
        Game(unsigned int w=800, unsigned int h=600, std::string title="Game");
        virtual ~Game();
        
        // =================================== Abstract methods
        virtual void Run() = 0;
        //virtual GameSprite* CreateSprite(std::string type) = 0;
        
        // =================================== Sprite List methods
        void AddSprite(GameSprite* pSpr);
        GameSprite* GetSprite(unsigned int i);
        unsigned int NbSprites();
        
        // =================================== Getters
        sf::RenderWindow* GetWindow();
    
    protected:
    
    	// =================================== Protected methods
        virtual void loadRessources() = 0;
        virtual void initGame() = 0;
        
        // =================================== Attributes
        std::vector<GameSprite*> sprites;
        sf::RenderWindow* window;
        bool isGameOn;
};

#endif
