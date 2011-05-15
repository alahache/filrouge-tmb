#ifndef CATAPULTE_H
#define CATAPULTE_H

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Bombe.h"


class ZombieGame;

class Catapulte
{
	public:

		// =================================== Constructors / Destructor
		Catapulte(ZombieGame* pGame, float x1, float y1, float x2, float y2);
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
		Bombe* bombe;
		
		// Define the first point :
		float xAttLeft;
		float yAttLeft;
		
		// Define the second point :
		float xAttRight;
		float yAttRight;
		
		// Define the Bombe position :
		sf::Vector2f posBombe;
		
		// Define the two lines :
		sf::Shape line1;
		sf::Shape line2;
		
		// Lines properties :
		//int thickness = 20;
		//color : sf::Color::Black;
		
		// =================================== Protected methods
        void drawLines();
};

#endif
