
#include "Game.h"

#include <iostream>

//================================================================ PUBLIC

Game::Game(unsigned int w, unsigned int h, std::string title) {
	window = new sf::RenderWindow(sf::VideoMode(w, h), title.c_str());
    window->SetFramerateLimit(35);
    
    // Load the game ressources :
    //loadRessources();
    
    // Initialize the game :
    //initGame();
}

Game::~Game() {
	delete window;
	for(int i=0; i<sprites.size(); i++)
		delete sprites[i];
}

void Game::AddSprite(GameSprite* pSpr) {
	sprites.push_back(pSpr);
}

GameSprite* Game::GetSprite(unsigned int i) {
	return sprites[i];
}

unsigned int Game::NbSprites() {
	return sprites.size();
}
