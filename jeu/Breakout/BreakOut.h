#ifndef BREAKOUT
#define BREAKOUT

#include <SFML/Graphics.hpp>

#include "Interface.h"
#include "Balle.h"

class BreakOut {
    public:
    
    	static const int SCREEN_W = 800;
        static const int SCREEN_H = 600;
    
        BreakOut();
        ~BreakOut();
        
        void Run();
        
        void SetInterface(Interface* myInterface);
        
        sf::Sprite* GetBarre();
        sf::Sprite* GetBackground();
        
        sf::RenderWindow* GetRenderWindow(); //Emulation de la webcam
    
    private:
        void loadRessources();
        void initGame();
        
        Interface* interface;
        
        Balle* balle;
        
        sf::Image* imgBarre;	// Barre
        sf::Sprite* sprBarre;
        
        sf::Image* imgBackground;
        sf::Sprite* sprBackground;
        
        sf::Font* font;
        sf::String* text;
        
        sf::RenderWindow* app;
        
        // TODO : faire un vecteur de tous les objets
        // vector<Sprite*> listeObjets;
        
        int score;
        bool isGameOn;
};

#endif
