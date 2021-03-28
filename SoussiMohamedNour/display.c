#include "fn.h"
#include "structs.h"

void displayScreen()
{
    mediaLoad();
    screen = NULL;
    screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    SDL_WM_SetCaption("Eniglme ROBOTA",NULL);
    if(screen == NULL)
	{
		printf(" ERROR creating screen : %s ! \n",SDL_GetError());
	}
	else
	{
		printf("Screen loaded ! \n");
	}

    SDL_BlitSurface(images.background ,NULL,screen,0);
    SDL_BlitSurface(images.logo,NULL,screen,&pos.logopos);
	SDL_Flip(screen);

}
void displayQuestions()
{


    SDL_BlitSurface(images.question,NULL,screen,&pos.quest);
    SDL_BlitSurface(images.robot,NULL,screen,&pos.robot);
    SDL_BlitSurface(images.emptya0,NULL,screen,&pos.empty1);
    SDL_BlitSurface(images.emptyb0,NULL,screen,&pos.empty2);
    SDL_BlitSurface(images.emptyc0,NULL,screen,&pos.empty3);
    SDL_BlitSurface(images.emptyd0,NULL,screen,&pos.empty4);
    SDL_BlitSurface(images.score1,NULL,screen,&pos.score1);
    SDL_BlitSurface(images.score1,NULL,screen,&pos.score2);
    SDL_BlitSurface(images.score1,NULL,screen,&pos.score3);


	SDL_Flip(screen);
}

void displayText()
{

    SDL_Color white  = {255,255,255};

    strcpy(qa.score,"score :");

    text.questiontextsurface = TTF_RenderText_Solid(font,qa.questionText,white);
    text.answertext1 = TTF_RenderText_Solid(font,qa.answerA,white);
    text.answertext2 = TTF_RenderText_Solid(font,qa.answerB,white);
    text.answertext3 = TTF_RenderText_Solid(font,qa.answerC,white);
    text.answertext4 = TTF_RenderText_Solid(font,qa.answerD,white);
    text.score = TTF_RenderText_Solid(font,qa.score,white);

    SDL_BlitSurface(text.questiontextsurface,NULL,screen,&pos.qtext);
    SDL_BlitSurface(text.answertext1,NULL,screen,&pos.a1text);
    SDL_BlitSurface(text.answertext2,NULL,screen,&pos.a2text);
    SDL_BlitSurface(text.answertext3,NULL,screen,&pos.a3text);
    SDL_BlitSurface(text.answertext4,NULL,screen,&pos.a4text);
    SDL_BlitSurface(text.score,NULL,screen,&pos.scoretext);
    SDL_Flip(screen);
}
