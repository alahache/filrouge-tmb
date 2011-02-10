#ifndef INTERFACE
#define INTERFACE

#include <SFML/Graphics.hpp>
#include <opencv/highgui.h>
#include <opencv/cv.h>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/shm.h>

// Maths methods
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))  
#define abs(x) ((x) > 0 ? (x) : -(x))
#define sign(x) ((x) > 0 ? 1 : -1)
 
// Step mooving for object min & max
#define STEP_MIN 5
#define STEP_MAX 100

static struct sembuf reserver = {0, -1, 0};
static struct sembuf liberer = {0, 1, 0};

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
        void miseAJour(); //Emulation de la webcam
        
        
        // Temporaire, fais des getters après...
        IplImage *image;
        int h,s,v, tolerance;
        
    private: 
		
		// Add a circle on the video that fellow your colored object
		void addObjectToVideo(IplImage* image, CvPoint objectNextPos, int nbPixels);
		// Transform the image into a two colored image, one color for the color we want to track, another color for the others colors
		CvPoint binarisation(IplImage* image, int *nbPixels);
    
    // ----------------------------------------------------------------
    // Attributs
    
    
		CvPoint objectPos;
        sf::RenderWindow* app;
        
        bool isPressed;
        
        float *x;
		float *y;
        
        CvCapture *capture;
		
		int sem; // sémaphore
		int pidVideo;
		
};

#endif
