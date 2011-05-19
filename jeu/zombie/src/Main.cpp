#include <iostream>

#include "ZombieGame.h"

using namespace std;

/*
 * J'ai mis le commentaire "Emulation de la webcam"
 * sur toutes les partie qui servent à émuler la
 * webcam avec la souris, en attendant le traitement
 * de l'image.
 */

int main() {
    ZombieGame z;
    Interface* inter = new Interface(); //Emulation de la webcam
    z.SetInterface(inter);
    z.Run();
    delete inter;
    return 0;
}
