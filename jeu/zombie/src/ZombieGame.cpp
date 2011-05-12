#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

#include "ZombieGame.h"
#include "Zombie.h"

ZombieGame::ZombieGame()
	: Game(SCREEN_W, SCREEN_H, "ZombieGame") {
	
	loadRessources();
	offset=0;
}

ZombieGame::~ZombieGame() {

}

void ZombieGame::loadRessources() {
	imgzombie = new sf::Image();
	if (!imgzombie->LoadFromFile("images/zombie.png"))
		std::cout << "ERREUR: chargement de l'image";
	
	imgfond = new sf::Image();
	if (!imgfond->LoadFromFile("images/terrain.png"))
		std::cout << "ERREUR: chargement de l'image";
	
	sprfond = new sf::Sprite(*imgfond);
	sprfond->Move(0, 0);
	
	sprzombie = new Zombie(imgzombie, imgfond);
	AddSprite(sprzombie);
}

void ZombieGame::initGame() {
	window->SetView(sf::View(sf::FloatRect(offset, 0, offset+800, offset+600)));
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
		
			sprzombie->Animate();
		
			// Update all sprites :
			for(int i=0; i<sprites.size(); i++) {
				sprites[i]->Update();
			}
		}
		
		window->SetView(sf::View(sf::FloatRect(offset, 0, offset+800, 600)));

		// Clear screen
		window->Clear(sf::Color(255, 255, 255));
		
		window->Draw(*sprfond);
		
		// Draw all the objects on the window
		for(int i=0; i<sprites.size(); i++) {
			window->Draw(*(sprites[i]));
		}
		
		// Update the window
		window->Display();
		
		//offset++;
	}
}

Interface& ZombieGame::GetInterface() {
    return *interface;
}

void ZombieGame::SetInterface(Interface* myInterface) {
    interface = myInterface;
}
