#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "ZombieGame.h"

using namespace std;

ZombieGame::ZombieGame()
	: Game(SCREEN_W, SCREEN_H, "ZombieGame") {
	
	loadRessources();
	srand(time(NULL));
	isGameOn = false;
	gameover = false;
}

ZombieGame::~ZombieGame() {
	delete camera;
	delete imgzombie;
	delete imgterrain;
	delete sprterrain;
	delete catapulte;
	delete imgbombe;
	delete sprbombe;
	delete imgexplosion;
	delete sprexplosion;
}

void ZombieGame::loadRessources() {
	catapulte = new Catapulte(this, 1550, 260, 1633, 260);
	
	imgexplosion = new sf::Image();
	if (!imgexplosion->LoadFromFile("images/explosion.png"))
		std::cout << "ERREUR: chargement de l'image";
	sprexplosion = new Explosion(imgexplosion, this);
	
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
	sprbombe = new Bombe(imgbombe, this, catapulte, imgterrain, sprexplosion);
	AddSprite(sprbombe);
	
	imgzombie = new sf::Image();
	if (!imgzombie->LoadFromFile("images/zombie.png"))
		std::cout << "ERREUR: chargement de l'image";
	
	camera = new Camera(window, sprfond);
}

void ZombieGame::initGame() {
	isGameOn = true;
	/*for(unsigned int i = 0; i<sprzombies.size(); i++) {
	    RemoveSprite(sprzombies[i]);
	}
	sprzombies.clear();
	sprzombies.push_back(new Zombie(imgzombie, imgterrain));
    AddSprite(sprzombies.back());*/
}

sf::Vector2f ZombieGame::GetMousePosition() {
	sf::Vector2f pos;
	pos.x = interface->GetX()*SCREEN_W + camera->GetRect().Left;
	pos.y = interface->GetY()*SCREEN_H + camera->GetRect().Top;
	return pos;
}

void ZombieGame::GameOver() {
	isGameOn = false;
	gameover = true;
}

void ZombieGame::Run() {

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
				if(Event.Key.Code == sf::Key::Return) {
			    	isGameOn = !isGameOn;
				}
			}
		}
		
		if(gameover) {
			//window->Close();
		}

		// Clear screen
		window->Clear(sf::Color(255, 255, 255));
		
		// Draw background
		window->Draw(*sprfond);
		
		// Draw terrain
		window->Draw(*sprterrain);
		
		if(isGameOn) {
		
			// Set camera
			if(interface->GetX() >= 0.7)
				camera->Move(10, 0);
			else if(interface->GetX() <= 0.3)
				camera->Move(-10, 0);
			camera->Update();
		
			if(rand()%500 <= 1) {
			    //for(unsigned int i = 0; i<4+rand()%4; i++) {
                    sprzombies.push_back(new Zombie(imgzombie, imgterrain));
	                AddSprite(sprzombies.back());
                //}
			    
			}
			
			// Update all sprites :
			for(int i=0; i<sprites.size(); i++) {
				AnimatedSprite* a = dynamic_cast<AnimatedSprite*>(sprites[i]);
				if(a != NULL) a->Animate();
				sprites[i]->Update();
			}
			
			// Delete all killed zombies :
			vector<Zombie*>::iterator it=sprzombies.begin();
			while(it!=sprzombies.end())
			{
				if((*it)->IsDead())
				{
					RemoveSprite(*it);
					sprzombies.erase(it);
				}
				else
				{
					it++;
				}
			}
			
		}
		
		// Draw all the objects on the window
		for(int i=0; i<sprites.size(); i++) {
			window->Draw(*(sprites[i]));
		}
		
		// Draw the mouse position :
		sf::Vector2f mouse_pos = GetMousePosition();
		sf::Shape circle = sf::Shape::Circle(mouse_pos.x, mouse_pos.y, 10, sf::Color::Red);
		window->Draw(circle);
		
		// Update the window
		window->Display();
	}
}

Interface& ZombieGame::GetInterface() {
    return *interface;
}

Camera& ZombieGame::GetCamera() {
    return *camera;
}

void ZombieGame::SetInterface(Interface* myInterface) {
    interface = myInterface;
}
