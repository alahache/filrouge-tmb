#ifndef INTERFACE
#define INTERFACE

#include <SFML/Graphics.hpp>

class Interface {
    public:
        Interface(); //Constructeur normal
        Interface(sf::RenderWindow* myApp); //Constructeur pour l'émulation de la webcam
        ~Interface();
        
        float GetX();
        float Gety();
        
        bool isMousePressed();
        
        void setPosition(float x, float y);
        void setMousePressed(bool isMousePressed);
        
    
    private:
        void miseAJour(); //Emulation de la webcam
        sf::RenderWindow* app;
        
        float x;
        float y;
        bool isPressed;
};

#endif
