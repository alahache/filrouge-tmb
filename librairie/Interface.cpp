#include "Interface.h"

#include <iostream>

#define KEYX 5678
#define KEYY 5679
#define KEYAFFICHE 12349
#define KEYSEM 1234
#define KEYSEMAFFICHE 1235
#define KEYISPRESSED 1236
#define KEYSEMCLICK 1237

#define TOLERANCE 8

#define NBPIXELSMIN 10

#define SEUILAPPROCHE 0.05

#define ARRONDI 100000.0

using namespace std;

Interface::Interface() 
{
	
	pidVideo = 0;

    if ((sharedIdX = shmget(KEYX, sizeof(float), IPC_CREAT | 0666)) < 0) 
    {
		cerr << "shgetX" << endl;
    }
    
    if ((x = (float*)shmat(sharedIdX, NULL, 0)) == (float *) -1) 
    {
        cerr << "shmatX" << endl;
    }

    if ((sharedIdY = shmget(KEYY, sizeof(float), IPC_CREAT | 0666)) < 0) 
    {
		cerr << "shgetY" << endl;
    }
    
    if ((y = (float*)shmat(sharedIdY, NULL, 0)) == (float *) -1) 
    {
        cerr << "shmatY" << endl;
    }
    
    *x = -1;
    *y = -1;
    
    if ((sharedIdAffiche = shmget(KEYAFFICHE, sizeof(int), IPC_CREAT | 0666)) < 0) 
    {
		cerr << "shgetAffiche" << endl;
    }
    
    if ((affiche = (int*)shmat(sharedIdAffiche, NULL, 0)) == (int*)-1) 
    {
        cerr << "shmatAffiche" << endl;
    }
    
    *affiche = 1;
    
    if ((sharedIdisPressed = shmget(KEYISPRESSED, sizeof(bool), IPC_CREAT | 0666)) < 0) 
    {
		cerr << "shgetisPressed" << endl;
    }
    
    if ((isPressed = (bool*)shmat(sharedIdisPressed, NULL, 0)) == (bool*)-1) 
    {
        cerr << "shmatisPressed" << endl;
    }
    
    *isPressed = false;
    
     // Position du click et de son point.
	clickPos = cvPoint(-1, -1);
	xClick = -1;
	yClick = -1;
	
	// Couleur du click.
	hClick = 0;
	sClick = 0;
	vClick = 0;
	toleranceClick = TOLERANCE;
	
	// Sémaphore pour isPressed.
	int semClick;
	semClick = semget(KEYSEMCLICK, 1, IPC_CREAT);
	if (semClick<0) 
	{	
		cerr << "semClick Error" << endl;
	}
	else
	{
		semctl(semClick, 0, SETVAL, 1);
	} 
	
	toChoose = TRACKING;
    
	app = NULL;
	objectPos = cvPoint(-1, -1);
	h = 0; 
	s = 0;
	v = 0;
	tolerance = TOLERANCE;

	capture = cvCreateCameraCapture(200);

	// Check if the capture is ok
	if (!capture) 
	{
		cerr << "Can't initialize the video capture" << endl;
	}

	sem = semget(KEYSEM, 1, IPC_CREAT);
	if (sem<0) 
	{	
		cerr << "semAffiche Error" << endl;
	}
	else
	{
		semctl(sem, 0, SETVAL, 1);
	} 
	
	semAffiche = semget(KEYSEMAFFICHE, 1, IPC_CREAT);
	if (semAffiche<0) 
	{	
		cerr << "semAffiche Error" << endl;
	}
	else
	{
		semctl(semAffiche, 0, SETVAL, 1);
	} 

	pidVideo = fork();
	
	if (pidVideo == 0)
	{
		
		afficherFenetre();
		monSuperThread();
	}
	
}

Interface::Interface(sf::RenderWindow* myApp) 
{
	app = myApp;
}

