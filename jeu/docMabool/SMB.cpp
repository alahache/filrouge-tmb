#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

#include "SMB.h"


SMB::SMB()
{
    app = new RenderWindow(VideoMode(SCREEN_W, SCREEN_H), "Shoot My Ball - Demo pour le projet de Fil Rouge 3IF 2011");
    app->SetFramerateLimit(35);

    loadRessources();
}


SMB::~SMB()
{
    delete imageBackground;
    delete spriteBackground;

    delete imageBall;
    delete spriteBall;

    delete imageBall2;
    delete spriteBall2;

    delete imageBall3;
    delete spriteBall3;

    delete imageBall4;
    delete spriteBall4;
    delete app;
}

sf::RenderWindow* SMB::GetRenderWindow() { //Emulation de la webcam
    return app;
}

void SMB::SetInterface(Interface* myInterface)
{
	interface = myInterface;
}



void SMB::loadRessources()
{
    // Chargement des images :
    imageBackground = new sf::Image();
    if (!imageBackground->LoadFromFile("terre2.png"))
    {
        cout<<"Erreur durant le chargement du parcorus !"<<endl;
        return;
    }
    else
    {
        spriteBackground = new Sprite(*imageBackground);
    }

    imageBall = new sf::Image();
    if (!imageBall->LoadFromFile("ballRed.png"))
    {
        cout<<"Erreur durant le chargement de la balle !"<<endl;
        return;
    }
    else
    {
        spriteBall = new Sprite(*imageBall);
    }

    imageBall2 = new sf::Image();
    if (!imageBall2->LoadFromFile("ballRed.png"))
    {
        cout<<"Erreur durant le chargement de la balle !"<<endl;
        return;
    }
    else
    {
        spriteBall2 = new Sprite(*imageBall2);
    }

    imageBall3 = new sf::Image();
    if (!imageBall3->LoadFromFile("ballRed.png"))
    {
        cout<<"Erreur durant le chargement de la balle !"<<endl;
        return;
    }
    else
    {
        spriteBall3 = new Sprite(*imageBall3);
    }

    imageBall4 = new sf::Image();
    if (!imageBall4->LoadFromFile("ballRed.png"))
    {
        cout<<"Erreur durant le chargement de la balle !"<<endl;
        return;
    }
    else
    {
        spriteBall4 = new Sprite(*imageBall4);
    }
    
    
}



bool SMB::hitTest(Sprite* sprite)
{
	sf::Vector2f pos = GetMousePosition();
    Rect<float> ObjectRect(sprite->GetPosition().x,
                         sprite->GetPosition().y,
                         sprite->GetPosition().x+ sprite->GetSize().x,
                         sprite->GetPosition().y+ sprite->GetSize().y);

     if(ObjectRect.Contains(pos.x ,pos.y))
     {
         return true;
     }
         return false;
}



bool SMB::collisionTest(Sprite* sprite, Sprite* sprite2)
{
    Rect<int> a(sprite->GetPosition().x,
                         sprite->GetPosition().y,
                         sprite->GetPosition().x+ sprite->GetSize().x,
                         sprite->GetPosition().y+ sprite->GetSize().y);

    Rect<int> b(sprite2->GetPosition().x,
                         sprite2->GetPosition().y,
                         sprite2->GetPosition().x+ sprite2->GetSize().x,
                         sprite2->GetPosition().y+ sprite2->GetSize().y);


    if (a.Bottom <= b.Top)
        return false;
    if (a.Top >= b.Bottom)
        return false;
    if (a.Right <= b.Left)
        return false;
    if (a.Left >= b.Right)
        return false;

    return true;
}


sf::Vector2f SMB::GetMousePosition() {
	sf::Vector2f pos;
	pos.x = interface->GetX()*SCREEN_W;
	pos.y = interface->GetY()*SCREEN_H;
	return pos;
}



