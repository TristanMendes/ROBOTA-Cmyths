#include "fn.h"
#include "structs.h"


int getkeyboard(SDL_Event e)
{
    int press;
    press = 0;
    SDL_PollEvent(&e);

    switch(e.type)
    {
        case SDL_KEYDOWN:
            switch(e.key.keysym.sym)
            {
                case SDLK_a:
                {
                    printf(" input : A . \n");
                    press = 1;
                    //return press;
                }break;
                case SDLK_b:
                {
                    printf(" input : B . \n");
                    press = 2;
                    //return press;
                }break;
                case SDLK_c:
                {
                    printf(" input : C . \n");
                    press = 3;
                    //return press;
                }break;
                case SDLK_d:
                {
                    printf(" input : D . \n");
                    press = 4;
                    //return press;
                }break;

            }
    }
    return press;
}

int getMouse(SDL_Event e)
{
    int click ;
    click =0;
    SDL_PollEvent(&e);

    switch(e.type)
    {
        case SDL_MOUSEBUTTONDOWN:
            switch(e.button.button)
            {
               case SDL_BUTTON_LEFT:
               {
                   if((e.button.x > 60 && e.button.x< 60+button_width) && (e.button.y > 360 && e.button.y < 360+button_height))
                   {
                    printf("A inout mouse! \n");
                    click = 1;
                   }
                   if((e.button.x > 400 && e.button.x< 400+button_width) && (e.button.y > 380 && e.button.y < 380+button_height))
                   {
                    printf("B inout mouse! \n");
                    click = 2;
                   }
                   if((e.button.x > 60 && e.button.x< 60+button_width) && (e.button.y > 490 && e.button.y < 490+button_height))
                   {
                    printf("C inout mouse! \n");
                    click = 3;
                   }
                   if((e.button.x > 400 && e.button.x< 400+button_width) && (e.button.y > 500 && e.button.y < 500+button_height))
                   {
                    printf("D inout mouse! \n");
                    click = 4;
                   }
               }break;
            }
    }
    return click;
}