Interface::~Interface()
{
	
	if (pidVideo !=0)
	{	
		if ( app == NULL)	
		{
			kill(pidVideo, SIGINT);
			waitpid(pidVideo, NULL, 0);
			
			if ( affiche )
			{
				// Destroy the windows we have created
				cvDestroyWindow("Test Color Tracking");
				cvDestroyWindow("Test Mask");
				cvDestroyWindow("Test Mask Click");
			}

			// Destroy the capture
			cvReleaseCapture(&capture);
			
			struct shmid_ds shmid;
			
			shmctl(sharedIdX, IPC_RMID, &shmid);
			shmdt(x);
			
			shmctl(sharedIdY, IPC_RMID, &shmid);
			shmdt(y);
			
			shmctl(sharedIdAffiche, IPC_RMID, &shmid);
			shmdt(affiche);
			semctl (semAffiche, 0, IPC_RMID, 0); // destruction semaphore
			
			semctl (sem, 0, IPC_RMID, 0); // destruction semaphore
			
			shmctl(sharedIdisPressed, IPC_RMID, &shmid);
			shmdt(isPressed);
			semctl (semClick, 0, IPC_RMID, 0); // destruction semaphore
			
		}
		else
		{
			delete x;
			delete y;
		}
	}
}

float Interface::GetX() 
{
	if ( app == NULL ) 
	{
		
		struct sembuf reserver = {0, -1, 0};
		struct sembuf liberer = {0, 1, 0};

		semop (sem, &reserver, 1); //réservation ressource critique
		float res = *x;
		
		// Arrondi du Float
		int tmp =(int)(res * ARRONDI);
		res = (float)(tmp)/ARRONDI;
		
		//cerr << "X : " << res << endl;
		semop (sem, &liberer, 1); 
		// Inversion du sens...
		return 1 - res;
		
	}
	else 
	{
		miseAJour();
		return *x;
	}
	
}

float Interface::GetY() 
{
	if ( app == NULL ) 
	{	
		struct sembuf reserver = {0, -1, 0};
		struct sembuf liberer = {0, 1, 0};

		semop (sem, &reserver, 1); //réservation ressource critique
		float res = *y;
		
		// Arrondi du Float
		int tmp =(int)(res * ARRONDI);
		res = (float)(tmp)/ARRONDI;
		
		//cerr << "Y : " << res << endl;
		semop (sem, &liberer, 1); 
		// Inversion du sens...
		return res;
	}
	else 
	{
		miseAJour();
		return *y;
	}
}

bool Interface::isMousePressed() 
{
	
	if ( app != NULL )
	{
		miseAJour();
		return isPressed;
	}
	else
	{
		struct sembuf reserver = {0, -1, 0};
		struct sembuf liberer = {0, 1, 0};

		semop (semClick, &reserver, 1);
		bool res = *isPressed;
		semop (semClick, &liberer, 1); 
		if(res == true)
			cerr << "Préssé !!" << endl;
		else
			cerr << "=== Pas préssé !!" << endl;
		return res;
	}

}

void Interface::setMousePressed(bool isMousePressed) 
{
	*isPressed = isMousePressed;
}

void Interface::miseAJour() 
{
	if(app != NULL) 
	{
		const sf::Input& input = app->GetInput();
		*x = input.GetMouseX()/(float)app->GetWidth();
		*y = input.GetMouseY()/(float)app->GetHeight();
		*isPressed = input.IsMouseButtonDown(sf::Mouse::Left);
	}
}

void Interface::afficherFenetre() 
{
	
	//if ( pidVideo != 0 )
	{
		//kill(pidVideo, SIGUSR1);
	}
	
	//cerr << pidVideo << " ba alors ???? " << endl;
	//cvNamedWindow("Test Color Tracking");
	//cvNamedWindow("Test Mask");
	//cvMoveWindow("Test Color Tracking", 0, 100);
	//cvMoveWindow("Test Mask", 650, 100);

	// Mouse event to select the tracked color on the original image
	//cvSetMouseCallback("Test Color Tracking", getObjectColor, this);

	
	struct sembuf reserver = {0, -1, 0};
	struct sembuf liberer = {0, 1, 0};

	semop (semAffiche, &reserver, 1);
	*affiche = 1;
	semop (semAffiche, &liberer, 1); 
	
}

