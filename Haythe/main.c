#include "SDLennemi.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL, *Hero= NULL,*Map= NULL,*tester=NULL;
    SDL_Rect posHero,posMap,posEnnemi;
    SDL_Event event;
    ennemi e;
    int continuer=1,collision,i;
    //THERE NEED TO BE CHANGED THEY ARE FOR THE REACTION TO THE PLAYERS POSITION int s1=600,s2=300;
    //SDL_TimerID timer;
    //SDL_EnableKeyRepeat(100, 100);
    //timer= SDL_AddTimer(30, animerEnnemi,&e);    
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    screen = SDL_SetVideoMode(966, 850, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    Hero=IMG_Load("mario_droite.gif");
    Map=IMG_Load("carte.PNG");
    //tester=IMG_Load("ball.png");
    initEnnemi(&e);
    posMap.x=0;
    posMap.y=0;
    posEnnemi.x=450;
    posEnnemi.y=450;    
    posHero.x=0;
    posHero.y=600;
    e.entite_pos.x = 700;
    e.entite_pos.y = 450;
    posHero.w=Hero->w;
    posHero.h=Hero->h;    
    e.entite_pos.w=e.entite[0][0]->w;
    e.entite_pos.h=e.entite[0][0]->h;
    e.entite_pos.w=e.entite[0][1]->w;
    e.entite_pos.h=e.entite[0][1]->h;
    e.entite_pos.w=e.entite[0][2]->w;
    e.entite_pos.h=e.entite[0][2]->h;
    e.entite_pos.w=e.entite[2][0]->w;
    e.entite_pos.h=e.entite[2][0]->h;
    e.entite_pos.w=e.entite[2][1]->w;
    e.entite_pos.h=e.entite[2][1]->h;
    e.entite_pos.w=e.entite[2][2]->w;
    e.entite_pos.h=e.entite[2][2]->h;
   
    e.entite_pos.w=e.entite[6][0]->w;
    e.entite_pos.h=e.entite[6][0]->h;
    e.entite_pos.w=e.entite[6][1]->w;
    e.entite_pos.h=e.entite[6][1]->h;
    e.entite_pos.w=e.entite[6][2]->w;
    e.entite_pos.h=e.entite[6][2]->h; 
    while (continuer)
    {
	SDL_BlitSurface(Map,NULL, screen, &posMap);
	SDL_PollEvent(&event);
	switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    case SDLK_RIGHT:
			for(i=0;i<20;i++)                        
				posHero.x++;
                        break;
                    case SDLK_LEFT:
                        for(i=0;i<20;i++)                        
				posHero.x--;
                        break;
                    case SDLK_UP:
                        for(i=0;i<20;i++)                        
				posHero.y--;
                        break;                    
		   default:
                        break;
                }
                break;
        } 

    //the enemy ai. 
	
collision=collisionBB(posHero,e);
if(collision==0)
{
animerEnnemi(&e);
    deplacer(&e);


}    
else
{
    e.direction=6;
animerEnnemi(&e);
posHero.x-=20;

}



	//pour une autre fonction dans un avenir proche 
	/*Uint32 animerEnnemi(Uint32 intervalle, void *parametre)
	{
		ennemi* e = parametre;


		int n=2;


		if ((e->num)==n)
		e->num=0;
		else
		e->num++;

		return intervalle;
	} */

//SDL_BlitSurface(tester,NULL, screen, &posEnnemi);
	SDL_BlitSurface(Hero,NULL, screen, &posHero);
	afficherEnnemi(e,screen); 	
//SDL_BlitSurface(e.entite[6][2],NULL, screen, &e.entite_pos);
	SDL_Flip(screen);
   }

    //CLEAR MEMORY
    SDL_FreeSurface(Map);
    SDL_FreeSurface(Hero); 
    ennemiFreesurface(e);




    SDL_Quit();

    return EXIT_SUCCESS;
}

