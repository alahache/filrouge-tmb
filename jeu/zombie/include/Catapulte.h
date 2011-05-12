#ifndef CATAPULTE_H
#define CATAPULTE_H

#include <string>
#include <SFML/Graphics.hpp>

#include "game.h"


class ZombieGame;

class Catapulte
{
	public:

		// =================================== Constructors / Destructor
		Catapulte(ZombieGame* pGame=0);
		virtual ~Catapulte();

		// =================================== Public methods
		void init();

		// =================================== Abstract methods
		virtual void Update();

		// =================================== Getters
		

		// =================================== Setters
		void SetPosBombe(float anyXBombe, float anyYBombe);

	protected:

		// =================================== Attributes
		ZombieGame* game;
		
		// Define the first point :
		float xAttLeft;
		float yAttLeft;
		
		// Define the second point :
		float xAttRight;
		float yAttRight;
		
		// Define the Bombe position :
		float xBombe;
		float yBombe;
		
		// Define the two lines :
		sf::Shape* line1;
		sf::Shape* line2;
		
		// TODO : Properties :
		//Thickness, Color
		
		// =================================== Protected methods
        void drawLines();
};

#endif