void Interface::supprimerFenetre() 
{
	cvDestroyWindow("Test Color Tracking");
	cvDestroyWindow("Test Mask");
	cvDestroyWindow("Test Mask Click");
	
	struct sembuf reserver = {0, -1, 0};
	struct sembuf liberer = {0, 1, 0};

	semop (semAffiche, &reserver, 1);
	*affiche = 0;
	semop (semAffiche, &liberer, 1); 
}

void Interface::monSuperThread() 
{
	char key ='A';
	int nbPixels = 0;
	int nbPixelsClick = 0;
	
	while (key != 'q' && key !='Q')
	{	
		image = cvQueryFrame(capture);

		// If there is no image, we exit the loop
		if(!image) 
		{
			continue;
		}
		
		//cerr << " X : " << *x << " & Y : " << *y << endl;

		binarisation(image, &nbPixels, &nbPixelsClick);
		addObjectsToVideo(image, objectPos, nbPixels, clickPos, nbPixelsClick);

		// We wait 10 ms
		key = cvWaitKey(10);
		
		if ( key == 'o' || key == 'O' )
		{
			supprimerFenetre();
		}
		
	}
}

// méthodes privées

/*
* Transform the image into a two colored image, one color for the color we want to track, another color for the others colors
* From this image, we get two datas : the number of pixel detected, and the center of gravity of these pixel
*/
void Interface::binarisation(IplImage* image, int *nbPixels, int *nbPixelsClick) 
{
	
	struct sembuf reserver = {0, -1, 0};
	struct sembuf liberer = {0, 1, 0};
		
	IplImage *hsv, *mask, *maskClick;
	IplConvKernel *kernel;
	int sommeX = 0, sommeY = 0;
	int sommeXClick = 0, sommeYClick = 0;
	*nbPixels = 0;
	*nbPixelsClick = 0;

	// Create the mask &initialize it to white (no color detected)
	mask = cvCreateImage(cvGetSize(image), image->depth, 1);
	maskClick = cvCreateImage(cvGetSize(image), image->depth, 1);

	// Create the hsv image
	hsv = cvCloneImage(image);
	cvCvtColor(image, hsv, CV_BGR2HSV);

	// We create the mask
	cvInRangeS(hsv, cvScalar(h - tolerance -1, s - tolerance, 0), cvScalar(h + tolerance -1, s + tolerance, 255), mask);
	cvInRangeS(hsv, cvScalar(hClick - toleranceClick -1, sClick - toleranceClick, 0), cvScalar(hClick + toleranceClick -1, sClick + toleranceClick, 255), maskClick);

	// Create kernels for the morphological operation
	kernel = cvCreateStructuringElementEx(5, 5, 2, 2, CV_SHAPE_ELLIPSE);

	// Morphological opening (inverse because we have white pixels on black background)
	cvDilate(mask, mask, kernel, 1);
	cvErode(mask, mask, kernel, 1);  
	cvDilate(maskClick, maskClick, kernel, 1);
	cvErode(maskClick, maskClick, kernel, 1);  

	// We go through the mask to look for the tracked object and get its gravity center
	for(int i = 0; i < mask->width; i++) 
	{
		for(int j = 0; j < mask->height; j++) 
		{
			// If its a tracked pixel, count it to the center of gravity's calcul
			if(((uchar *)(mask->imageData + j*mask->widthStep))[i] == 255) 
			{
				sommeX += i;
				sommeY += j;
				(*nbPixels)++;
			}
			// If its a tracked Click pixel, count it to the center of gravity's calcul
			if(((uchar *)(maskClick->imageData + j*maskClick->widthStep))[i] == 255) 
			{
				sommeXClick += i;
				sommeYClick += j;
				(*nbPixelsClick)++;
			}
		}
	}

	semop (semAffiche, &reserver, 1);
	if ( *affiche )
	{
		// Show the result of the mask image
		cvShowImage("Test Mask", mask);
		cvShowImage("Test Mask Click", maskClick);
	}
	semop (semAffiche, &liberer, 1); 

	// We release the memory of kernels
	cvReleaseStructuringElement(&kernel);

	// We release the memory of the masks
	cvReleaseImage(&mask);
	cvReleaseImage(&maskClick);
	// We release the memory of the hsv image
	cvReleaseImage(&hsv);
	 
	// Test des pixels de click
	if(*nbPixelsClick > NBPIXELSMIN)
	{
		xClick = (((float)sommeXClick / (float)(*nbPixelsClick))/ (float)(image->width));
		yClick = (((float)sommeYClick / (float)(*nbPixelsClick))/ (float)(image->height));
		clickPos = cvPoint((int)(sommeXClick / (*nbPixelsClick)), (int)(sommeYClick / (*nbPixelsClick)));
	}
	else
	{
		xClick = -1;
		yClick = -1;
		clickPos = cvPoint(-1, -1);
	}

	// If there is no pixel, we return a center outside the image, else we return the center of gravity
	if(*nbPixels > NBPIXELSMIN)
	{
		semop (sem, &reserver, 1); //réservation ressource critique
		*x = (((float)sommeX / (float)(*nbPixels))/ (float)(image->width));
		*y = (((float)sommeY / (float)(*nbPixels))/ (float)(image->height));
		
		semop (semClick, &reserver, 1);
		if ( ((*x-xClick)*(*x-xClick) + (*y-yClick)*(*y-yClick)) < SEUILAPPROCHE )
		{
			//cerr << "### Pressed : " << ((*x-xClick)*(*x-xClick) + (*y-yClick)*(*y-yClick)) << endl;
			*isPressed = true;
		}
		else
		{
			//cerr << "### Not Pressed... : " << ((*x-xClick)*(*x-xClick) + (*y-yClick)*(*y-yClick)) << endl;
			*isPressed = false;
		}
		semop (semClick, &liberer, 1); 
		
		semop (sem, &liberer, 1); 
		objectPos = cvPoint((int)(sommeX / (*nbPixels)), (int)(sommeY / (*nbPixels)));
	}
	else
	{
		semop (sem, &reserver, 1);
		*x = -1;
		*y = -1;
		semop (sem, &liberer, 1); 

		objectPos = cvPoint(-1, -1);
	}
	
	return;
}

