#ifndef BALLE_H
#define BALLE_H

#include <SFML/Graphics.hpp>

// Déclaration anticipée de la classe BreakOut :
class BreakOut;

class Balle : public sf::Sprite {
    public:
    
        Balle(sf::Image* img, BreakOut *leJeu=0)
        	: sf::Sprite(img), jeu(leJeu) { }
        ~Balle();
        
       	float GetX();
       	float GetY();
       	void majPositions();
    
    private:
        
        BreakOut *jeu
        
        sf::Vector2f direction;	// Direction du Sprite
        // note : Vector2f -> Vector2<float>
};

#endif
