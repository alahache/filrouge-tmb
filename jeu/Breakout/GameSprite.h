#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include <SFML/Graphics.hpp>

class GameSprite : public sf::Sprite {
    public:
    	
    	// =================================== Constructors / Destructor
        GameSprite(sf::Image* pImg);
        virtual ~GameSprite();
        
        // =================================== Public methods
        bool Hits(GameSprite* pSpr);
        
        // =================================== Abstract methods
        virtual void Update();
        virtual void HitBy(GameSprite* pSpr);
        
        // =================================== Getters
       	float X();
       	float Y();
       	float Width();
       	float Height();
       	const sf::FloatRect& GetHitBox();
       	
       	// =================================== Setters
       	void SetParent(GameSprite* pParent);
    
    protected:
    
    	// =================================== Attributes
        GameSprite *parent;
        sf::FloatRect hitBox;
};

#endif
