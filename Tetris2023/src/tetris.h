#pragma once
#include "defs.h"           
#include "utility.h"
#include "graphics.h"
extern int boucle;
extern bool hardMode;

#ifndef _TETRIS_CONSTANTS
#define _TETRIS_CONSTANTS


typedef struct {
    int x;
    int y;
} block;

typedef struct {
    block coords[4];
    Color_Block couleur;
} tetromino;


typedef enum {
    UP,LEFT,RIGHT,DOWN,ROTATE,RESTART,DROP,AUTO_DROP,NONE
} Tetris_Action;


// default tetris action
// defines the action to apply to current tetromino
extern Tetris_Action TETROMINO_ACTION;


// simple array to store coords of blocks rendered on playing field.
// Each tetromino has 4 blocks with total of 4 coordinates.
//
// To access a coord, if 0 <= i < 4, then
//      x = i * 2, y = x + 1
//
static uint8_t CURRENT_TETROMINO_COORDS[8] = {0};
static uint8_t GHOST_TETROMINO_COORDS[8] = {0};

//static Tetromino_Movement CURRENT_TETROMINO;


// bool array of the playfield.
// Use row-major order convention to access (x,y) coord.
// Origin is 'top-left' -- like matrices.
// Zero-based indexing.
static Color_Block playfield[PLAYFIELD_HEIGHT * PLAYFIELD_WIDTH];


// Every time AUTO_DROP event is executed, the current tetromino will drop by one
// block. If the drop is unsucessful equal to the number of times of lock_delay_threshold,
// the tetromino freezes in place.
//
// Lock when ++lock_delay_count % lock_delay_threshold == 0
const static uint8_t lock_delay_threshold = 2;
static uint8_t lock_delay_count = 0;

// Queue to determine the next tetromino.
// Knuth shuffle algorithm is applied.
static uint8_t tetromino_queue[7 * 4];
static uint8_t tetromino_queue_size = 7*4;
static uint8_t current_queue_index = 0;


static SDL_TimerID cb_timer = 0;


#endif


void draw_playing_field();
//Color_Block get_playfield(uint8_t x, uint8_t y);
//void set_playfield(uint8_t x, uint8_t y, Color_Block color);

void initTetris();
void updateTetris();
void lockTetromino();

void spawn_tetromino();
//bool render_tetromino(Tetromino_Movement tetra_request, uint8_t current_coords[]);
//bool render_current_tetromino(Tetromino_Movement tetra_request);
