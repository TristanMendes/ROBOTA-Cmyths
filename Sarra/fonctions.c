#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "fonctions.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
//fonctions gestion du temps




//////////////////////////////////////////////////////////////////////////////////////////////////
//fonctions minimap
void initmap(miniMap *m)
{
    m->posMinimap.x=0;
    m->posMinimap.y=0;
    m->imageMiniature=IMG_Load("map.png");
}
void afficherminimap(miniMap m, SDL_Surface *screen)
{
    SDL_BlitSurface(m.imageMiniature, NULL, screen, &m.posMinimap);
}
void MAJMinimap(personnage *perso, miniMap *m, SDL_Rect positionCamera, int redimensionnement)
{
    if (positionCamera.x==0)
  perso->positionPerso.x+= redimensionnement;

  if (positionCamera.x==1)
  perso->positionPerso.x -= redimensionnement;

  if (positionCamera.x==2)
  perso->positionPerso.y += redimensionnement;

  if (positionCamera.x==3)
  perso->positionPerso.y -= redimensionnement;

}






/////////////////////////////////////////////////////////////////////////////////////////////////
//fonctions collision
SDL_Color GetPixel(SDL_Surface *background, int x, int y)
{
    SDL_Color couleur;
	Uint32 col=0;

	//permet de determiner la position

	char* pixelPosition=(char*) background->pixels;
	pixelPosition+=(background->pitch*y);
	pixelPosition+=(background->format->BytesPerPixel*x);

	memcpy(&col, pixelPosition, background->format->BytesPerPixel);

	//convertir couleur

	SDL_GetRGB(col, background->format, &couleur.r, &couleur.g, &couleur.b);

	return(couleur);

}
int collisionPP(personnage p, SDL_Surface *backgroundMasque)
{
    SDL_Color test;

	int collision=0, i;

	SDL_Rect pixelRef[8];
	int X, Y, W, H;
	int x, y;

	X=p.positionPerso.x;
	Y=p.positionPerso.y;
	W=p.positionPerso.w;
	H=p.positionPerso.h;

	//coordonnées des 8 points au niveau desquels ont va detecter la collision
	pixelRef[0].x=X;
	pixelRef[0].y=Y;

	pixelRef[1].x=X+W/2;
	pixelRef[1].y=Y;

	pixelRef[2].x=X+W;
	pixelRef[2].y=Y;

	pixelRef[3].x=X;
	pixelRef[3].y=Y+H/2;

	pixelRef[4].x=X;
	pixelRef[4].y=Y+H;

	pixelRef[5].x=X+W/2;
	pixelRef[5].y=Y+H;

	pixelRef[6].x=X+W;
	pixelRef[6].y=Y+H;

	pixelRef[7].x=X+W;
	pixelRef[7].y=Y+H/2;

	if(collision==0)
	{
		for(i=0; i<8 && collision==0; i++)
		{
            //couleur des obstacles est noir={0,0,0}
            x=pixelRef[i].x;
            y=pixelRef[i].y;
            test=GetPixel(backgroundMasque, x, y);
            if(test.r==0 && test.g==0 && test.b==0)
                collision=1;
		}

	}
	return(collision);

}




