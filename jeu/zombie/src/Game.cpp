
#include "Game.h"

#include <iostream>

//================================================================ PUBLIC

Game::Game(unsigned int w, unsigned int h, std::string title, unsigned int _fps) : fps(_fps) {
	window = new sf::RenderWindow(sf::VideoMode(w, h), title.c_str());
    window->SetFramerateLimit(fps);
}

Game::~Game() {
	delete window;
	/*for(int i=0; i<sprites.size(); i++)
		delete sprites[i];*/
}

void Game::AddSprite(GameSprite* pSpr) {
	sprites.push_back(pSpr);
}

void Game::RemoveSprite(GameSprite* pSpr) {
	std::vector<GameSprite*>::iterator it = find(sprites.begin(), sprites.end(), pSpr);
	sprites.erase(it);
}

GameSprite* Game::GetSprite(unsigned int i) {
	return sprites[i];
}

unsigned int Game::NbSprites() {
	return sprites.size();
}

sf::RenderWindow* Game::GetWindow() {
	return window;
}

unsigned int Game::GetFps() {
	return fps;
}
