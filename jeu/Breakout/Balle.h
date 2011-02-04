#ifndef BALLE_H
#define BALLE_H

#include <SFML/Graphics.hpp>

class Balle {
    public:
    
        Balle();
        ~Balle();
        
        void Run();
       	float GetX();
       	float GetY();
    
    private:

        sf::Image* imgBalle; //Image de la balle
        sf::Sprite* sprBalle; //Sprite de la balle
        
		float x;
		float y;
};

#endif
