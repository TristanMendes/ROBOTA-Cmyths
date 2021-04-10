#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

//structure personnage
typedef struct
{
	SDL_Rect positionPerso;
	SDL_Surface *imagePerso;
}personnage;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//minimap
//structure minimap
typedef struct
{
	SDL_Surface *imageMiniature;
	SDL_Rect posMinimap;
}miniMap;
//Fonctions mini map
void initmap(miniMap *m);
void afficherminimap(miniMap m, SDL_Surface *screen);
void MAJMinimap(personnage *perso, miniMap *m, SDL_Rect positionCamera, int redimensionnement);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//collision parfaite 
//Fonctions collision perfect pixel
SDL_Color GetPixel(SDL_Surface *background, int x, int y);
int collisionPP(personnage p, SDL_Surface *backgroundMasque);



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//gestion du temps
//structure temps
typedef struct temps
{
	SDL_Surface *texte;
	SDL_Rect position;

	TTF_Font *police;

	char entree[100];
	int secondesEcoulees;
	SDL_Color couleurBlanche;
	time_t t1, t2;
	int m, s;
} temps;
//Fonctions gestion du temps
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);

#endif // FONCTIONS_H_INCLUDED
