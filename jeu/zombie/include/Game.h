#ifndef BREAKOUT
#define BREAKOUT

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "GameSprite.h"

class Game {
    public:
    
    	// =================================== Constructors / Destructor
        Game(unsigned int w=800, unsigned int h=600, std::string title="Game", unsigned int fps=30);
        virtual ~Game();
        
        // =================================== Abstract methods
        virtual void Run() = 0;
        
        // =================================== Sprite List methods
        void AddSprite(GameSprite* pSpr);
        void RemoveSprite(GameSprite* pSpr);
        GameSprite* GetSprite(unsigned int i);
        unsigned int NbSprites();
        
        // =================================== Getters
        sf::RenderWindow* GetWindow();
        unsigned int GetFps();
    
    protected:
    
    	// =================================== Protected methods
        virtual void loadRessources() = 0;
        virtual void initGame() = 0;
        
        // =================================== Attributes
        std::vector<GameSprite*> sprites;
        sf::RenderWindow* window;
        bool isGameOn;
        unsigned int fps;
};

#endif
