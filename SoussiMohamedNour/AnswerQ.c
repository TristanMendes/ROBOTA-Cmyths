#include "structs.h"
#include "fn.h"

void getAnswer( SDL_Event e,int scorenb,int health)
{
    int keyinput;
    int mouseinput;
    int corrAnswer;

    //loadtext();
    keyinput = getkeyboard(e);
    mouseinput = getMouse(e);
    corrAnswer = answernumber();


    if(((keyinput == 1) || (mouseinput == 1)) && corrAnswer == 1)
    {
        correctSound();
        SDL_BlitSurface(images.emptya1,NULL,screen,&pos.empty1);
        SDL_Flip(screen);
        scorenb = scorenb + 1000;
    }
    else if(((keyinput == 1) || (mouseinput == 1)) && corrAnswer != 1)
    {
        wrongSound();
        SDL_BlitSurface(images.emptya2,NULL,screen,&pos.empty1);
        SDL_Flip(screen);
        health = health - 1;
    }
     if(((keyinput == 2) || (mouseinput == 2)) && corrAnswer == 2)
    {
        correctSound();
        SDL_BlitSurface(images.emptyb1,NULL,screen,&pos.empty2);
        SDL_Flip(screen);
        scorenb = scorenb + 1000;
    }
    else if(((keyinput == 2) || (mouseinput == 2)) && corrAnswer != 2)
    {
        wrongSound();
        SDL_BlitSurface(images.emptyb2,NULL,screen,&pos.empty2);
        SDL_Flip(screen);
        health = health - 1;
    }
    if(((keyinput == 3) || (mouseinput == 3)) && corrAnswer == 3)
    {
        correctSound();
        SDL_BlitSurface(images.emptyc1,NULL,screen,&pos.empty3);
        SDL_Flip(screen);
        scorenb = scorenb + 1000;
    }
    else if(((keyinput == 3) || (mouseinput == 3)) && corrAnswer != 3)
    {
        wrongSound();
        SDL_BlitSurface(images.emptyc2,NULL,screen,&pos.empty3);
        SDL_Flip(screen);
        health = health - 1;
    }
    if(((keyinput == 4) || (mouseinput == 4)) && corrAnswer == 4)
    {
        correctSound();
        SDL_BlitSurface(images.emptyd1,NULL,screen,&pos.empty4);
        SDL_Flip(screen);
        scorenb = scorenb + 1000;
    }
    else if(((keyinput == 4) || (mouseinput == 4)) && corrAnswer != 4)
    {
        wrongSound();
        SDL_BlitSurface(images.emptyd2,NULL,screen,&pos.empty4);
        SDL_Flip(screen);
        health = health - 1;
    }
    if(health == 2)
    {
        SDL_BlitSurface(images.score0,NULL,screen,&pos.score3);
        SDL_Flip(screen);
    }
    if(health == 1)
    {
        SDL_BlitSurface(images.score0,NULL,screen,&pos.score2);
        SDL_Flip(screen);
    }
    if(health == 0)
    {
        SDL_BlitSurface(images.score0,NULL,screen,&pos.score1);
        SDL_Flip(screen);
    }
    ///printf(" score: %d",scorenb);
    ///printf(" health : %d",health);
}
