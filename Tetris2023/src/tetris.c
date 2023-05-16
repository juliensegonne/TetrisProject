#include "tetris.h"

Color_Block Tab[PLAYFIELD_WIDTH][PLAYFIELD_HEIGHT];

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
            Tab[x][y] = BLUE;
        }
    }
    printf("le tableau dest rempli\n");

}

void lockTetromino() {

}

void render_score() {

}

void updateTetris() {
}

void spawn_tetromino() {

}

bool can_render_tetromino(Tetromino_Movement tetra_request, uint8_t block_render_queue[]) {

    return true;
}

bool render_current_tetromino(Tetromino_Movement tetra_request) {

    return false;
}

bool render_tetromino(Tetromino_Movement tetra_request, uint8_t current_coords[]) {

    return true;
}
