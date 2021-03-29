#include "fn.h"
#include "structs.h"

void scoreLIFE(SDL_Event e,int score,int health)
{

    loadtext();
    displayText();
    displayQuestions();
    getAnswer(e,score,health);

}
