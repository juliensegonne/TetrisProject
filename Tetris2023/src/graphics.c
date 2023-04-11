#include "graphics.h"


void init_graphics() {
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
}

void setRenderChanged() {
    render_changed = true;
}

void preRender() {

    SDL_SetRenderTarget(render, display);


}

void updateRender() {

    // lazily update the screen only if render operations are queued
    if(render_changed) {

    }
}

void draw_block(uint8_t x, uint8_t y, uint32_t color) {


}

void cleanup_graphics() {
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}
