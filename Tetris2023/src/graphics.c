#include "graphics.h"   //done for the moment

                        
void init_graphics() {                           //pas texture pas police
    int statut = EXIT_FAILURE;
    
    /* Initialisation, création de la fenêtre et du renderer. */
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        exit(1);
    }
    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        exit(1);
    }
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == render)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        exit(1);
    }

    



}


void preRender() {                               //done

    SDL_SetRenderTarget(render, display);


}

void updateRender() {                                   //not necessary

    // lazily update the screen only if render operations are queued

    SDL_RenderPresent(render);

}

void draw_block(uint8_t x, uint8_t y, Color_Block color) {      //done 
    int a = 255;
    //printf("dans drawblock\n");
    SDL_Rect carre = {x*(BLOCK_SIZE+1)+1,y*(BLOCK_SIZE+1)+1,BLOCK_SIZE,BLOCK_SIZE};
    
    if (color==BLUE){ 
        SDL_SetRenderDrawColor(render,0,0,255,a);}   // on peut faire sxitch case 
    if (color==PURPLE){ 
        SDL_SetRenderDrawColor(render,105,0,170,a);}
    if (color==GREEN){ 
        SDL_SetRenderDrawColor(render,0,255,0,a);}
    if (color==WHITE){ 
        SDL_SetRenderDrawColor(render,255,255,255,a);}
    if (color==RED){ 
        SDL_SetRenderDrawColor(render,255,0,0,a);}
    if (color==ORANGE){ 
        SDL_SetRenderDrawColor(render,255,128,0,a);}
    if (color==CYAN){ 
        SDL_SetRenderDrawColor(render,0,255,255,a);}
    if (color==EMPTY){ 
        SDL_SetRenderDrawColor(render,40,40,40,a);}
        

    
    SDL_RenderFillRect(render,&carre);

}

void draw_score(int score){
    TTF_Font* font;
    font = TTF_OpenFont("/home/sdl/Bureau/In104Projet/Tetris2023/src/font/Inconsolata-Regular.ttf", 30);
    if(font != 0){
        SDL_Color violet = {174, 55, 255}; //attention ce n'est pas un Uint32
        char scoreString[20];
        sprintf(scoreString,"%d",score);
	    SDL_Surface* texte = TTF_RenderText_Blended(font, scoreString, violet) ;
        SDL_Texture* texturedetexte = SDL_CreateTextureFromSurface(render, texte);

        SDL_Rect rectNoir = {PLAYFIELD_WIDTH * (BLOCK_SIZE + 1)+10,60,140,50};
        SDL_SetRenderDrawColor(render,0,0,0,255);
        SDL_RenderFillRect(render,&rectNoir);

        if (score==0) {
            SDL_Rect rectScore = {PLAYFIELD_WIDTH * (BLOCK_SIZE + 1)+115,60,35,50};
            SDL_RenderCopy(render, texturedetexte,NULL,&rectScore);
        }
        else {
            SDL_Rect rectScore = {PLAYFIELD_WIDTH * (BLOCK_SIZE + 1)+10,60,140,50};
            SDL_RenderCopy(render, texturedetexte,NULL,&rectScore);
        }
    }   
}

void draw_background(){
    TTF_Font* font;
    font = TTF_OpenFont("/home/sdl/Bureau/In104Projet/Tetris2023/src/font/Inconsolata-Regular.ttf", 30);
    if(font != 0){
        SDL_Color violet = {174, 55, 255}; //attention ce n'est pas un Uint32
	    SDL_Surface* texte = TTF_RenderText_Blended(font, "SCORE :", violet) ;
        SDL_Texture* texturedetexte = SDL_CreateTextureFromSurface(render, texte);
        SDL_Rect rectScore = {PLAYFIELD_WIDTH * (BLOCK_SIZE + 1)+10,5,180,50};
        SDL_RenderCopy(render, texturedetexte,NULL,&rectScore);
    }   
}

void cleanup_graphics() {                      //done
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}
