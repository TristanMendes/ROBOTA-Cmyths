#ifndef SDLENNEMI_H_INCLUDED
#define SDLENNEMI_H_INCLUDED

#ifndef ENTITESDL_H_INCLUDED
#define ENTITESDL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef enum STATE STATE;
enum STATE {waiting,following,attacking};

struct Ennemi
{
    SDL_Surface *entite[8][2] ;
    SDL_Rect entite_pos;
    int direction;//0 RIGHT 2 LEFT 6 STAND
    int num; //nombre de l'image
    STATE state;
};
typedef struct Ennemi ennemi;
void initEnnemi(ennemi *e);
void afficherEnnemi(ennemi e , SDL_Surface *screen);
void animerEnnemi(ennemi *e);
void deplacer(ennemi *e);
void ennemiFreesurface(ennemi e);
int collisionBB(SDL_Rect posHero, ennemi e);
//void updateEnnemi (ennemi* e, SDL_Rect posHero,SDL_Surface *screen);
#endif // ENTITESDL_H_INCLUDED

#endif // SDLENNEMI_H_INCLUDED
