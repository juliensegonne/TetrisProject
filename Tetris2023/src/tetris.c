#include "tetris.h"

Tetris_Action TETROMINO_ACTION;

Color_Block Tab[PLAYFIELD_WIDTH][PLAYFIELD_HEIGHT];
tetromino tetrominoCourant;
tetromino tetrominoFutur;
int score;


void draw_playing_field() {                //done

    for (int x=0;x<PLAYFIELD_WIDTH;x++){
        for (int y=0;y<PLAYFIELD_HEIGHT;y++){
            draw_block(x,y,Tab[x][y]);
        }
    }
   
}


void initTetris() {
    for (int x=0;x<PLAYFIELD_WIDTH;x++){
        for (int y=0;y<PLAYFIELD_HEIGHT;y++){
            Tab[x][y] = EMPTY;
        }
    }
    score = 0;
    draw_score(score);
    spawn_tetromino();
}

void lockTetromino(tetromino tetr) {
    for (int i=0; i<4;i++) {
        Tab[tetr.coords[i].x][tetr.coords[i].y] = tetr.couleur;
    }
    spawn_tetromino();
}

void affichageTetr(tetromino tetr) {
    for (int i =0; i<4;i++) {
        draw_block(tetr.coords[i].x,tetr.coords[i].y,tetr.couleur);
    }
}

void translatTetr(tetromino tetr,int dx,int dy) {   //marche pas... faille dans le non passage par adresse ?
    for (int i =0; i<4;i++) {
        tetr.coords[i].x = tetr.coords[i].x +dx;
        tetr.coords[i].y = tetr.coords[i].y +dy;
    }
}

void elimligne() {
    bool ligneRemplie;
    for (int y=0;y<PLAYFIELD_HEIGHT;y++){
        ligneRemplie = true;
        for (int x=0;x<PLAYFIELD_WIDTH;x++){
            if (Tab[x][y] == EMPTY) {
                ligneRemplie = false;
            }
        }
        if (ligneRemplie) {
            score = score+1000;
            for (int j=y;j>=0;j--){
                if (j==0){
                    for (int i=0;i<PLAYFIELD_WIDTH;i++){
                        Tab[i][j]=EMPTY;
                    }
                }

                else{
                    for (int i=0;i<PLAYFIELD_WIDTH;i++){
                        Tab[i][j]=Tab[i][j-1];
                    }
                }
            }
            draw_score(score);
        }

    }
}

