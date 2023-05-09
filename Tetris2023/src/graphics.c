#include "graphics.h"


void init_graphics() {
    
}

void setRenderChanged() {             //done
    render_changed = true;
}

void preRender() {                               //done

    SDL_SetRenderTarget(render, display);


}

void updateRender() { 

    // lazily update the screen only if render operations are queued
    if(render_changed) {

    }
}

void draw_block(uint8_t x, uint8_t y, uint32_t color) {


}

void cleanup_graphics() {                      //done
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}
