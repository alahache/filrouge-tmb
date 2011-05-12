
#include "ZombieGame.h"
#include "Catapulte.h"

//================================================================ PUBLIC

Catapulte::Catapulte(ZombieGame* pGame)
		: game(pGame)
{
	// Positions :
	
	// Define the first point :
	xAttLeft = 0;
	yAttLeft = 0;
	
	// Define the second point :
	xAttRight = 0;
	yAttRight = 0;

	// Define the lines :
	line1 = sf::Shape::Line(xAttLeft, yAttLeft, posBombe.x, posBombe.y, 20, sf::Color::Black);
	line2 = sf::Shape::Line(xAttRight, xAttRight, posBombe.x, posBombe.y, 20, sf::Color::Black);
}

Catapulte::~Catapulte()
{
	// delete : nothing
}

void Catapulte::Update()
{
	if(game->GetInterface().isMousePressed())
	{
		posBombe = bombe->GetPosBombe();
		SetPosBombe(posBombe.x, posBombe.y);
		drawLines();
	}
	else
	{
		// Nothing to be done
	}
	
}


void Catapulte::SetPosBombe(float anyXBombe, float anyYBombe)
{
	posBombe.x = anyXBombe;
	posBombe.y = anyYBombe;
	drawLines();
}


void Catapulte::drawLines()
{
	game->GetWindow()->Draw(line1);
	game->GetWindow()->Draw(line2);
}
