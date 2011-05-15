#ifndef SMB_H
#define SMB_H

#include <SFML/Graphics.hpp>
#include "Interface.h"


class SMB {
    public:

    	static const int SCREEN_W = 800;
        static const int SCREEN_H = 600;

        SMB();
        ~SMB();

        void Run();
        sf::Vector2f GetMousePosition();

        void SetInterface(Interface* myInterface);

        sf::RenderWindow* GetRenderWindow(); //Emulation de la webcam


    private:
        void loadRessources();

        bool hitTest(sf::Sprite* sprite);
        bool collisionTest(sf::Sprite* sprite, sf::Sprite* sprite2);


        Interface* interface;

        sf::Image* imageBackground;
        sf::Sprite* spriteBackground;

        sf::Image* imageBall;
        sf::Sprite* spriteBall;

        sf::Image* imageBall2;
        sf::Sprite* spriteBall2;

        sf::Image* imageBall3;
        sf::Sprite* spriteBall3;

        sf::Image* imageBall4;
        sf::Sprite* spriteBall4;

        sf::RenderWindow* app;

        bool isGameOn;
};

#endif

