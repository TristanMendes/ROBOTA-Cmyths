#include "fn.h"
#include "structs.h"

void closeAudio()
{

	Mix_FreeMusic(sounds.menuSong);
	Mix_FreeChunk(sounds.correctAnswer);
	Mix_FreeChunk(sounds.wrongAnswer);

	printf("Memory for MUSIC FREE !! \n");
}

void closeImages()
{


	SDL_FreeSurface(screen);
	SDL_FreeSurface(images.background);
	SDL_FreeSurface(images.click1);
	SDL_FreeSurface(images.click2);
	SDL_FreeSurface(images.correct);
	SDL_FreeSurface(images.wrong);
	SDL_FreeSurface(images.question);
	SDL_FreeSurface(images.emptya1);
	SDL_FreeSurface(images.emptya2);
	SDL_FreeSurface(images.emptya0);
	SDL_FreeSurface(images.emptyb1);
	SDL_FreeSurface(images.emptyb2);
	SDL_FreeSurface(images.emptyb0);
	SDL_FreeSurface(images.emptyc1);
	SDL_FreeSurface(images.emptyc2);
	SDL_FreeSurface(images.emptyc0);
	SDL_FreeSurface(images.emptyd1);
	SDL_FreeSurface(images.emptyd2);
	SDL_FreeSurface(images.emptyd0);
    SDL_FreeSurface(text.answertext1);
    SDL_FreeSurface(text.answertext2);
    SDL_FreeSurface(text.answertext3);
    SDL_FreeSurface(text.answertext4);
    SDL_FreeSurface(text.questiontextsurface);
	printf("Memory for IMAGES FREE !! \n");

}

void closeAll()
{
	closeAudio();
	closeImages();
	SDL_Quit();
	TTF_CloseFont(font);
	TTF_Quit();
}
