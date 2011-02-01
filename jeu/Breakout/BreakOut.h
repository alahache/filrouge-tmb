#ifndef BREAKOUT
#define BREAKOUT

#include <SFML/Graphics.hpp>

#include "Interface.h"

class BreakOut {
    public:

        static const int SCREEN_W = 800;
        static const int SCREEN_H = 600;
    
        BreakOut();
        ~BreakOut();
        
        void Run();
        
        void SetInterface(Interface* myInterface);
        
        sf::RenderWindow* GetRenderWindow(); //Emulation de la webcam
    
    private:
        void loadRessources();
        void initGame();
        
        Interface* interface;
        
        sf::Image* imgBalle; //Image de la balle
        sf::Sprite* sprBalle; //Sprite de la balle
        
        sf::Image* imgBackground;
        sf::Sprite* sprBackground;
        
        sf::Font* font;
        sf::String* text;
        
        sf::RenderWindow* app;
        
        int score;
        bool isGameOn;
};

#endif
