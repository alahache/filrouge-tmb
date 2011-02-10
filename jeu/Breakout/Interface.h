#ifndef INTERFACE
#define INTERFACE

#include <SFML/Graphics.hpp>
#include <opencv/highgui.h>
#include <opencv/cv.h>

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sys/sem.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>

// Maths methods
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))  
#define abs(x) ((x) > 0 ? (x) : -(x))
#define sign(x) ((x) > 0 ? 1 : -1)
 
// Step mooving for object min & max
#define STEP_MIN 5
#define STEP_MAX 100

struct sembuf reserver = {0, -1, 0};
struct sembuf liberer = {0, 1, 0};

// Get the color of the pixel where the mouse has clicked
void getObjectColor(int event, int x, int y, int flags, void *param = NULL);

class Interface {
    // --------------------------------------------------------------
    // Méthodes
    public:
    
        Interface(); //Constructeur normal
        Interface(sf::RenderWindow* myApp); //Constructeur pour l'émulation de la webcam
        ~Interface();
        
        float GetX();
        float Gety();
        
        bool isMousePressed();
        
        void setPosition(float x, float y);
        void setMousePressed(bool isMousePressed);
        void monSuperThread();
        
    private: 
		
		// Add a circle on the video that fellow your colored object
		void addObjectToVideo(IplImage* image, CvPoint objectNextPos, int nbPixels);
		// Transform the image into a two colored image, one color for the color we want to track, another color for the others colors
		CvPoint binarisation(IplImage* image, int *nbPixels);
    
    // ----------------------------------------------------------------
    // Attributs
    private:
        void miseAJour(); //Emulation de la webcam
        sf::RenderWindow* app;
        
        float x;
        float y;
        bool isPressed;
        
        IplImage *image;
        CvPoint objectPos;
        int h,s,v, tolerance;
        
        CvCapture *capture;
        
		// Next position of the object we overlay
		CvPoint objectNextPos;
		
		int sem; // sémaphore
		int pidVideo;
		
		
		
};

#endif
