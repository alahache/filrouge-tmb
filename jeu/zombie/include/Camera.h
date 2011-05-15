#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include "GameSprite.h"

enum CameraState{STOP, FOLLOW};

class Camera {
    public:
    	
    	// =================================== Constructors / Destructor
        Camera(sf::RenderWindow* _window, sf::Sprite* _sprbackground);
        ~Camera();
        
        // =================================== Public methods
        void GoTo(float x, float y);
        void Move(float offsetX, float offsetY);
        void Follow(GameSprite* sprite);
        void Stop();
        void Update();
        sf::FloatRect GetRect();
    
    protected:
        
		// =================================== Attributes
		CameraState state;
		sf::RenderWindow* window;
		sf::Sprite* sprbackground;
		sf::View* view;
		GameSprite* followedSprite;
};

#endif
