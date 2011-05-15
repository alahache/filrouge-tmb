#include <iostream>

#include "SMB.h"
//#include "Interface.h"

using namespace std;

/*
 * J'ai mis le commentaire "Emulation de la webcam"
 * sur toutes les partie qui servent � �muler la
 * webcam avec la souris, en attendant le traitement
 * de l'image.
 */

int main() {
    SMB shootMyBall;
    Interface* inter = new Interface(shootMyBall.GetRenderWindow()); //Emulation de la webcam
    shootMyBall.SetInterface(inter);
    shootMyBall.Run();
    delete inter;

    return 0;
}
