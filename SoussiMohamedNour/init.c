#include "fn.h"
#include "structs.h"

void videoinit()
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("ERROR initializing video : %s \n",SDL_GetError());
	}
	else
	{
		printf(" Video init successfully . \n ");
	}
}
////////////////
void audioinit()
{
	if(SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		printf("ERROR initializing audio : %s \n",SDL_GetError());
	}
	else
	{
        printf("AUDIO initialized successfully . \n ");
	}
}
/////////////////
void imageinit()
{
	int imgflags = IMG_INIT_PNG;
    if(!(IMG_Init(imgflags) & imgflags))
    {
        printf(" ERROR initializing images %s !!\n",IMG_GetError());
    }
    else
    {
        printf("SDL initilazed images successfully !!\n");
    }
}
void ttfinit()
{
    if(TTF_Init() != 0)
    {
        printf("ERROR initializing TTF : %s . \n",TTF_GetError());
    }
    else
    {
        printf("TTF init successfully !!\n");
    }
}
///////////////
void initAll()
{
	videoinit();
	audioinit();
	imageinit();
	ttfinit();
}
void initPos()
{
    pos.backpos.x = 0;
    pos.backpos.y = 0;

    pos.robot.x = 20;
    pos.robot.y = 300;

    pos.quest.x = 20;
    pos.quest.y = 0;

    pos.logopos.x = 0;
    pos.logopos.y = 650;

    pos.empty1.x = 50;
    pos.empty1.y = 370;

    pos.empty2.x = 400;
    pos.empty2.y = 370;

    pos.empty3.x = 50;
    pos.empty3.y = 490;

    pos.empty4.x = 400;
    pos.empty4.y = 490;

    pos.qtext.x = 100;
    pos.qtext.y = 190;

    pos.a1text.x = 100;
    pos.a1text.y = 420;

    pos.a2text.x = 450;
    pos.a2text.y =  420;

    pos.a3text.x = 100;
    pos.a3text.y = 550;

    pos.a4text.x = 450;
    pos.a4text.y = 550;

    pos.score1.x = 0;
    pos.score1.y = 0;

    pos.score2.x = 80;
    pos.score2.y = 0;

    pos.score3.x = 160;
    pos.score3.y = 0;

    pos.scoretext.x = 300;
    pos.scoretext.y = 0;


}
