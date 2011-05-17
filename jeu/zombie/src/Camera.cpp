
#include "Camera.h"

//================================================================ PUBLIC

Camera::Camera(sf::RenderWindow* _window, sf::Sprite* _sprbackground)
	: window(_window), sprbackground(_sprbackground)
{
	view = new sf::View(sf::FloatRect(0, 0, window->GetWidth(), window->GetHeight()));
	window->SetView(*view);
	state=STOP;
}

Camera::~Camera() {
	delete view;
}

void Camera::GoTo(float x, float y) {
	if(x - window->GetWidth()/2 <= 0) x = window->GetWidth()/2;
	else if(x + window->GetWidth()/2 > sprbackground->GetSize().x) x = sprbackground->GetSize().x - window->GetWidth()/2;
	if(y - window->GetHeight()/2 <= 0) y = window->GetHeight()/2;
	else if(y + window->GetHeight()/2 > sprbackground->GetSize().y) y = sprbackground->GetSize().y - window->GetHeight()/2;
	view->SetCenter(x, y);
}

void Camera::Move(float offsetX, float offsetY) {
	if(state != STOP) return;
	GoTo(view->GetCenter().x + offsetX, view->GetCenter().y + offsetY);
}

void Camera::Follow(GameSprite* sprite) {
	followedSprite = sprite;
	state = FOLLOW;
}

void Camera::Stop() {
	state = STOP;
}

void Camera::Update() {
	switch(state)
	{
		case FOLLOW:
			GoTo(followedSprite->X() + followedSprite->Width()/2, followedSprite->Y() + followedSprite->Height()/2);
			break;
		case STOP:
			break;
	}
}

sf::FloatRect Camera::GetRect() {
	return view->GetRect();
}
