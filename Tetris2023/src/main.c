#include "main.h"
int boucle;
int main(int argc, const char *argv[]) {
    srand(time(0));
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
    printf("init atteint\n");
    init();
    boucle =0;
    bool quit = false;

    while(!quit) {
        boucle++;
        preRender();

        getInput();

        updateTetris();     //les calculs


        updateRender();     //affiche ce qu'il y a dans le renderer
        
        // Set to ~60 fps.
        // 1000 ms/ 60 fps = 1/16 s^2/frame
    }

    return 0;
}
