#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <string>
#include <SFML/Graphics.hpp>

class AnimatedSprite : public GameSprite {
	public:

		// =================================== Constructors / Destructor
		AnimatedSprite(sf::Image* pImg);
		virtual ~GameSprite();

		// =================================== Public methods
		virtual bool Hits(GameSprite* pSpr);

		// =================================== Abstract methods
		virtual void Update();
		virtual void HitBy(GameSprite* pSpr);

		// =================================== Getters

		// =================================== Setters

	protected:

		// =================================== Attributes
		int index;
};

#endif