/*
* Add a circle on the video that follow your colored object
*/
void Interface::addObjectsToVideo(IplImage* image, CvPoint objectNextPos, int nbPixels, CvPoint clickNextPos, int nbPixelsClick)
 {

	int objectNextStepX, objectNextStepY;

	// Calculate circle next position (if there is enough pixels)
	if (nbPixels > NBPIXELSMIN) {

		// Reset position if no pixel were found
		if (objectPos.x == -1 || objectPos.y == -1) 
		{
			objectPos.x = objectNextPos.x;
			objectPos.y = objectNextPos.y;
		}

		// Move step by step the object position to the desired position
		if (abs(objectPos.x - objectNextPos.x) > STEP_MIN) 
		{
			objectNextStepX = max(STEP_MIN, min(STEP_MAX, abs(objectPos.x - objectNextPos.x) / 2));
			objectPos.x += (-1) * sign(objectPos.x - objectNextPos.x) * objectNextStepX;
		}
		if (abs(objectPos.y - objectNextPos.y) > STEP_MIN) 
		{
			objectNextStepY = max(STEP_MIN, min(STEP_MAX, abs(objectPos.y - objectNextPos.y) / 2));
			objectPos.y += (-1) * sign(objectPos.y - objectNextPos.y) * objectNextStepY;
		}

	// -1 = object isn't within the camera range
	}
	else 
	{
		objectPos.x = -1;
		objectPos.y = -1;
	}

	// Draw an object (circle) centered on the calculated center of gravity
	if (nbPixels > 10) 
	{
		cvDrawCircle(image, objectPos, 15, CV_RGB(255, 0, 0), -1);
	}
	
	int clickNextStepX, clickNextStepY;

	// Calculate circle next position (if there is enough pixels)
	if (nbPixelsClick > NBPIXELSMIN) {

		// Reset position if no pixel were found
		if (clickPos.x == -1 || clickPos.y == -1) 
		{
			clickPos.x = clickNextPos.x;
			clickPos.y = clickNextPos.y;
		}

		// Move step by step the object position to the desired position
		if (abs(clickPos.x - clickNextPos.x) > STEP_MIN) 
		{
			clickNextStepX = max(STEP_MIN, min(STEP_MAX, abs(clickPos.x - clickNextPos.x) / 2));
			clickPos.x += (-1) * sign(clickPos.x - clickNextPos.x) * clickNextStepX;
		}
		if (abs(clickPos.y - clickNextPos.y) > STEP_MIN) 
		{
			clickNextStepY = max(STEP_MIN, min(STEP_MAX, abs(clickPos.y - clickNextPos.y) / 2));
			clickPos.y += (-1) * sign(clickPos.y - clickNextPos.y) * clickNextStepY;
		}

	// -1 = object isn't within the camera range
	}
	else 
	{
		clickPos.x = -1;
		clickPos.y = -1;
	}

	// Draw an object (circle) centered on the calculated center of gravity
	if (nbPixelsClick > NBPIXELSMIN) 
	{
		cvDrawCircle(image, clickPos, 15, CV_RGB(0, 255, 0), -1);
	}
	
	struct sembuf reserver = {0, -1, 0};
	struct sembuf liberer = {0, 1, 0};

	semop (semAffiche, &reserver, 1);
	if ( *affiche )
	{
		// We show the image on the window
		cvShowImage("Test Color Tracking", image);
		cvSetMouseCallback("Test Color Tracking", getObjectColor, this);
	}
	semop (semAffiche, &liberer, 1);

}

