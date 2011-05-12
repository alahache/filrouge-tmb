#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

#include "ZombieGame.h"

ZombieGame::ZombieGame()
	: Game(SCREEN_W, SCREEN_H, "ZombieGame") {
	
	loadRessources();
	
}

ZombieGame::~ZombieGame() {

}

void ZombieGame::loadRessources() {
	sprzombie = new sf::Image();
	if (!sprzombie->LoadFromFile("images/zombie.png"))
		std::cout << "ERREUR: chargement de l'image";
	
	zombie = new AnimatedSprite(sprzombie, 5, 5, 5, 50, 88);
	AddSprite(zombie);
}

void ZombieGame::initGame() {

}

void ZombieGame::Run() {

	initGame();

	// Start the game loop
	while (window->IsOpened())
	{
		// Process events
		sf::Event Event;
		while (window->GetEvent(Event))
		{
			// Close window : exit
			if (Event.Type == sf::Event::Closed)
			window->Close();
		
			if(Event.Type == sf::Event::KeyPressed) {
				if(!isGameOn && Event.Key.Code == sf::Key::Return) {
			    	initGame();
				}
			}
		}
		
		if(isGameOn) {
		
			zombie->Animate();
		
			// Update all sprites :
			for(int i=0; i<sprites.size(); i++) {
				sprites[i]->Update();
			}
		}

		// Clear screen
		window->Clear(sf::Color(255, 255, 255));
		
		// Draw all the objects on the window
		for(int i=0; i<sprites.size(); i++) {
			window->Draw(*(sprites[i]));
		}
		
		// Update the window
		window->Display();
	}
}

Interface& ZombieGame::GetInterface() {
    return *interface;
}

void ZombieGame::SetInterface(Interface* myInterface) {
    interface = myInterface;
}
