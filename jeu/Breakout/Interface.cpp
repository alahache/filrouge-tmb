#include "Interface.h"

#include <SFML/Graphics.hpp>

Interface::Interface() {
    app = NULL;
}

Interface::Interface(sf::RenderWindow* myApp) {
    app = myApp;
}

Interface::~Interface() {

}

float Interface::GetX() {
    miseAJour();
    return x;
}

float Interface::Gety() {
   	miseAJour();
    return y;
}

bool Interface::isMousePressed() {
    miseAJour();
    return isPressed;
}

void Interface::setPosition(float posx, float posy) {
    x = posx;
    y = posy;
}

void Interface::setMousePressed(bool isMousePressed) {
    isPressed = isMousePressed;
}

void Interface::miseAJour() {
	if(app != NULL) {
		const sf::Input& input = app->GetInput();
		x = input.GetMouseX()/(float)app->GetWidth();
		y = input.GetMouseY()/(float)app->GetHeight();
		isPressed = input.IsMouseButtonDown(sf::Mouse::Left);
	}
}
