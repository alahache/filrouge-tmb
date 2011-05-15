#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "GameSprite.h"

class AnimatedSprite : public GameSprite {
	public:

		// =================================== Constructors / Destructor
		AnimatedSprite(sf::Image* pImg, int _fpi, int _ncols, int _nbimgs, float _imgwidth, float _imgheight);
		virtual ~AnimatedSprite();

		// =================================== Public methods
		void Animate();
		void Play();
		void Stop();
		void Play(int _begin, int _end, bool _loop=true);

		// =================================== Abstract methods
		virtual void Update();
		virtual void HitBy(GameSprite* pSpr);
		virtual void End();

		// =================================== Getters
		

		// =================================== Setters

	protected:

		// =================================== Attributes
		int index;
		int fpi;	// frames per image
		int fcount;
		int ncols;
		int nbimgs;
		float imgwidth;
		float imgheight;
		float offsetX;
		float offsetY;
		
		bool play;
		bool loop;
		int begin;
		int end;
};

#endif
