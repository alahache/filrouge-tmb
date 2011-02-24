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
 
// Step mooving for object min & max
#define STEP_MIN 5
#define STEP_MAX 100

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
       
        void setMousePressed(bool isMousePressed);
        void monSuperThread();
        void miseAJour(); //Emulation de la webcam
        
        void afficherFenetre();
        void supprimerFenetre(); 
        
        inline IplImage* getImage() { return image; }
        
        void setH(int unH) { h = unH; }
        void setS(int unS) { s = unS; }
        void setV(int unV) { v = unV; }
        
        // Temporaire, fais des getters après...
        
    private: 
		
		// Add a circle on the video that fellow your colored object
		void addObjectToVideo(IplImage* image, CvPoint objectNextPos, int nbPixels);
		// Transform the image into a two colored image, one color for the color we want to track, another color for the others colors
		CvPoint binarisation(IplImage* image, int *nbPixels);
		
		int max(int a, int b) { return (a) > (b) ? (a) : (b); }
		int min(int a, int b) { return (a) < (b) ? (a) : (b); }  
		int abs(int x) { return (x) > 0 ? (x) : -(x); }
		int sign(int x) { return (x) > 0 ? 1 : -1; }
    
    // ----------------------------------------------------------------
    // Attributs
    
    
		CvPoint objectPos;
        sf::RenderWindow* app;
        
        bool isPressed;
        
        float *x;
		float *y;
		
		int sharedIdX;
		int sharedIdY;
        
        CvCapture *capture;
		
		int sem; // sémaphore
		int pidVideo;
		
		IplImage *image;
        int h,s,v, tolerance;
        
        int sharedIdAffiche;
        // Pour plus de facilité, mais utilisé comme un bool
        int *affiche;
        int semAffiche;
		
};

#endif
