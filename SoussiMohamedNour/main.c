#include "fn.h"
#include "structs.h"

int main()
{

    SDL_Event e;

    initAll();
    initPos();

    //menuPlay();

    gameLoop(e);


    closeAll();
    return 0;
}