void updateTetris() {
    SDL_Delay(100);
    draw_playing_field();    
    draw_background();
    if (TETROMINO_ACTION == RIGHT) {
        tetrominoFutur = tetrominoCourant;
        for (int i =0; i<4;i++) {
        tetrominoFutur.coords[i].x = tetrominoFutur.coords[i].x +1;
    }
        bool positionFuturePossible = true;

        for (int i=0; i<4;i++) {
            if (Tab[tetrominoFutur.coords[i].x][tetrominoFutur.coords[i].y] != EMPTY || tetrominoFutur.coords[i].y >= PLAYFIELD_HEIGHT
                 || tetrominoFutur.coords[i].x >= PLAYFIELD_WIDTH|| tetrominoFutur.coords[i].x < 0) {
                positionFuturePossible = false;
            }
        }  

        if (positionFuturePossible) {
            tetrominoCourant = tetrominoFutur;
        }
    }
    if (TETROMINO_ACTION == LEFT) {
        tetrominoFutur = tetrominoCourant;
        for (int i =0; i<4;i++) {
        tetrominoFutur.coords[i].x = tetrominoFutur.coords[i].x -1;
    }
        bool positionFuturePossible = true;

        for (int i=0; i<4;i++) {
            if (Tab[tetrominoFutur.coords[i].x][tetrominoFutur.coords[i].y] != EMPTY || tetrominoFutur.coords[i].y >= PLAYFIELD_HEIGHT
                 || tetrominoFutur.coords[i].x >= PLAYFIELD_WIDTH|| tetrominoFutur.coords[i].x < 0) {
                positionFuturePossible = false;
            }
        }  

        if (positionFuturePossible) {
            tetrominoCourant = tetrominoFutur;
        }
       
    }
    if (TETROMINO_ACTION == DOWN) {
        tetrominoFutur = tetrominoCourant;
        for (int i =0; i<4;i++) {
        tetrominoFutur.coords[i].y = tetrominoFutur.coords[i].y + 1 ;
    }
        bool positionFuturePossible = true;

        for (int i=0; i<4;i++) {
            if (Tab[tetrominoFutur.coords[i].x][tetrominoFutur.coords[i].y] != EMPTY || tetrominoFutur.coords[i].y >= PLAYFIELD_HEIGHT
                 || tetrominoFutur.coords[i].x >= PLAYFIELD_WIDTH|| tetrominoFutur.coords[i].x < 0) {
                positionFuturePossible = false;
            }
        }  

        if (positionFuturePossible) {
            tetrominoCourant = tetrominoFutur;
        }
       
    }
    if (TETROMINO_ACTION == ROTATE) {
        tetrominoFutur = tetrominoCourant;
        int temp;
//centrage
    
        for (int i =0; i<4;i++) {
            tetrominoFutur.coords[i].y = tetrominoFutur.coords[i].y - tetrominoCourant.coords[0].y ;
            tetrominoFutur.coords[i].x = tetrominoFutur.coords[i].x - tetrominoCourant.coords[0].x ;
        }
//rotation
        for (int i =0; i<4;i++) {
            temp = tetrominoFutur.coords[i].x ;
            tetrominoFutur.coords[i].x = -tetrominoFutur.coords[i].y ;
            tetrominoFutur.coords[i].y = temp ;
        }
        //remet a la place
        for (int i =0; i<4;i++) {
            tetrominoFutur.coords[i].y = tetrominoFutur.coords[i].y + tetrominoCourant.coords[0].y ;
            tetrominoFutur.coords[i].x = tetrominoFutur.coords[i].x + tetrominoCourant.coords[0].x ;
        }

        bool positionFuturePossible = true;

        for (int i=0; i<4;i++) {
            if (Tab[tetrominoFutur.coords[i].x][tetrominoFutur.coords[i].y] != EMPTY || tetrominoFutur.coords[i].y >= PLAYFIELD_HEIGHT
                 || tetrominoFutur.coords[i].x >= PLAYFIELD_WIDTH|| tetrominoFutur.coords[i].x < 0) {
                positionFuturePossible = false;
            }
        }  

        if (positionFuturePossible) {
            tetrominoCourant = tetrominoFutur;
        }
    }

    if (boucle%5 ==0) {
        for (int i =0; i<4;i++) {
            tetrominoFutur.coords[i].y = tetrominoCourant.coords[i].y +1;
            tetrominoFutur.coords[i].x = tetrominoCourant.coords[i].x ;
        }
        tetrominoFutur.couleur = tetrominoCourant.couleur ;

        bool positionFuturePossible = true;

        for (int i=0; i<4;i++) {
            if (Tab[tetrominoFutur.coords[i].x][tetrominoFutur.coords[i].y] != EMPTY || tetrominoFutur.coords[i].y >= PLAYFIELD_HEIGHT) {
                positionFuturePossible = false;
            }
        }

        if (positionFuturePossible) {
            tetrominoCourant = tetrominoFutur;
        }

        else {
            lockTetromino(tetrominoCourant);
            elimligne();
        }

        

    }
    affichageTetr(tetrominoCourant);
}

void spawn_tetromino() {
    int r = rand()%7;
    if (r==0){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2-2;
        tetrominoCourant.coords[2].y = 0;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[3].y= 0;
        tetrominoCourant.couleur = BLUE;
    }
    if (r==1){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[2].y = 1;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[3].y= 1;
        tetrominoCourant.couleur = GREEN;
    }
    if (r==2){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[2].y = 0;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[3].y= 1;
        tetrominoCourant.couleur = PURPLE;
    }
    if (r==3){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[2].y = 0;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[3].y= 1;
        tetrominoCourant.couleur = WHITE;
    }
    if (r==4){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[2].y = 0;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[3].y= 1;
        tetrominoCourant.couleur = RED;
    }
    if (r==5){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[2].y = 1;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[3].y= 1;
        tetrominoCourant.couleur = ORANGE;
    }
    if (r==6){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[0].y = 1;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[2].y = 1;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[3].y= 0;
        tetrominoCourant.couleur = CYAN;
    }

    bool spawnPossible = true;

    for (int i=0; i<4;i++) {
        if (Tab[tetrominoCourant.coords[i].x][tetrominoCourant.coords[i].y] != EMPTY) {
            spawnPossible = false;
            }
        }
    
    if (!spawnPossible) {
        SDL_SetRenderDrawColor(render, 255, 0,0, 255);
        SDL_RenderClear(render);
        SDL_RenderPresent(render);
        SDL_Delay(3000);
        exit(0);
    }
    draw_playing_field();
    affichageTetr(tetrominoCourant);
}
