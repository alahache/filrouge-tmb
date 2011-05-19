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

enum prochain { CLICK, TRACKING };

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
        float GetY();
        
        bool isMousePressed();
       
        void setMousePressed(bool isMousePressed);
        void monSuperThread();
        void miseAJour(); //Emulation de la webcam
        
        void afficherFenetre();
        void supprimerFenetre(); 
        
        IplImage* getImage() { return image; }
        
        void setH(int unH) { h = unH; }
        void setS(int unS) { s = unS; }
        void setV(int unV) { v = unV; }
        
        void setHClick(int unH) { hClick = unH; }
        void setSClick(int unS) { sClick = unS; }
        void setVClick(int unV) { vClick = unV; }
        
        prochain getNext() { return toChoose; }
        void setNext() 
        { 
			if(toChoose == CLICK) toChoose = TRACKING;
			else toChoose = CLICK;
		}
        
    private: 
		
		// Add to Circles, one for the tracking and one for the click. -- In Dev
		void addObjectsToVideo(IplImage* image, CvPoint objectNextPos, int nbPixels, CvPoint clickNextPos, int nbPixelsClick);
		
		// Transform the image into a two colored image, one color for the color we want to track, another color for the others colors
		// Modifie tout seul la position des ronds...
		void binarisation(IplImage* image, int *nbPixels, int *nbPixelsClick);
		
		int max(int a, int b) { return (a) > (b) ? (a) : (b); }
		int min(int a, int b) { return (a) < (b) ? (a) : (b); }  
		int abs(int x) { return (x) > 0 ? (x) : -(x); }
		int sign(int x) { return (x) > 0 ? 1 : -1; }
    
    // ----------------------------------------------------------------
    // Attributs
    
    
		// Position du point rouge.
		CvPoint objectPos;
        sf::RenderWindow* app;
        
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
        
        // Position du click et de son point.
        CvPoint clickPos;
        float xClick;
        float yClick;
        
        // Variable partagé pour dire si on est cliqué.
        bool *isPressed;
        int sharedIdisPressed;
        
        // Couleur du click.
        int hClick,sClick,vClick, toleranceClick;
        
        // Sémaphore pour isPressed.
        int semClick;
        
        // Pour savoir qu'est ce qu'on choisi au prochain clic.
        // Prend ses valeurs dans l'énumération PROCHAIN.
        prochain toChoose;
		
};

#endif
