#include <SFML/Graphics.hpp>
#include <iostream>
#include "Balle.h"
#include "BreakOut.h"

Balle::Balle(sf::Image *img, BreakOut* leJeu)
	: sf::Sprite(*img), jeu(leJeu)
{

    if(jeu) {
    	x=jeu->GetBackground()->GetSize().x / 2;
    	y=jeu->GetBackground()->GetSize().y / 2;
    }
    
    // Direction :
    direction.x=5;
    direction.y=5;
}

Balle::~Balle() {
	// rien.
}

void Balle::MajPositions() {
	
	// TODO : gérer les collisions avec tous les objets (cf liste sprites)
	
	// Collisions avec les bords du terrain :
	if(x <= jeu->GetBackground()->GetPosition().x || x >= jeu->GetBackground()->GetSize().x)
		direction.x = -direction.x;
	if(y <= jeu->GetBackground()->GetPosition().y || y >= jeu->GetBackground()->GetSize().y)
		direction.y = -direction.y;
	
	// Bouger le sprite :
	Move(direction);
	
	x=GetPosition().x;
	y=GetPosition().y;
}

void Balle::SetDirection(sf::Vector2f uneDirection) {
	direction=uneDirection;
}

float Balle::GetX() {
	return GetPosition().x;
}

float Balle::GetY() {
	return GetPosition().y;
}
