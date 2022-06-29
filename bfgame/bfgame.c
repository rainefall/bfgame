#include <SDL2/SDL.h>
#include "bf.h"
#include "engine.h"

// this example program should light up one of 8 pixels at the top of the screen when one of the 8 buttons is pressed
// this is a very bad implementation however because it has "gameplay" "logic" inside "VRAM"
// its mostly just to check that the code i wrote actually works
char* program = "+[>,.<]";

int main() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER)) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("bfgame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, 0);
    if (!window) {
        SDL_Log("Unable to create SDL window: %s", SDL_GetError());
        return 1;
    }

    // i doubt hardware acceleration will do much here ha
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_Log("Unable to create SDL renderer: %s", SDL_GetError());
        return 1;
    }

    bfg_interpreter* game = bfg_interpreterCreate(program);
    if (!game) {
        SDL_Log("Unable to create bf interpreter");
        return 1;
    }

    while (bfg_pollEvents()) {
        bfg_interpreterStep(game, renderer, bfg_playerInput);
    }

    bfg_interpreterDestroy(game);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}