#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

#include "BreakOut.h"

#include "Balle.h"
#include "Barre.h"
#include "Brique.h"

#define MAX_BRIQUES 10

BreakOut::BreakOut()
	: Game(SCREEN_W, SCREEN_H, "BreakOut") {
	
	loadRessources();
	
}

BreakOut::~BreakOut() {
	delete imgBarre;
	delete imgBrique;
	delete imgBalle;
	delete imgBackground;
	delete sprBackground;
	//delete text;
	//delete font;
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
	
	//Chargement des briques
	imgBrique = new sf::Image();
	if (!imgBrique->LoadFromFile("brique.png"))
		std::cout << "ERREUR: chargement de l'image";
	brique.resize(MAX_BRIQUES);
	for(int i=0; i<MAX_BRIQUES; i++) {
	    Brique* uneBrique = new Brique(imgBrique, 100 + i*(imgBrique->GetWidth()+20), 200, this, 2);
    	AddSprite(uneBrique);
    	brique[i] = uneBrique;
	}

	// Font
	/*font = new sf::Font();
	if (!font->LoadFromFile("arial.ttf"))
		//return EXIT_FAILURE;
		std::cout << "ERREUR: chargement de la font";
	text = new sf::String("Score :", sf::Font::GetDefaultFont(), 30);
	text->SetColor(sf::Color(0, 0, 0));*/
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

void BreakOut::Lost() {
    isGameOn = false;
}

void BreakOut::initGame() {
    dynamic_cast<Balle*>(balle)->Init();
    for(int i=0; i<MAX_BRIQUES; i++)
        dynamic_cast<Brique*>(brique[i])->Init();
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
		/*std::string txt("Score : ");
		{
			std::ostringstream os;
			os << score;
			if(!isGameOn) {
		    	os << " Perdu !! Appuyer sur entrée pour recommencer.";
			}
			txt += os.str();
		}
		text->SetText(txt);*/

		// Clear screen
		window->Clear(sf::Color(255, 255, 255));
		
		// Draw the background
		window->Draw(*sprBackground);
		
		// Draw all the objects on the window
		for(int i=0; i<sprites.size(); i++) {
		    if(dynamic_cast<Brique*>(sprites[i]) == NULL || dynamic_cast<Brique*>(sprites[i])->IsLiving()) //N'affiche pas les briques touchees
			    window->Draw(*(sprites[i]));
		}
		
		// Draw the string
		//window->Draw(*text);

		// Update the window
		window->Display();
	}
}

