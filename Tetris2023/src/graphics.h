#pragma once
#include "defs.h"                             //all done



extern SDL_Window *window;
extern SDL_Renderer *render;
extern SDL_Texture *display;
extern TTF_Font *gFont;


typedef enum {
    BLUE,GREEN,PURPLE,WHITE,RED,ORANGE,CYAN,EMPTY
} Color_Block;


// This tracks whether to update the render.
// Any procedure that has updated the render should set this to true.
extern bool render_changed;

void init_graphics();
void cleanup_graphics();


void draw_block(uint8_t x, uint8_t y, Color_Block color);


void preRender();
void updateRender();

