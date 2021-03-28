#include "SDLennemi.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
void initEnnemi(ennemi *e)
{
   /* e->entite_pos.w=e->entite[0][0]->w;
    e->entite_pos.h=e->entite[0][0]->h;
    e->entite_pos.w=e->entite[0][1]->w;
    e->entite_pos.h=e->entite[0][1]->h;
    e->entite_pos.w=e->entite[0][2]->w;
    e->entite_pos.h=e->entite[0][2]->h;
    e->entite_pos.w=e->entite[2][0]->w;
    e->entite_pos.h=e->entite[2][0]->h;
    e->entite_pos.w=e->entite[2][1]->w;
    e->entite_pos.h=e->entite[2][1]->h;
    e->entite_pos.w=e->entite[2][2]->w;
    e->entite_pos.h=e->entite[2][2]->h;
    e->entite_pos.w=e->entite[6][0]->w;
    e->entite_pos.h=e->entite[6][0]->h;
    e->entite_pos.w=e->entite[6][1]->w;
    e->entite_pos.h=e->entite[6][1]->h;
    e->entite_pos.w=e->entite[6][2]->w;
    e->entite_pos.h=e->entite[6][2]->h;
    e->entite_pos.x = 700;
    e->entite_pos.y = 450; for some reason these do not work so I have to reinitiliaze in main*/
    e->entite[0][0]= IMG_Load("1.png");
    e->entite[0][1]= IMG_Load("2.png");
    e->entite[0][2]= IMG_Load("3.png");  
    e->entite[2][0]= IMG_Load("0left.png");
    e->entite[2][1]= IMG_Load("7left.png");
    e->entite[2][2]= IMG_Load("9left.png");
    e->entite[6][0]= IMG_Load("attack003.png");
    e->entite[6][1]= IMG_Load("attack005.png");
    e->entite[6][2]= IMG_Load("attack003.png");
    e->state=waiting;
    e->direction=0; //0 RIGHT 2 LEFT 6 STAND
    e->num=0; 
}
void afficherEnnemi(ennemi e , SDL_Surface *screen)
{
   SDL_BlitSurface(e.entite[e.direction][e.num],NULL, screen, &e.entite_pos);

}
void animerEnnemi(ennemi *e) //faut fixer celui la
{
    int n=2;


    if (e->num==n)
        e->num=0;
    else
        e->num++;
    
    SDL_Delay(200);
}

void deplacer(ennemi *e)
{
    int posmax=700, posmin=400,i;
    if (e->entite_pos.x>posmax)
        e->direction=2; //LEFT

    if (e->entite_pos.x <posmin)
        e->direction=0; //RIGHT

    if (e->direction==0)
    {
	for(i=0;i<20;i++)
		e->entite_pos.x++;}
    else
    {
	for(i=0;i<20;i++)
    	    e->entite_pos.x--;
    }
}

void ennemiFreesurface(ennemi e)
{
	SDL_FreeSurface(e.entite[0][0]);
	SDL_FreeSurface(e.entite[0][1]);
	SDL_FreeSurface(e.entite[0][2]);
	SDL_FreeSurface(e.entite[2][0]);
	SDL_FreeSurface(e.entite[2][1]);
	SDL_FreeSurface(e.entite[2][2]);
	SDL_FreeSurface(e.entite[6][0]);
	SDL_FreeSurface(e.entite[6][1]);
	SDL_FreeSurface(e.entite[6][2]);

}

int collisionBB(SDL_Rect posHero, ennemi e)
{
int state;
if ((posHero.x+posHero.w<e.entite_pos.x) || (posHero.x>e.entite_pos.x + e.entite_pos.w) ||
(posHero.y+posHero.h<e.entite_pos.y) || (posHero.y>e.entite_pos.y + e.entite_pos.h))
{
	state=0; //NO COLLISION
}

else
{
		state=1; //COLLISION
}
return state;
} 
/*int detect_collision(perso *p, entite* e){
  if (e->col==0){
if ((p->position_perso.x + p->position_perso. w< e->entite_pos. x) || (p->position_perso.x> e->entite_pos. x + e->entite_pos. w) ||
(p->position_perso.y + p->position_perso.h< e->entite_pos. y) || (p->position_perso.y> e->entite_pos. y + e->entite_pos. h ))
e->col= 0;
else
e->col=1;
}
return e->col;
}*/





//THIS PART IS FOR IA 1 INTELLIGENT MOVEMENT

/*void updateEnnemi (ennemi* e, SDL_Rect posHero,SDL_Surface *screen)
{
int s1=600, s2=100;
//the enemy ai.
    if (e->state == waiting)
    {
        if(posHero.x > s1)
        {
        //WAIT-WAIT
            e->state=waiting;
           //animerEnnemi(&e);
            //deplacer(&e);

        }
        else if(s2 < posHero.x && s1 >= posHero.x)
        {
    //WAIT-FOLLOWING
            e->state=following;
            //animerEnnemi(&e);//ennemi ne bouge pas il est retourné vers la droite
            e->entite_pos.x--;//ennemi bouge vers la gauche tout en affichant deux images pour marcher	
				
        }
    }

    else if (e->state == following)
    {
        if(s2 < posHero.x && s1 >= posHero.x)
        {
            //FOLLOWING-FOLLOWING
            e->state=following;
            //animerEnnemi(&e);
            e->entite_pos.x--;//ennemi bouge vers la gauche tout en affichant deux images pour marcher
	
        }
        else if(0 < posHero.x && s2 >= posHero.x )
        {
        //FOLLOWING-ATTACKING
            e->state=attacking;
           // animerEnnemi(&e);

        }
    }
    else if (e->state==attacking)
    {
        if(0 < posHero.x && s2 >= posHero.x )
        {
            //ATTACKING-ATTACKING
            e->state=attacking;
//animerEnnemi(&e);
		
        }
        else if(posHero.x > s1)
        {
        //ATTACKING - WAIT
            e->state=waiting;
//animerEnnemi(&e);
	
        }
        
        //l'affichage des images lorsque lenemi attaque le jouer
   }
}*/


