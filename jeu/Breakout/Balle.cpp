#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Balle.h"
#include "BreakOut.h"

#define PI 3.14159265

Balle::Balle(sf::Image *img, BreakOut* leJeu)
	: sf::Sprite(*img), jeu(leJeu)
{
	x=jeu->GetBackground()->GetSize().x / 2;
	y=jeu->GetBackground()->GetSize().y / 2;
	SetX(x);
	SetY(y);
    
    // Direction :
    angle = -45;
    speed = 10;
    calculerDirection();
    
    // HitBox :
    hitBox.Left 	= x;
    hitBox.Top 		= y;
    hitBox.Right 	= x + GetSize().x;
    hitBox.Bottom 	= y + GetSize().y;
    
}

Balle::~Balle() {
	// rien.
}

void Balle::MajPositions() {
	
	// Collisions avec les bords du terrain :
	if(x <= jeu->GetBackground()->GetPosition().x || x >= jeu->GetBackground()->GetSize().x)
		direction.x = -direction.x;
	if(y <= jeu->GetBackground()->GetPosition().y || y >= jeu->GetBackground()->GetSize().y)
		direction.y = -direction.y;
		
	// Collisions avec les sprites du jeu :
	for(unsigned int i=0; i<jeu->NbSprites(); i++) {
	
		sf::Sprite* sprCourant = jeu->GetSprite(i);
		if(sprCourant == this) continue;
		
		// TODO : créer classe GameSprite avec hitBox, maj, ...
		sf::Vector2f posSpr = sprCourant->GetPosition();
		sf::Vector2f sizeSpr = sprCourant->GetSize();
		sf::FloatRect rectSpr(posSpr.x, posSpr.y, posSpr.x + sizeSpr.x, posSpr.y + sizeSpr.y);
		
		// Test de collistion :
		if(!hitBox.Intersects(rectSpr)) continue;
		
		// Gestion Sprites spéciaux :
		if(sprCourant == jeu->GetBarre()) {		// Collision avec la barre
		
			// Contrôle direction : (entre 30 et 160 degrés)
			angle = (120.0/sizeSpr.x) * (rectSpr.Right - (x + GetSize().x / 2)) + 30.0;
			
			calculerDirection();
		}
	}
	
	// Bouger le sprite :
	Move(direction);
	
	x=GetPosition().x;
	y=GetPosition().y;
	
	// HitBox :
    hitBox.Left 	= x;
    hitBox.Top 		= y;
    hitBox.Right 	= x + GetSize().x;
    hitBox.Bottom 	= y + GetSize().y;
}

void Balle::SetSpeed(float unSpeed) {
	speed = unSpeed;
	calculerDirection();
}

void Balle::SetAngle(float unAngle) {
	angle = unAngle;
	calculerDirection();
}

float Balle::GetX() {
	return GetPosition().x;
}

float Balle::GetY() {
	return GetPosition().y;
}

const sf::FloatRect & Balle::GetHitBox() {
	return hitBox;
}

void Balle::calculerDirection() {
	float angleRadian = angle*PI/180;
	direction.x = speed * cos(angleRadian);
	direction.y = - speed * sin(angleRadian);	// On soustrait la direction obtenue grâce à l'angle
}
