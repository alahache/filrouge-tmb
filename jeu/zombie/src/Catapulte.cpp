
#include "Catapulte.h"

//================================================================ PUBLIC

Catapulte::Catapulte()
{
	// Positions :
	
	// Define the first point :
	xAttLeft = 0;
	yAttLeft = 0;
	
	// Define the second point :
	xAttRight = 0;
	yAttRight = 0;

	// Define the lines :
	line1 = new sf::Shape::Line(xAttLeft, yAttLeft, xBombe, yBombe, thickness, color);
	line2 = new sf::Shape::Line(xAttRight, xAttRight, xBombe, yBombe, thickness, color);
}

Catapulte::~Catapulte()
{
	// delete :
	delete line1;
	delete line2;
}

void Catapulte::Update()
{
	if(isMousePressed)
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
	xBombe = anyXBombe;
	yBombe = anyYBombe;
	drawLines();
}


void Catapulte::drawLines()
{
	ZombieGame->GetWindow()->Draw(line1);
	ZombieGame->GetWindow()->Draw(line2);
}
