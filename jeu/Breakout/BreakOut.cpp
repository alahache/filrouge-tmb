#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

#include "BreakOut.h"

#include "Balle.h"
#include "Barre.h"
#include "Brique.h"

#define MAX_BRIQUES 54
#define BRIQUES_PER_LINE 9

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
	if (!imgBackground->LoadFromFile("bg.png"))
		//return EXIT_FAILURE;
		std::cout << "ERREUR: chargement de l'image";
	sprBackground = new sf::Sprite(*imgBackground);
	sprBackground->Move(0, 0);

	//Chargement de la barre
	imgBarre = new sf::Image();
	if (!imgBarre->LoadFromFile("wood.png"))
		//return EXIT_FAILURE;
		std::cout << "ERREUR: chargement de l'image";
	barre = new Barre(imgBarre, this);
	AddSprite(barre);

	//Chargement de la balle
	imgBalle = new sf::Image();
	if (!imgBalle->LoadFromFile("balle.png"))
		std::cout << "ERREUR: chargement de l'image";
	balle = new Balle(imgBalle, this);
	AddSprite(balle);
	
	//Chargement des briques
	imgBrique = new sf::Image();
	if (!imgBrique->LoadFromFile("feuille.png"))
		std::cout << "ERREUR: chargement de l'image";
	brique.resize(MAX_BRIQUES);
	for(int i=0; i<MAX_BRIQUES; i++) {
	    Brique* uneBrique = new Brique(imgBrique, 60 + i%BRIQUES_PER_LINE*(imgBrique->GetWidth()+25), 
	                                    40 + i/BRIQUES_PER_LINE*(imgBrique->GetHeight()+25), this, 1);
    	AddSprite(uneBrique);
    	brique[i] = uneBrique;
	}

	// Font
	font = new sf::Font();
	if (!font->LoadFromFile("arial.ttf"))
		//return EXIT_FAILURE;
		std::cout << "ERREUR: chargement de la font";
	text = new sf::String("Score :", *font, 20);
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

void BreakOut::Lost() {
    isGameOn = false;
}

void BreakOut::initGame() {
    dynamic_cast<Balle*>(balle)->Init();
    for(int i=0; i<MAX_BRIQUES; i++)
        dynamic_cast<Brique*>(brique[i])->Init();
    isGameOn = true;
    first = false;
    haveWon = false;
    score=0;
}

void BreakOut::Run() {

	initGame();
	isGameOn = false;
	first = true;

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
		
		int score= 0;
		
		if(isGameOn) {
		
			// Update all sprites :
			for(unsigned int i=0; i<sprites.size(); i++) {
				sprites[i]->Update();
			}
			
			score++;
		}
		
		// Clear screen
		window->Clear(sf::Color(255, 255, 255));
		
		// Draw the background
		window->Draw(*sprBackground);
		
		
		score = MAX_BRIQUES + 2; // + les deux autres sprites...
		
		// Draw all the objects on the window
		for(unsigned int i=0; i<sprites.size(); i++) {
		    if(dynamic_cast<Brique*>(sprites[i]) == NULL || dynamic_cast<Brique*>(sprites[i])->IsLiving()) {//N'affiche pas les briques touchees
			    window->Draw(*(sprites[i]));
			    score--;
		    }
		}
		
		if(score == MAX_BRIQUES) {
		    haveWon = true;
		    isGameOn = false;
		}
		
		// change text :
		std::string txt(" Score : ");
		{
			std::ostringstream os;
			os << score;
			if(!isGameOn) {
				if(!first) {
					if(haveWon) {
					    os << " Gagne !!! ";
					} else {
					    os << " Perdu !!! ";
					}
				}
		    	os << "Appuyez sur entree pour commencer.";
			}
			txt += os.str();
		}
		text->SetText(txt);
		//String text(txt, font, 20);
		text->SetColor(sf::Color(255, 255, 255));
		
		// Draw the string
		window->Draw(*text);

		// Update the window
		window->Display();
	}
}

