#include "main.h"
int boucle;
bool hardMode;

int main(int argc, const char *argv[]) {

    srand(time(0));   //initiate to the current time to have a good randomness

    // Start up SDL, and make sure it went ok
    //
    uint32_t flags = SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError());

        return 1;
    }

    atexit(cleanup);
    init();
    boucle =0;
    bool quit = false;

    while(!quit) {
        boucle++;
        preRender();

        getInput();

        updateTetris(); 


        updateRender();     //affiche ce qu'il y a dans le renderer
    }

    return 0;
}
