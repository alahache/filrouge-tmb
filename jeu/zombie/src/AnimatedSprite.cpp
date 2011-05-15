
#include <iostream>
#include "AnimatedSprite.h"

using namespace std;

//================================================================ PUBLIC

AnimatedSprite::AnimatedSprite(sf::Image *pImg, int _fpi, int _ncols, int _nbimgs, float _imgwidth, float _imgheight)
	: GameSprite(pImg), fpi(_fpi), ncols(_ncols), nbimgs(_nbimgs), imgwidth(_imgwidth), imgheight(_imgheight)
{
	offsetX = 0;
	offsetY = 0;
	index = 0;
	fcount = 0;
	play = true;
	loop = true;
	begin = 0;
	end = nbimgs-1;
	SetSubRect(sf::IntRect(offsetX, offsetY, offsetX+imgwidth, offsetY+imgheight));
}

AnimatedSprite::~AnimatedSprite() {
	// Nothing to delete
}

void AnimatedSprite::Animate() {
	if(!play) return;
	if(fcount == fpi)
	{
		if(index>=end)
		{
			if(loop)
				index = begin;
			else
			{
				Stop();
				End();
				return;
			}
		}
		
		offsetX = imgwidth*(index%ncols);
		offsetY = imgheight*(index/ncols);
		index++;
		fcount = 0;
		SetSubRect(sf::IntRect(offsetX, offsetY, offsetX+imgwidth, offsetY+imgheight));
	}
	fcount++;
}

void AnimatedSprite::Play() {
	play = true;
}

void AnimatedSprite::Stop() {
	play = false;
}

void AnimatedSprite::Play(int _begin, int _end, bool _loop) {
	begin = _begin;
	end = _end;
	loop = _loop;
	play = true;
	index = begin;
}

void AnimatedSprite::Update() {
	// To be redefined if necessary
}

void AnimatedSprite::HitBy(GameSprite* pSpr) {
	// To be redefined if necessary
}

void AnimatedSprite::End() {
	// To be redefined if necessary
}
