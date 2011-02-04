#ifndef BALLE_H
#define BALLE_H

#include <SFML/Graphics.hpp>

// Déclaration anticipée de la classe BreakOut :
class BreakOut;

class Balle {
    public:
    
        Balle(BreakOut *leJeu=0);
        ~Balle();
        
       	float GetX();
       	float GetY();
       	void majPositions();
       	sf::Sprite* GetSprite();
    
    private:

        sf::Image* imgBalle; //Image de la balle
        sf::Sprite* sprBalle; //Sprite de la balle
        
        BreakOut *jeu;	// Sprite qui contient la balle
        
        sf::Vector2f direction;	// Direction du Sprite
        // note : Vector2f -> Vector2<float>
        
		float x;
		float y;
};

#endif
