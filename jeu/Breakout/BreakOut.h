#ifndef BREAKOUT
#define BREAKOUT

#include <SFML/Graphics.hpp>
#include <vector>

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
        
        // Liste de sprites :
        void AjouterSprite(sf::Sprite* spr);
        sf::Sprite* GetSprite(unsigned int i);
        unsigned int NbSprites();
    
    private:
        void loadRessources();
        void initGame();
        
        Interface* interface;
        
        sf::Image* imgBalle;
        Balle* balle;
        
        sf::Image* imgBarre;	// Barre
        sf::Sprite* sprBarre;
        
        sf::Image* imgBackground;
        sf::Sprite* sprBackground;
        
        sf::Font* font;
        sf::String* text;
        
        sf::RenderWindow* app;
        
        // Vecteur de Sprites :
        std::vector<sf::Sprite*> listeSprites;
        
        int score;
        bool isGameOn;
};

#endif
