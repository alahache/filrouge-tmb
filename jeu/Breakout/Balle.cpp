#include <SFML/Graphics.hpp>
#include <iostream>
#include "Balle.h"
#include "BreakOut.h"

Balle::Balle(BreakOut* leJeu) {
	// Image :
	imgBalle = new sf::Image();
    if (!imgBalle->LoadFromFile("img.png"))
        std::cout << "ERREUR: chargement de l'image";
    sprBalle = new sf::Sprite(*imgBalle);
    
    // Position :
    x=0;
    y=0;
    
    // Background :
    jeu = leJeu;
    
    if(jeu) {
    	x=jeu->GetBackground()->GetSize().x / 2;
    	y=jeu->GetBackground()->GetSize().y / 2;
    }
    
    // Direction :
    direction.x=3;
    direction.y=3;
}

Balle::~Balle() {
	delete imgBalle;
	delete sprBalle;
}

float Balle::GetX() {
	return x;
}

float Balle::GetY() {
	return y;
}

sf::Sprite* Balle::GetSprite() {
	return sprBalle;
}

void Balle::majPositions() {
	
	// TODO : gérer les collisions avec tous les objets (cf liste sprites)
	
	// Collisions avec les bords du terrain :
	if(x <= jeu->GetBackground()->GetPosition().x || x >= jeu->GetBackground()->GetSize().x)
		direction.x = -direction.x;
	if(y <= jeu->GetBackground()->GetPosition().y || y >= jeu->GetBackground()->GetSize().y)
		direction.y = -direction.y;
	
	// Bouger le sprite :
	sprBalle->Move(direction);
	
	x=sprBalle->GetPosition().x;
	y=sprBalle->GetPosition().y;
}

