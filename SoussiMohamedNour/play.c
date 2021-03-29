#include "fn.h"
#include "structs.h"

void gameLoop(SDL_Event ee)
{

    bool quit = false;
    int score;
    int hearts;
    //char scoretext[5];
    hearts = 3;
    score = 0;

    displayScreen();
    loadtext();
    displayText();
    displayQuestions();

    while(!quit)
    {
        while(SDL_PollEvent(&ee) != 0)
        {
            if(ee.type == SDL_QUIT)
            {
                quit = true;
            }
            else
            {
                getAnswer(ee,score,hearts);

            }
        }

    }


}