void SMB::Run()
{
    Font font;
    // Chargement à partir d'un fichier sur le disque
    if(!font.LoadFromFile("arial.ttf"))
    {
        // Traitement de l'erreur
        cout << "Erreur chargement de la police !" << endl;
    }

    int score = 0;
    bool isGameOn = false;

    string txt("Score : ");
    {
        std::ostringstream os;
        os << score;
        txt += os.str();
    }

    String text(txt, font, 20);

    // Positions initiales des sprite :
    int XBall = 100;
    float YBall = 0;

    int XBall2 = 70;
    float YBall2 = 0;

    int XBall3 = 400;
    float YBall3 = 0;

    int XBall4 = 250;
    float YBall4 = 0;

    // Boucle principale
    while (app->IsOpened())
    {
		
        Event event;
        while (app->GetEvent(event))
        {
            // Fenêtre fermée : on quitte
            if (event.Type == Event::Closed)
                app->Close();
            
            // Mode Pause :    
            if(event.Type == sf::Event::KeyPressed) {
				if(!isGameOn) {
			    	isGameOn = true;
				} else {
					isGameOn = false;
				}
			}
			

        }
        
	if(!isGameOn) {
        // Efface l'écran (remplissage avec du noir)
        app->Display();
	}
	
		app->Clear();
        // On met à jour et on affiche le score :
        txt.clear();
        txt += ("Score : ");
        {
            std::ostringstream os;
            os << score;
            txt += os.str();
        }
        text.SetText(txt);
        app->Draw(text);

        // Set Earth Position :
        spriteBackground->SetPosition(0,440);
        app->Draw(*spriteBackground);

        app->Draw(*spriteBall);
        app->Draw(*spriteBall2);
        app->Draw(*spriteBall3);
        app->Draw(*spriteBall4);

		
		if(isGameOn) {
        // Speed :
        YBall  += 1.7;
        YBall2 += 1.1;
        YBall3 += 1.6;
        YBall4 += 1.3;
		}
		
        // Collision Tests :
        if(collisionTest(spriteBackground,spriteBall))
        {
            XBall = rand()%530;
            YBall = -150;
            spriteBall->SetPosition(XBall,YBall);
            score = 0;

        }

        if(collisionTest(spriteBackground,spriteBall2))
        {
            XBall2 = rand()%530;
            YBall2 = -150;
            spriteBall2->SetPosition(XBall2,YBall2);
            score = 0;
        }

        if(collisionTest(spriteBackground,spriteBall3))
        {
            XBall3 = rand()%530;
            YBall3 = -150;
            spriteBall3->SetPosition(XBall3,YBall3);
            score = 0;
        }

        if(collisionTest(spriteBackground,spriteBall4))
        {
            XBall4 = rand()%530;
            YBall4 = -150;
            spriteBall4->SetPosition(XBall4,YBall4);
            score = 0;
        }


        // Position Initialisation :
        spriteBall->SetPosition(XBall,YBall);
        spriteBall2->SetPosition(XBall2,YBall2);
        spriteBall3->SetPosition(XBall3,YBall3);
        spriteBall4->SetPosition(XBall4,YBall4);
        
        sf::Shape cursor = sf::Shape::Circle(GetMousePosition().x,GetMousePosition().y,10,sf::Color::Red);
        app->Draw(cursor);
        
        
        // On test le click :
        // Si on clicke sur un sprite :
		if(interface->isMousePressed())
		{
			if(hitTest(spriteBall))
			{
				XBall = rand()%730;
				YBall = -150;
				spriteBall->SetPosition(XBall,YBall);
				score += 5;
			}
			else if(hitTest(spriteBall2))
			{
				XBall2 = rand()%730;
				YBall2 =  -150;
				spriteBall2->SetPosition(XBall2,YBall2);
				score += 5;
			}
			else if(hitTest(spriteBall3))
			{
				XBall3 = rand()%730;
				YBall3 =  -150;
				spriteBall3->SetPosition(XBall3,YBall3);
				score += 5;
			}
			else if(hitTest(spriteBall4))
			{
				XBall4 = rand()%730;
				YBall4 =  -150;
				spriteBall4->SetPosition(XBall4,YBall4);
				score += 5;
			}
		}

        // Affichage du contenu de la fenêtre à l'écran
        app->Display();

        // On limite à 60 images par secondes :
        app->SetFramerateLimit(60);
	
    }
}


