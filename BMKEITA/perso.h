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
typedef struct text text; //STRUCTURE PERMETTANT DE GERER LES TEXTES QUI DOIVENT ETRE AFFCIHÉS COMME "SCORE,VIE,OU TEMPS.....);

struct vie
{SDL_Surface *image;
SDL_Rect position;
};
typedef struct vie vies; //STRUCTURE PERMETTANT DE GERER LES IMAGES DES VIES

struct perso
{
text TEXTE[3];
vies V[5]; //CONTIENT  LES IMAGES DES COEURS ET LEURS POSITIONS;

SDL_Surface *imagePerso[4][4];//LA MATRICE CONTENANT LES IMAGES DU PERSONNAGE PRINCIPAL;
SDL_Rect postion,posMarioRel;
int score;
int vie;
int etat;//QUI PERMET DE CONNAITRE LETAT DU JOUEUR(EN SITUATION DOWN,UP,RIGHT OU LEFT);
int temps;
int key;//VARIE EN FONCTION DU BOUTON DU CLAVIER QUI A ETE APPUYE, CETTE VARIABLE EST UTILISEE POUR LES CONDITIONS DE DEPLACEMENT ET AUTRES; 

int etape[4];//TABLEAU DENTIERS PERMETTANT DE SE DEPLACER DANS LA MATRICE DES IMAGES AFIN DE REALISER LANIMATION;

int j; //UNE VARIABLE DE TEST QUI ME PERMET DAFFICHER LES RESSOURCES DES AU DEPART DU JEU MEME SI AUCUN EVENEMENT N'EST DETECTE;

float vitesse,acceleration,dx;//PERMET DE GERER LA VITESSE ET LACCELERATION DU PERSONNAGE AINSI QUE LA DISTANCE ENGENFREE

int etat_vie;//CETTE VARIABLE EST UTILISEE POUR GERER LA SITUATION DES COEURS DU PERSONNAGE, ELLE PERMET DE SE DEPLACER LE TABLEAU DES VIES;
int sauter;
};
typedef struct perso Personne;


//FONCTION A DEVELOPPEES;
void initPerso(Personne *p);
void afficherPerso(Personne *p, SDL_Surface * screen);
void deplacerPerso (Personne *p,Uint32 dt);
void animerPerso (Personne* p);
void sauter(Personne* p,SDL_Surface* screen);
void updatePerso(Personne *p);//PERMET LA MAJ DES RESSSOURCES DU PERSONNAGE PRINCIPAL COMME LE SCORE, LE TEMPS OU LE NOMBRE DE COEURS;
void liberer(Personne *p);//FONCTION PERMETTANT DE LIBERER LA MEMOIRE LORS DE LA SORTIE DE LA BOUCLE DU JEU;

#endif // PERSO_H_INCLUDED

