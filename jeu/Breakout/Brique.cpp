#include <cmath>

#include "Brique.h"
#include "BreakOut.h"

#define PI 3.14159265

Brique::Brique(sf::Image *img, int xinit, int yinit, BreakOut* pGame, int linitLife)
	: GameSprite(img), game(pGame), initLife(linitLife)
{
    SetPosition(xinit, yinit);
    Init();
}

Brique::~Brique() {
	// Nothing to delete either
}

void Brique::Init() {
    life = initLife;
}

void Brique::SetLife(int laVie) {
	life = laVie;
}

bool Brique::IsLiving() {
    return life>0;
}
