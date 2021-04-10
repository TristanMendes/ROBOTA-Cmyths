#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include "structs.h"
#include "fn.h"

SDL_Surface* screen;
TTF_Font* font;

struct Img
{
    SDL_Surface* background;
	SDL_Surface* click1;
	SDL_Surface* click2;
	SDL_Surface* correct;
	SDL_Surface* wrong;
	SDL_Surface* question;
	SDL_Surface* emptya0;
	SDL_Surface* emptyb0;
	SDL_Surface* emptyc0;
	SDL_Surface* emptyd0;
	SDL_Surface* emptya1;
	SDL_Surface* emptya2;
	SDL_Surface* emptyb1;
	SDL_Surface* emptyb2;
	SDL_Surface* emptyc1;
	SDL_Surface* emptyc2;
	SDL_Surface* emptyd1;
	SDL_Surface* emptyd2;
	SDL_Surface* logo;
	SDL_Surface* robot;
	///hearts images
	SDL_Surface* score0;
	SDL_Surface* score1;

}images;

struct MouseState
{
    SDL_Surface* mouse0;
    SDL_Surface* mouse1;

}mouse;
struct Beats
{
	Mix_Music* menuSong;
	Mix_Chunk* wrongAnswer;
	Mix_Chunk* correctAnswer;
}sounds;
struct TextQA
{
    SDL_Surface* questiontextsurface;
    SDL_Surface* answertext1;
    SDL_Surface* answertext2;
    SDL_Surface* answertext3;
    SDL_Surface* answertext4;
    SDL_Surface* score;
}text;

struct Positions
{
    SDL_Rect backpos;
    SDL_Rect logopos;
    SDL_Rect robot;
    SDL_Rect quest;
    SDL_Rect empty1;
    SDL_Rect empty2;
    SDL_Rect empty3;
    SDL_Rect empty4;
    SDL_Rect qtext;
    SDL_Rect a1text;
    SDL_Rect a2text;
    SDL_Rect a3text;
    SDL_Rect a4text;
    SDL_Rect score1;
    SDL_Rect score2;
    SDL_Rect score3;
    SDL_Rect scoretext;

}pos;

//typedef
struct QuesAnswer
{
    char questionText[200];
    char answerA[200] ;
    char answerB[200];
    char answerC[200];
    char answerD[200];
    char correctanswer[200];
    char score[10];
}qa;


#endif // STRUCTS_H_INCLUDED
