#include "fn.h"
#include "structs.h"

void mediaLoad()
{


	images.background = NULL;
	images.click1 = NULL;
	images.click2 = NULL;
	images.correct = NULL;
	images.emptya1 = NULL;
	images.emptya2 = NULL;
	images.emptyb1 = NULL;
	images.emptyb2 = NULL;
	images.emptyc1 = NULL;
	images.emptyc2 = NULL;
	images.emptyd1 = NULL;
	images.emptyd2 = NULL;
	images.question = NULL;
	images.wrong = NULL;
	images.logo = NULL;
	images.robot = NULL;
	mouse.mouse0 = NULL;
	mouse.mouse1 = NULL;
	images.score0 = NULL;
	images.score1 = NULL;
	font = NULL;

	images.background = IMG_Load("src/img/back1.jpg");
	mouse.mouse0 = IMG_Load("src/img/click0.png");
	mouse.mouse1 = IMG_Load("src/img/click1.png");
	images.logo = IMG_Load("src/img/logoPetit.png");
	images.correct =  IMG_Load("src/img/correctcc.png");
	images.wrong = IMG_Load("src/img/false.jpg");
	images.question = IMG_Load("src/img/text.png");
	images.emptya0 = IMG_Load("src/img/empty1.png");
	images.emptyb0 = IMG_Load("src/img/empty2.png");
	images.emptyc0 = IMG_Load("src/img/empty3.png");
	images.emptyd0 = IMG_Load("src/img/empty4.png");
	images.emptya1 = IMG_Load("src/img/emptya1.png");
	images.emptya2 = IMG_Load("src/img/emptya2.png");
	images.emptyb1 = IMG_Load("src/img/emptyb1.png");
	images.emptyb2 = IMG_Load("src/img/emptyb2.png");
	images.emptyc1 = IMG_Load("src/img/emptyc1.png");
	images.emptyc2 = IMG_Load("src/img/emptyc2.png");
	images.emptyd1 = IMG_Load("src/img/emptyd1.png");
	images.emptyd2 = IMG_Load("src/img/emptyd2.png");
	images.robot = IMG_Load("src/img/gif2.png");
	images.score0 = IMG_Load("src/img/score0.png");
	images.score1 = IMG_Load("src/img/score1.png");
    font = TTF_OpenFont("src/fonts/arial.ttf",20);

	if(images.background == NULL)
	{
		printf("Error load background : %s . \n",SDL_GetError());
	}
	else
	{
		printf("background laoded . \n");
	}
	if(mouse.mouse0 == NULL)
	{
		printf("Error load click1 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("click1 laoded . \n");
	}
	if(mouse.mouse1 == NULL)
	{
		printf("Error load click2 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("click2 laoded . \n");
	}
	if(images.correct == NULL)
	{
		printf("Error load correct : %s . \n",SDL_GetError());
	}
	else
	{
		printf("correct laoded . \n");
	}
	if(images.wrong == NULL)
	{
		printf("Error load false : %s . \n",SDL_GetError());
	}
	else
	{
		printf("false laoded . \n");
	}
	///////
	if(images.emptya0 == NULL)
	{
		printf("Error load empty A0 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty a0 laoded . \n");
	}
	if(images.emptyb0 == NULL)
	{
		printf("Error load empty B0 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty b0 laoded . \n");
	}
	if(images.emptyc0 == NULL)
	{
		printf("Error load empty C0 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty c0 laoded . \n");
	}
	if(images.emptyd0 == NULL)
	{
		printf("Error load empty D0 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty d0 laoded . \n");
	}
	///////
	if(images.emptya1 == NULL)
	{
		printf("Error load empty A1 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty a1 laoded . \n");
	}
	if(images.emptya2 == NULL)
	{
		printf("Error load empty A2 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty a2 laoded . \n");
	}
	if(images.emptyb1 == NULL)
	{
		printf("Error load empty B1 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty b1 laoded . \n");
	}
	if(images.emptyb2 == NULL)
	{
		printf("Error load empty B2 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty b2 laoded . \n");
	}
    if(images.emptyc1 == NULL)
	{
		printf("Error load empty C1 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty c1 laoded . \n");
	}
    if(images.emptyc2 == NULL)
	{
		printf("Error load empty C2 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty c2 laoded . \n");
	}
	if(images.emptyd1 == NULL)
	{
		printf("Error load empty D1 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty d1 laoded . \n");
	}
	if(images.emptyd2 == NULL)
	{
		printf("Error load empty D2 : %s . \n",SDL_GetError());
	}
	else
	{
		printf("empty d2 laoded . \n");
	}
	if(images.question == NULL)
	{
		printf("Error load question : %s . \n",SDL_GetError());
	}
	else
	{
		printf("question laoded . \n");
	}
	if(images.logo == NULL)
	{
		printf("Error load LOGO: %s . \n",SDL_GetError());
	}
	else
	{
		printf("logo laoded . \n");
	}
	if(images.robot == NULL)
	{
        printf(" ERROR load Robo : %s . \n",SDL_GetError());
	}
	else
	{
        printf("robot loaded . \n");
	}
	if(images.score0 == NULL)
	{
        printf("Error load score 0 : %s . \n",SDL_GetError());
    }
    else
    {
        printf("score 0 loaded . \n");
    }
    if(images.score1 == NULL)
	{
        printf("Error load score 1 : %s . \n",SDL_GetError());
    }
    else
    {
        printf("score 1 loaded . \n");
    }
	if(font == NULL)
	{
        printf("ERROR loading font : %s !! \n",TTF_GetError());
	}
	else
	{
        printf("Font loaded . \n");
	}
}
