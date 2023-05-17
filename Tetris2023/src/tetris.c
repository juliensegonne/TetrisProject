#include "tetris.h"

Tetris_Action TETROMINO_ACTION;

Color_Block Tab[PLAYFIELD_WIDTH][PLAYFIELD_HEIGHT];
tetromino tetrominoCourant;
tetromino tetrominoFutur;


void draw_playing_field() {                //done

    // loop var
    printf("dans drawplayingfield\n");
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
    printf("le tableau est rempli\n");
    spawn_tetromino();
}

void lockTetromino(tetromino tetr) {
    for (int i=0; i<4;i++) {
        Tab[tetr.coords[i].x][tetr.coords[i].y] = tetr.couleur;
    }
    spawn_tetromino();
}

void render_score() {

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

void updateTetris() {
    SDL_Delay(400);
    draw_playing_field();    

    if (TETROMINO_ACTION == RIGHT) {
        printf("dedans\n");
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
            printf("dedDEDVDs\n");
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
            printf("dedDEDVDs\n");
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
            printf("dedDEDVDs\n");
        }
       
    }

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
    }

    affichageTetr(tetrominoCourant);


}

void spawn_tetromino() {
    int r = rand()%7;
    if (r==0){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2-2;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[2].y = 0;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[3].y= 0;
        tetrominoCourant.couleur = BLUE;
    }
    if (r==1){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[2].y = 1;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[3].y= 1;
        tetrominoCourant.couleur = GREEN;
    }
    if (r==2){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[2].y = 0;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[3].y= 1;
        tetrominoCourant.couleur = PURPLE;
    }
    if (r==3){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[2].y = 0;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[3].y= 1;
        tetrominoCourant.couleur = WHITE;
    }
    if (r==4){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[2].y = 0;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[3].y= 1;
        tetrominoCourant.couleur = RED;
    }
    if (r==5){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[0].y = 0;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[2].y = 1;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[3].y= 1;
        tetrominoCourant.couleur = ORANGE;
    }
    if (r==6){
        tetrominoCourant.coords[0].x = PLAYFIELD_WIDTH/2-1;
        tetrominoCourant.coords[0].y = 1;
        tetrominoCourant.coords[1].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[1].y = 0;
        tetrominoCourant.coords[2].x = PLAYFIELD_WIDTH/2;
        tetrominoCourant.coords[2].y = 1;
        tetrominoCourant.coords[3].x= PLAYFIELD_WIDTH/2+1;
        tetrominoCourant.coords[3].y= 0;
        tetrominoCourant.couleur = CYAN;
    }

    draw_playing_field();
    affichageTetr(tetrominoCourant);
}

/*bool can_render_tetromino(Tetromino_Movement tetra_request, uint8_t block_render_queue[]) {

    return true;
}

bool render_current_tetromino(Tetromino_Movement tetra_request) {

    return false;
}

bool render_tetromino(Tetromino_Movement tetra_request, uint8_t current_coords[]) {

    return true;
}*/