#ifndef FN_H_INCLUDED
#define FN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 700

#define button_width 300
#define button_height 200

#define max_length 150



void audioinit();
void imageinit();
void ttfinit();
void initAll();
void initPos();
///AUDIO & IMAGES FUNCTIONS
void mediaLoad();
void musicLoad();
void menuPlay();
void correctSound();
void wrongSound();


///FREE MEMORY FUNCTIONS
void closeAudio();
void closeImages();
void closeAll();

void displayScreen();
void displayQuestions();
void displayText();
///TAKE INPUT FROM KEYBOARD
int getkeyboard(SDL_Event e);
int getMouse(SDL_Event e);
void getAnswer(SDL_Event e,int scorenb, int health);

///void readQuestions();
void openfile();
int getRandom();
void loadtext();
int answernumber();

void gameLoop(SDL_Event ee);
void scoreLIFE(SDL_Event e,int scorenb,int health);
#endif // FN_H_INCLUDED
