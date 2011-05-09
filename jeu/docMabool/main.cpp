#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;


bool hitTest (Sprite sprite, Event event )
{
    Rect<int> ObjectRect(sprite.GetPosition().x,
                         sprite.GetPosition().y,
                         sprite.GetPosition().x+ sprite.GetSize().x,
                         sprite.GetPosition().y+ sprite.GetSize().y);

     if(ObjectRect.Contains(event.MouseButton.X, event.MouseButton.Y))
     {
         return true;
     }
         return false;
}



bool collisionTest(Sprite sprite, Sprite sprite2)
{
    //const IntRect & a;
    Rect<int> a(sprite.GetPosition().x,
                         sprite.GetPosition().y,
                         sprite.GetPosition().x+ sprite.GetSize().x,
                         sprite.GetPosition().y+ sprite.GetSize().y);

    Rect<int> b(sprite2.GetPosition().x,
                         sprite2.GetPosition().y,
                         sprite2.GetPosition().x+ sprite2.GetSize().x,
                         sprite2.GetPosition().y+ sprite2.GetSize().y);


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





int main()
{
    // Fenêtre de rendu
    RenderWindow app(VideoMode(600, 600, 32), "TMB Game !");

    Font font;
    // Chargement à partir d'un fichier sur le disque
    if(!font.LoadFromFile("arial.ttf"))
    {
        // Traitement de l'erreur
    }

    int score = 0;

    string txt("Score : ");
    {
        std::ostringstream os;
        os << score;
        txt += os.str();
    }

    String text(txt, font, 20);


    Image imageParcours;

    Image imageBall;
    Image imageBall2;
    Image imageBall3;
    Image imageBall4;

    Sprite spriteParcours;
    Sprite spriteBall;
    Sprite spriteBall2;
    Sprite spriteBall3;
    Sprite spriteBall4;

    // Positions de la souris :
    int MouseX;
    int MouseY;

    // Positions initiales des sprite :
    int XBall = 100;
    int YBall = 0;

    int XBall2 = 70;
    int YBall2 = 0;

    int XBall3 = 400;
    int YBall3 = 0;

    int XBall4 = 250;
    int YBall4 = 0;


    const Input & input = app.GetInput(); // input : référence constante


    if (!imageParcours.LoadFromFile("terre.png")) // Si le chargement du fichier a échoué
    {
        cout<<"Erreur durant le chargement du parcorus !"<<endl;
        return EXIT_FAILURE; // On ferme le programme
    }
    else // Si le chargement de l'image a réussi
    {
        spriteParcours.SetImage(imageParcours);
    }

    if (!imageBall.LoadFromFile("ballRed.png")) // Si le chargement du fichier a échoué
    {
        cout<<"Erreur durant le chargement de la balle !"<<endl;
        return EXIT_FAILURE; // On ferme le programme
    }
    else // Si le chargement de l'image a réussi
    {
        spriteBall.SetImage(imageBall);
    }


    if (!imageBall2.LoadFromFile("ballRed.png")) // Si le chargement du fichier a échoué
    {
        cout<<"Erreur durant le chargement de la balle !"<<endl;
        return EXIT_FAILURE; // On ferme le programme
    }
    else // Si le chargement de l'image a réussi
    {
        spriteBall2.SetImage(imageBall2);
    }


    if (!imageBall3.LoadFromFile("ballRed.png")) // Si le chargement du fichier a échoué
    {
        cout<<"Erreur durant le chargement de la balle !"<<endl;
        return EXIT_FAILURE; // On ferme le programme
    }
    else // Si le chargement de l'image a réussi
    {
        spriteBall3.SetImage(imageBall3);
    }


    if (!imageBall4.LoadFromFile("ballRed.png")) // Si le chargement du fichier a échoué
    {
        cout<<"Erreur durant le chargement de la balle !"<<endl;
        return EXIT_FAILURE; // On ferme le programme
    }
    else // Si le chargement de l'image a réussi
    {
        spriteBall4.SetImage(imageBall4);
    }



    // Boucle principale
    while (app.IsOpened())
    {
        Event event;
        while (app.GetEvent(event))
        {
            // Fenêtre fermée : on quitte
            if (event.Type == Event::Closed)
                app.Close();

            /*if (Event::MouseMoved)
            {
                MouseX = input.GetMouseX();
                MouseY = input.GetMouseY();
                cout << "X : " << MouseX << ", Y : " << MouseY << endl;
                spriteBall.SetPosition(MouseX,MouseY);
            }*/

            // Comment gèrer le Drag And Drop ????
            /*if(event.Type == Event::MouseButtonPressed)
            {
                if(event.Type == Event::MouseButtonReleased)
                {
                    MouseX = input.GetMouseX();
                    MouseY = input.GetMouseY();
                    cout << "X : " << MouseX << ", Y : " << MouseY << endl;
                    spriteBall.SetPosition(MouseX,MouseY);
                }
            }*/


            // Si on clicke sur un sprite :
            if(Event::MouseButtonPressed)
            {
                if(hitTest(spriteBall,event))
                {
                    XBall = rand()%530;
                    YBall = -150;
                    spriteBall.SetPosition(XBall,YBall);
                    score += 5;
                }
                if(hitTest(spriteBall2,event))
                {
                    XBall2 = rand()%530;
                    YBall2 =  -150;
                    spriteBall2.SetPosition(XBall2,YBall2);
                    score += 5;
                }
                if(hitTest(spriteBall3,event))
                {
                    XBall3 = rand()%530;
                    YBall3 =  -150;
                    spriteBall3.SetPosition(XBall3,YBall3);
                    score += 5;
                }
                if(hitTest(spriteBall4,event))
                {
                    XBall4 = rand()%530;
                    YBall4 =  -150;
                    spriteBall4.SetPosition(XBall4,YBall4);
                    score += 5;
                }
            }

        }

        // Efface l'écran (remplissage avec du noir)
        app.Clear();

        // On met à jour et on affiche le score :
        txt.clear();
        txt += ("Score : ");
        {
            std::ostringstream os;
            os << score;
            txt += os.str();
        }
        text.SetText(txt);
        app.Draw(text);

        // Set Earth Position :
        spriteParcours.SetPosition(-20,440);
        app.Draw(spriteParcours);

        app.Draw(spriteBall);
        app.Draw(spriteBall2);
        app.Draw(spriteBall3);
        app.Draw(spriteBall4);

        // Speed :
        YBall  += 3;
        YBall2 += 2;
        YBall3 += 3;
        YBall4 += 2;

        // Collision Tests :
        // if(YBall > 600)
        if(collisionTest(spriteParcours,spriteBall))
        {
            XBall = rand()%530;
            YBall = 0;
            spriteBall.SetPosition(XBall,YBall);
            score = 0;

        }

        if(collisionTest(spriteParcours,spriteBall2))
        {
            XBall2 = rand()%530;
            YBall2 = 0;
            spriteBall2.SetPosition(XBall2,YBall2);
            score = 0;
        }

        if(collisionTest(spriteParcours,spriteBall3))
        {
            XBall3 = rand()%530;
            YBall3 = 0;
            spriteBall3.SetPosition(XBall3,YBall3);
            score = 0;
        }

        if(collisionTest(spriteParcours,spriteBall4))
        {
            XBall4 = rand()%530;
            YBall4 = 0;
            spriteBall4.SetPosition(XBall4,YBall4);
            score = 0;
        }


        // Position Initialisation :
        spriteBall.SetPosition(XBall,YBall);
        spriteBall2.SetPosition(XBall2,YBall2);
        spriteBall3.SetPosition(XBall3,YBall3);
        spriteBall4.SetPosition(XBall4,YBall4);

        // Affichage du contenu de la fenêtre à l'écran
        app.Display();


        // On limite à 60 images par secondes :
        app.SetFramerateLimit(60);

    }

    return EXIT_SUCCESS;
}
