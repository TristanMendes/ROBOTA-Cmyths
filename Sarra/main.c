#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int done=1, temps=0, tempsMax=900000;
	SDL_Event event;
	SDL_Surface *screen = NULL;
	SDL_Surface *image = NULL;
	SDL_Rect positionecran;
	char pause;
	miniMap m;
	
	initMap(&m);
	
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize SDL : %s\n ", SDL_GetError());
		return 1;
	}
	screen = SDL_SetVideoMode(600, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL)
	{
		printf("Unable to set video mode : %s\n", SDL_GetError());
		return 1;
	}

	image=SDL_LoadBMP("finale.bmp");
	if (image == NULL)
	{
		printf("Unable to load background : %s\n", SDL_GetError());
		return 1;
	}
	
	
	while (done)
	{
		positionecran.x = 0;
		positionecran.y = 0;
		
		SDL_BlitSurface(image, NULL, screen, &positionecran);
		
		SDL_Flip(screen);
		
		//test du miniMap
		afficherMap(m, &screen);
		
		
		//test du gestionnaire du temps
		if(temps<tempsMax)
		{
			afficherTemps(&temps);		
		}
		else
			temps=0;
		
		//test de la collision perfect pixel
			//collision=collisionPerfectPixel(p, b, &masque);
		
		//test IA2
			//i=IA(g, joueurProgramme);
	}


	SDL_Quit();

	return 0;
}
