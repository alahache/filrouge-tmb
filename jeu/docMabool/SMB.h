#ifndef SMB_H
#define SMB_H

#include <SFML/Graphics.hpp>


class SMB {
    public:

    	static const int SCREEN_W = 800;
        static const int SCREEN_H = 600;

        SMB();
        ~SMB();

        void Run();

        //void SetInterface(Interface* myInterface);

        sf::RenderWindow* GetRenderWindow(); //Emulation de la webcam


    private:
        void loadRessources();
        //void initGame();

        bool hitTest(sf::Sprite* sprite, sf::Event event );
        bool collisionTest(sf::Sprite* sprite, sf::Sprite* sprite2);


        //Interface* interface;

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

        /*
        sf::Font* font;
        sf::String* text;
        */
        sf::RenderWindow* app;

        bool isGameOn;
};

#endif

