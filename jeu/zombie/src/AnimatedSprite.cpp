
#include "AnimatedSprite.h"

//================================================================ PUBLIC

AnimatedSprite::AnimatedSprite(sf::Image *pImg, int _fpi, int _ncols, int _nbimgs, float _imgwidth, float _imgheight)
	: GameSprite(pImg), fpi(_fpi), ncols(_ncols), nbimgs(_nbimgs), imgwidth(_imgwidth), imgheight(_imgheight)
{
	offsetX = 0;
	offsetY = 0;
	index = 0;
	fcount = 0;
}

AnimatedSprite::~AnimatedSprite() {
	// Nothing to delete
}

void AnimatedSprite::Animate() {
	if(fcount == fpi)
	{
		if(index>nbimgs) index = 0;
		offsetX = imgwidth*(index%ncols);
		offsetY = imgheight*(index/ncols);
		index++;
		fcount = 0;
		SetSubRect(sf::IntRect(offsetX, offsetY, offsetX+imgwidth, offsetY+imgheight));
	}
	fcount++;
}

void AnimatedSprite::Update() {
	// To be redefined if necessary
}

void AnimatedSprite::HitBy(GameSprite* pSpr) {
	// To be redefined if necessary
}
