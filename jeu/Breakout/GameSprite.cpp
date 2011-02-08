
#include "GameSprite.h"

#include <iostream>
#include "Game.h"

//================================================================ PUBLIC

GameSprite::GameSprite(sf::Image *pImg, Game* pGame)
	: sf::Sprite(*pImg), game(pGame)
{
	// Position :
	x=0;
	y=0;
	SetX(x);
	SetY(y);
    
    // HitBox :
    hitBox.Left 	= x;
    hitBox.Top 		= y;
    hitBox.Right 	= x + GetSize().x;
    hitBox.Bottom 	= y + GetSize().y;
    
    // Parent :
    parent = 0;
    
}

GameSprite::~GameSprite() {
	// nothing.
}

float GameSprite::GetX() {
	return GetPosition().x;
}

float GameSprite::GetY() {
	return GetPosition().y;
}

const sf::FloatRect & GameSprite::GetHitBox() {
	return hitBox;
}

void GameSprite::SetParent(GameSprite* pParent) {
	parent = pParent;
}
