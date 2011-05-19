#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Interface.h"
#include "Game.h"

class BreakOut : public Game {
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
        void Lost();
        
        GameSprite& GetBarre();
        GameSprite& GetBalle();
        sf::Sprite& GetBackground();
    
    protected:
    	// =================================== Redefined protected methods
        void loadRessources();
        void initGame();
        
        // =================================== Attributes
        Interface* interface;
        
        sf::Image* imgBalle;
        GameSprite* balle;
        
        sf::Image* imgBarre;
        GameSprite* barre;
        
        sf::Image* imgBrique;
        std::vector<GameSprite*> brique;
        
        sf::Image* imgBackground;
        sf::Sprite* sprBackground;
        
        sf::Font* font;
        sf::String* text;
        
        int score;
        bool haveWon;
        bool first;
};

#endif
