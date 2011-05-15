#ifndef CATAPULTE_H
#define CATAPULTE_H

#include <SFML/Graphics.hpp>

#include "Game.h"

#define LINESIZE 10

class ZombieGame;

class Catapulte
{
	public:

		// =================================== Constructors / Destructor
		Catapulte(ZombieGame* pGame, float x1, float y1, float x2, float y2);
		virtual ~Catapulte();

		// =================================== Public methods
		void DrawLines(float posX, float posY);
		
	protected:

		// =================================== Attributes
		ZombieGame* game;
		
		// Define the first point :
		float xAttLeft;
		float yAttLeft;
		
		// Define the second point :
		float xAttRight;
		float yAttRight;
		
		// Define the two lines :
		sf::Shape line1;
		sf::Shape line2;
		
		// =================================== Protected methods
};

#endif
