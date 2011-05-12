
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

    //    
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
		//bombe.getPosBombe (x et y)
		//SetPosBombe(x, y);
	
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
	line1 = new sf::Shape::Line(xAttLeft, yAttLeft, xBombe, yBombe, Thickness, Color);
	line2 = new sf::Shape::Line(xAttRight, xAttRight, xBombe, yBombe, Thickness, Color);
}
