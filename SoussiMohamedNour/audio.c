#include "fn.h"
#include "structs.h"

void musicLoad()
{
	sounds.menuSong = NULL;
	sounds.correctAnswer = NULL;
	sounds.wrongAnswer = NULL;

	Mix_OpenAudio(22050,AUDIO_S16SYS,2,640);
	sounds.menuSong = Mix_LoadMUS("src/audio/aria.mp3");
	sounds.correctAnswer = Mix_LoadWAV("src/audio/correct.wav");
	sounds.wrongAnswer = Mix_LoadWAV("src/audio/false.wav");

	if(sounds.menuSong == NULL)
	{
		printf("ERROR loading menu Music %s \n",Mix_GetError());
	}
	else
	{
		printf("Menu music loaded . \n");
	}
	if(sounds.correctAnswer == NULL)
	{
		printf("ERROR loading correct Music %s \n",Mix_GetError());
	}
	else
	{
		printf("Correct music loaded . \n");
	}
	if(sounds.wrongAnswer == NULL)
	{
		printf("ERROR loading wrong Music %s \n",Mix_GetError());
	}
	else
	{
		printf("wrong music loaded . \n");
	}

}

void menuPlay()
{
	musicLoad();
	Mix_PlayMusic(sounds.menuSong,-1);
	printf("Menu music ON!!\n");
}
void correctSound()
{
	musicLoad();
	Mix_PlayChannel(-1,sounds.correctAnswer,0);
	printf("Correct Music played!! \n");
}
void wrongSound()
{
	musicLoad();
	Mix_PlayChannel(-1,sounds.wrongAnswer,0);
	printf("False Music played!! \n");
}
