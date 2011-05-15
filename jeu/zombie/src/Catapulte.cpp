
#include "ZombieGame.h"
#include "Catapulte.h"

//================================================================ PUBLIC

Catapulte::Catapulte(ZombieGame* pGame, float x1, float y1, float x2, float y2)
		: game(pGame)
{
	// Positions :
	
	// Define the first point :
	xAttLeft = x1;
	yAttLeft = y1;
	
	// Define the second point :
	xAttRight = x2;
	yAttRight = y2;
}

Catapulte::~Catapulte()
{
	// delete : nothing
}

void Catapulte::DrawLines(float posX, float posY)
{
	line1 = sf::Shape::Line(xAttLeft, yAttLeft, posX, posY, LINESIZE, sf::Color::Black);
	line2 = sf::Shape::Line(xAttRight, yAttRight, posX, posY, LINESIZE, sf::Color::Black);
	game->GetWindow()->Draw(line1);
	game->GetWindow()->Draw(line2);
}
