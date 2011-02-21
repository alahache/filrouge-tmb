
#include "GameSprite.h"
#include "Game.h"

//================================================================ PUBLIC

GameSprite::GameSprite(sf::Image *pImg)
	: sf::Sprite(*pImg)
{
	// Position :
	SetX(0);
	SetY(0);
    
    // HitBox :
    hitBox.Left 	= 0;
    hitBox.Top 		= 0;
    hitBox.Right 	= GetSize().x;
    hitBox.Bottom 	= GetSize().y;
    
}

GameSprite::~GameSprite() {
	// Nothing to delete
}

bool GameSprite::Hits(GameSprite* pSpr) {
	sf::FloatRect r1 = GetHitBox();
		r1.Left		+= X();
		r1.Right	+= X();
		r1.Top		+= Y();
		r1.Bottom	+= Y();
	sf::FloatRect r2 = pSpr->GetHitBox();
		r2.Left		+= pSpr->X();
		r2.Right	+= pSpr->X();
		r2.Top		+= pSpr->Y();
		r2.Bottom	+= pSpr->Y();
	
	return r1.Intersects(r2);
}

void GameSprite::Update() {
	// To be redefined if necessary
}

void GameSprite::HitBy(GameSprite* pSpr) {
	// To be redefined if necessary
}

std::string GameSprite::GetType() {
	return type;
}

float GameSprite::X() {
	return GetPosition().x;
}

float GameSprite::Y() {
	return GetPosition().y;
}

float GameSprite::Width() {
	return GetSize().x;
}

float GameSprite::Height() {
	return GetSize().y;
}

const sf::FloatRect& GameSprite::GetHitBox() {
    return hitBox;
}

