#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "fonctions.h"
int main()
{
    int collision, continuer=1, distance=100;
    SDL_Event event;
    personnage perso, miniPerso, miniPersoProchain;

    int longueurMax = 8000, largeurMax = 800, longueur = 800, largeur = 80;

    int redimensionnement =  distance * longueur / longueurMax;

    miniMap m;

    SDL_Surface *screen=NULL;
    SDL_Surface *background=NULL;
    SDL_Surface *backgroundMasque=NULL;

    SDL_Rect positionCamera, positionBackground;
    return 0;
    //initialisation de la sdl
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize SDL : %s\n ", SDL_GetError());
		return 1;
	}

    //screen
    screen = SDL_SetVideoMode(1600, 800, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    if (screen == NULL)
    {
        printf("ERREUR: %s\n", SDL_GetError());
        return 1;
    }

    //background et sa position
    background=IMG_Load("fondComplet.jpg");

	if (background == NULL)
	{
		printf("Unable to load background : %s\n", SDL_GetError());
		return 1;
	}

	positionBackground.x = 0;
	positionBackground.y = 0;

    //background masque
    backgroundMasque=IMG_Load("fondComplet.jpg");

	if (backgroundMasque == NULL)
	{
		printf("Unable to load background : %s\n", SDL_GetError());
		return 1;
	}

	//personnage
	perso.imagePerso=IMG_Load("mario.png");
	perso.positionPerso.x=0;
   	perso.positionPerso.y=313-perso.positionPerso.h/2;

	if (perso.imagePerso == NULL)
	{
		printf("Unable to load background : %s\n", SDL_GetError());
		return 1;
	}

   	 //personnage dans le minimap
    	 miniPerso.imagePerso=IMG_Load("miniPerso.png");
   	 miniPerso.positionPerso.x=0;
   	 miniPerso.positionPerso.y=550;
   	 
   	 if (miniPerso.imagePerso == NULL)
	{
		printf("Unable to load background : %s\n", SDL_GetError());
		return 1;
	}

	miniPersoProchain.positionPerso.x=miniPerso.positionPerso.x;
	miniPersoProchain.positionPerso.x=miniPerso.positionPerso.x;

	//minimap
	initmap(&m);



    while(continuer)
    {
        SDL_BlitSurface(background, NULL, screen, &positionBackground);
        SDL_BlitSurface(perso.imagePerso, NULL, screen, &perso.positionPerso);
        SDL_BlitSurface(miniPerso.imagePerso, NULL, screen, &miniPerso.positionPerso);

        afficherminimap(m, screen);

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    continuer=0;
                    break;

                //events du perso
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                    case SDLK_RIGHT:
                        miniPersoProchain.positionPerso.x+=distance;
                        if(collisionPP(miniPersoProchain, backgroundMasque)==0)
                        {
                            positionCamera.x=0;
                            miniPerso.positionPerso.x=miniPersoProchain.positionPerso.x;

                            MAJMinimap(&perso, &m, positionCamera, redimensionnement);
                        }
                        break;

                    case SDLK_LEFT:
                        miniPersoProchain.positionPerso.x-=distance;
                        if(collisionPP(miniPersoProchain, backgroundMasque)==0)
                        {
                            positionCamera.x=1;
                            miniPerso.positionPerso.x=miniPersoProchain.positionPerso.x;
                            MAJMinimap(&perso, &m, positionCamera, redimensionnement);
                        }
                        break;

                    case SDLK_DOWN:
                        miniPersoProchain.positionPerso.y+=distance;
                        if(collisionPP(miniPersoProchain, backgroundMasque)==0)
                        {
                            positionCamera.x=2;
                            miniPerso.positionPerso.y=miniPersoProchain.positionPerso.y;
                            MAJMinimap(&perso, &m, positionCamera, redimensionnement);
                        }
                        break;

                    case SDLK_UP:
                        miniPersoProchain.positionPerso.y-=distance;
                        if(collisionPP(miniPersoProchain, backgroundMasque)==0)
                        {
                            positionCamera.x=3;
                            miniPerso.positionPerso.x=miniPersoProchain.positionPerso.x;
                            MAJMinimap(&perso, &m, positionCamera, redimensionnement);
                        }
                        break;
                    }
            }
        }
        SDL_Flip(screen);
    }
}
