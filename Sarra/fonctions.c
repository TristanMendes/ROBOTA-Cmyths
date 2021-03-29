#include "fonctions.h"

//Mini Map

void initMap(miniMap *m)
{
    m->imageMiniature=IMG_Load("miniBackground.png");
    m->hero=IMG_Load("miniHero.png");
    m->ennemi=IMG_Load("miniEnnemi.png");

}

void afficherMap(miniMap m, SDL_Surface *screen)
{

}

SDL_Rect MAJMinimap(SDL_RECT posInitiale, int redimmensionnement)
{
    SDL_Rect posMiniature;
    posMiniature.x=posInitiale.x * redimmensionnement/100;
    posMiniature.y=posInitiale.y * redimmensionnement/100;
    return posMiniature;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Gestionnaire de temps

void afficherTemps(init *temps)
{


}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Collision perfect pixel

int collisionPerfectPixel(personne p, background b, char *masque)





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//IA2

int IA(grille g, int joueurProgramme)
