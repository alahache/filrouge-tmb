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
    
        BreakOut();
        ~BreakOut();
        
        void Run();
        
        void SetInterface(Interface* myInterface);
        Interface& GetInterface();
        
        GameSprite& GetBarre();
        GameSprite& GetBalle();
        sf::Sprite& GetBackground();
    
    private:
        void loadRessources();
        void initGame();
        
        Interface* interface;
        
        sf::Image* imgBalle;
        GameSprite* balle;
        
        sf::Image* imgBarre;
        GameSprite* barre;
        
        sf::Image* imgBackground;
        sf::Sprite* sprBackground;
        
        sf::Font* font;
        sf::String* text;
        
        int score;
};

#endif
