#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

#include "ZombieGame.h"
#include "Zombie.h"
#include "Bombe.h"

using namespace std;

ZombieGame::ZombieGame()
	: Game(SCREEN_W, SCREEN_H, "ZombieGame") {
	
	loadRessources();
}

ZombieGame::~ZombieGame() {
	delete camera;
	delete imgzombie;
	delete imgterrain;
	delete sprterrain;
	delete catapulte;
	delete imgbombe;
}

void ZombieGame::loadRessources() {
	catapulte = new Catapulte(this, 1550, 260, 1633, 260);
		
	imgfond = new sf::Image();
	if (!imgfond->LoadFromFile("images/fond.png"))
		std::cout << "ERREUR: chargement de l'image";
	sprfond = new sf::Sprite(*imgfond);
	sprfond->Move(0, 0);
	
	imgterrain = new sf::Image();
	if (!imgterrain->LoadFromFile("images/terrain.png"))
		std::cout << "ERREUR: chargement de l'image";
	sprterrain = new sf::Sprite(*imgterrain);
	sprterrain->Move(0, 0);
	
	imgbombe = new sf::Image();
	if (!imgbombe->LoadFromFile("images/bombe.png"))
		std::cout << "ERREUR: chargement de l'image";
	sprbombe = new Bombe(imgbombe, this, catapulte);
	AddSprite(sprbombe);
	
	imgzombie = new sf::Image();
	if (!imgzombie->LoadFromFile("images/zombie.png"))
		std::cout << "ERREUR: chargement de l'image";
	sprzombie = new Zombie(imgzombie, imgterrain);
	AddSprite(sprzombie);
	
	camera = new Camera(window, sprfond);
}

void ZombieGame::initGame() {
	isGameOn = true;
}

sf::Vector2f ZombieGame::GetMousePosition() {
	sf::Vector2f pos;
	pos.x = interface->GetX()*SCREEN_W + camera->GetRect().Left;
	pos.y = interface->GetY()*SCREEN_H + camera->GetRect().Top;
	return pos;
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
		
		// Set camera
		if(interface->GetX() >= 0.7)
			camera->Move(10, 0);
		else if(interface->GetX() <= 0.3)
			camera->Move(-10, 0);
		camera->Update();

		// Clear screen
		window->Clear(sf::Color(255, 255, 255));
		
		// Draw background
		window->Draw(*sprfond);
		
		// Draw terrain
		window->Draw(*sprterrain);
		
		if(isGameOn) {
		
			sprzombie->Animate();
		
			// Update all sprites :
			for(int i=0; i<sprites.size(); i++) {
				sprites[i]->Update();
			}
		}
		
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
