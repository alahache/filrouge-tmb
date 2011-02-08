#ifndef BALLE_H
#define BALLE_H

#include <SFML/Graphics.hpp>

// Previous declaration of Game Interface :
class Game;

class GameSprite : public sf::Sprite {
    public:
    	
    	// =================================== Constructors / Destructor
        GameSprite(sf::Image* pImg, Game* pGame=0);
        virtual ~GameSprite();
        
        // =================================== Abstract methods
        virtual void Update() = 0;
        virtual void Hit(GameSprite* pSpr) = 0;
        virtual void Draw() = 0;
        
        // =================================== Getters
       	float GetX();
       	float GetY();
       	const sf::FloatRect& GetHitBox();
       	
       	// =================================== Setters
       	void SetParent(GameSprite* pParent);
    
    protected:
    
    	// =================================== Attributes
    	float x;
        float y;
        Game *game;
        GameSprite *parent;
        sf::FloatRect hitBox;
};

#endif
