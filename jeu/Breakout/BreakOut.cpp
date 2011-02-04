#include <sstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>

#include "BreakOut.h"


BreakOut::BreakOut() {
    app = new sf::RenderWindow(sf::VideoMode(SCREEN_W, SCREEN_H), "Break Out - Demo pour le projet de Fil Rouge 3IF 2011");
    app->SetFramerateLimit(35);
    
    loadRessources();
}

BreakOut::~BreakOut() {
    delete sprBarre;
    delete imgBarre;
    delete text;
    delete font;
    delete sprBackground;
    delete imgBackground;
    delete app;
    delete balle;
}

sf::RenderWindow* BreakOut::GetRenderWindow() { //Emulation de la webcam
    return app;
}

sf::Sprite* BreakOut::GetBarre() {
	return sprBarre;
}

sf::Sprite* BreakOut::GetBackground() {
	return sprBackground;
}

void BreakOut::SetInterface(Interface* myInterface) {
    interface = myInterface;
}

void BreakOut::initGame() {
    isGameOn = true;
    score=0;
}

void BreakOut::loadRessources() {
    //Chargement de la barre
    imgBarre = new sf::Image();
    if (!imgBarre->LoadFromFile("barre.png"))
        //return EXIT_FAILURE;
        std::cout << "ERREUR: chargement de l'image";
    sprBarre = new sf::Sprite(*imgBarre);
    
    sprBarre->Move(400, 530);
    
    //Chargement du Background
    imgBackground = new sf::Image();
    if (!imgBackground->LoadFromFile("Bg.png"))
        //return EXIT_FAILURE;
        std::cout << "ERREUR: chargement de l'image";
    sprBackground = new sf::Sprite(*imgBackground);
    sprBackground->Move(0, 0);
    
    //Chargement de la balle
    balle = new Balle(this);
    
    // Font
    font = new sf::Font();
    if (!font->LoadFromFile("arial.ttf"))
        //return EXIT_FAILURE;
        std::cout << "ERREUR: chargement de la font";
    text = new sf::String("Score :", *font, 30);
    text->SetColor(sf::Color(0, 0, 0));
}

void BreakOut::Run() {
    initGame();
    
    // Start the game loop
    while (app->IsOpened())
    {
        if(isGameOn) score++;
        // Process events
        sf::Event Event;
        while (app->GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
            app->Close();
            
            if(Event.Type == sf::Event::KeyPressed) {
                if(!isGameOn && Event.Key.Code == sf::Key::Return) {
                    initGame();
                }
            }
        }
        
        
        // Maj barre :
        int x = (int)(interface->GetX()*app->GetWidth());
        x -= (int)(sprBarre->GetSize().x/2);

        if(isGameOn) {
            //TODO: Mettre a jour le jeu
            
            sprBarre->SetX(x);
        }
        
        // Maj balle :
        balle->majPositions();

        //AFFICHAGE
        
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
        app->Clear(sf::Color(255, 255, 255));
        app->Draw(*sprBackground);
        
        //TODO: Ici afficher tous les objets
        
        // Draw the sprite
        app->Draw(*sprBarre);
        
        // Draw the ball
        app->Draw(*(balle->GetSprite()));

        // Draw the string
        app->Draw(*text);

        // Update the window
        app->Display();
    }
}

