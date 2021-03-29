#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

struct text
{
SDL_Surface*texte;
SDL_Rect position;
char score[20];
char vie[20];
char temps[20];
};
typedef struct text text;

struct vie
{SDL_Surface *image;
SDL_Rect position;
};
typedef struct vie vies;

struct perso
{
text TEXTE[3];
SDL_Surface *imagePerso[4][4];
SDL_Surface *texte;
vies V[5];
SDL_Rect postion;
int score;
int vie;
int etat;
int temps;
int key;
int etape[3];
int j;
float vitesse,acceleration,dx;
int etat_vie;

};
typedef struct perso Personne;



//FONCTION A DEVELOPPEES;
void initPerso(Personne *p);
void afficherPerso(Personne *p, SDL_Surface * screen);
void deplacerPerso (Personne *p,Uint32 dt);
void animerPerso (Personne* p);
void saut (Personne* p,SDL_Surface* screen);
void updatePerso(Personne *p);
void liberer(Personne *p);

#endif // PERSO_H_INCLUDED

