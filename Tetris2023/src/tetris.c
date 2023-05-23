#include "tetris.h"

Tetris_Action TETROMINO_ACTION;

Color_Block Tab[PLAYFIELD_WIDTH][PLAYFIELD_HEIGHT];
tetromino tetrominoCourant;
tetromino tetrominoFutur;
int score;



void draw_playing_field() {  //draws all cells of the array Tab     

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
    hardMode = false;
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

void elimligne() {
    bool ligneRemplie;
    for (int y=0;y<PLAYFIELD_HEIGHT;y++){
        ligneRemplie = true;
        for (int x=0;x<PLAYFIELD_WIDTH;x++){
            if (Tab[x][y] == EMPTY) {
                ligneRemplie = false;
            }
        }
        if (ligneRemplie) {   // when a line is completed, we update the score and translate down the lines of the array that were above the full line 
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
            draw_score(score); //we update the display of the score only when a line is completed
        }

    }
}

void updateTetris() {
    if(hardMode) {
        SDL_Delay(80);
    }
    else {
        SDL_Delay(100);
    }
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
    
        for (int i =0; i<4;i++) {   //center the tetromino
            tetrominoFutur.coords[i].y = tetrominoFutur.coords[i].y - tetrominoCourant.coords[0].y ;
            tetrominoFutur.coords[i].x = tetrominoFutur.coords[i].x - tetrominoCourant.coords[0].x ;
        }

        for (int i =0; i<4;i++) {  //rotate the tetromino according to the rotation matrix
            temp = tetrominoFutur.coords[i].x ;
            tetrominoFutur.coords[i].x = -tetrominoFutur.coords[i].y ;
            tetrominoFutur.coords[i].y = temp ;
        }
        
        for (int i =0; i<4;i++) { //replace the tetromino at its original place
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

    if (TETROMINO_ACTION == DROP) {
        hardMode = !hardMode;
    }

    /*if we are in the hard mode, the player can do only one action (rotation,translation...) before the tetromino is going down 
     in normal mode, he can do 5 actions, that's why we translate the tetromnio down only one in five time*/

    if (boucle%5 ==0 || hardMode) { 
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

        if (positionFuturePossible) { // if the position below the current tetromino is free, we translate it
            tetrominoCourant = tetrominoFutur;
        }

        else { //else, we lock it in the array and check if it completes a line
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
    
    if (!spawnPossible) {  //if its not possible to spawn a tetromino, the game is lost, it displays "GAME OVER" on full screen and automatically exit after 3 seconds
        printGameOver();
        SDL_RenderPresent(render);
        SDL_Delay(3000);
        exit(0);
    }
    draw_playing_field();
    affichageTetr(tetrominoCourant);
}