/*
* Get the color of the pixel where the mouse has clicked
* We put this color as model color (the color we want to tracked)
*/
void getObjectColor(int event, int x, int y, int flags, void *param) 
{
	// Vars
	CvScalar pixel;
	IplImage *hsv;
	
	//cerr << getpid() << " --> blabla" << endl;
	
	if(event == CV_EVENT_LBUTTONUP)
	{
		
		//cerr << getpid() << " --> buttonnnnnn" << endl;
		
		// Get the hsv image
		hsv = cvCloneImage(((Interface*)param)->getImage());
		cvCvtColor(((Interface*)param)->getImage(), hsv, CV_BGR2HSV);

		// Get the selected pixel
		pixel = cvGet2D(hsv, y, x);

		if ( ((Interface*)param)->getNext() == CLICK)
		{
			// Change the value of the tracked color with the color of the selected pixel
			((Interface*)param)->setHClick((int)pixel.val[0]);
			((Interface*)param)->setSClick((int)pixel.val[1]);
			((Interface*)param)->setVClick((int)pixel.val[2]);
			((Interface*)param)->setNext();
		}
		else
		{
			// Change the value of the tracked color with the color of the selected pixel
			((Interface*)param)->setH((int)pixel.val[0]);
			((Interface*)param)->setS((int)pixel.val[1]);
			((Interface*)param)->setV((int)pixel.val[2]);
			((Interface*)param)->setNext();
		}

		// Release the memory of the hsv image
		cvReleaseImage(&hsv);
	}

}
