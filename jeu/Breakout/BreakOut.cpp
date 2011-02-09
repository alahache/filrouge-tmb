#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

#include "BreakOut.h"

#include "Balle.h"
#include "Barre.h"

BreakOut::BreakOut()
	: Game(SCREEN_W, SCREEN_H, "BreakOut") {
	
	loadRessources();
	
}

BreakOut::~BreakOut() {
	delete imgBarre;
	delete imgBalle;
	delete imgBackground;
	delete sprBackground;
	delete text;
	delete font;
}

void BreakOut::loadRessources() {

	//Chargement du Background
	imgBackground = new sf::Image();
	if (!imgBackground->LoadFromFile("Bg.png"))
		//return EXIT_FAILURE;
		std::cout << "ERREUR: chargement de l'image";
	sprBackground = new sf::Sprite(*imgBackground);
	sprBackground->Move(0, 0);

	//Chargement de la barre
	imgBarre = new sf::Image();
	if (!imgBarre->LoadFromFile("barre.png"))
		//return EXIT_FAILURE;
		std::cout << "ERREUR: chargement de l'image";
	barre = new Barre(imgBarre, this);
	AddSprite(barre);

	//Chargement de la balle
	imgBalle = new sf::Image();
	if (!imgBalle->LoadFromFile("img.png"))
		std::cout << "ERREUR: chargement de l'image";
	balle = new Balle(imgBalle, this);
	AddSprite(balle);

	// Font
	font = new sf::Font();
	if (!font->LoadFromFile("arial.ttf"))
		//return EXIT_FAILURE;
		std::cout << "ERREUR: chargement de la font";
	text = new sf::String("Score :", *font, 30);
	text->SetColor(sf::Color(0, 0, 0));
}


GameSprite& BreakOut::GetBarre() {
	return *barre;
}

GameSprite& BreakOut::GetBalle() {
	return *barre;
}

sf::Sprite& BreakOut::GetBackground() {
	return *sprBackground;
}

Interface& BreakOut::GetInterface() {
    return *interface;
}

void BreakOut::SetInterface(Interface* myInterface) {
    interface = myInterface;
}

void BreakOut::initGame() {
    isGameOn = true;
    score=0;
}

void BreakOut::Run() {

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
		
			// Update all sprites :
			for(int i=0; i<sprites.size(); i++) {
				sprites[i]->Update();
			}
		}
		
		// change text :
		std::string txt("Score : ");
		{
			std::ostringstream os;
			os << score;
			if(!isGameOn) {
		    	os << " Perdu !! Appuyer sur entrée pour recommencer.";
			}
			txt += os.str();
		}
		text->SetText(txt);

		// Clear screen
		window->Clear(sf::Color(255, 255, 255));
		
		// Draw the background
		window->Draw(*sprBackground);
		
		// Draw all the objects on the window
		for(int i=0; i<sprites.size(); i++) {
			window->Draw(*(sprites[i]));
		}
		
		// Draw the string
		window->Draw(*text);

		// Update the window
		window->Display();
	}
}

