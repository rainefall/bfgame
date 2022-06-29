#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include "stdlib.h"
#include "string.h"
#include "math.h"

// button definitions (todo: make this configurable?)

#define BFG_BUTTON_UP SDL_SCANCODE_UP
#define BFG_BUTTON_DOWN SDL_SCANCODE_DOWN
#define BFG_BUTTON_LEFT SDL_SCANCODE_LEFT
#define BFG_BUTTON_RIGHT SDL_SCANCODE_RIGHT
#define BFG_BUTTON_A SDL_SCANCODE_Z
#define BFG_BUTTON_B SDL_SCANCODE_X
#define BFG_BUTTON_C SDL_SCANCODE_C
#define BFG_BUTTON_START SDL_SCANCODE_RETURN

#define BFG_INTERNAL_UP 0b00000001
#define BFG_INTERNAL_DOWN 0b00000010
#define BFG_INTERNAL_LEFT 0b00000100
#define BFG_INTERNAL_RIGHT 0b00001000
#define BFG_INTERNAL_A 0b00010000
#define BFG_INTERNAL_B 0b00100000
#define BFG_INTERNAL_C 0b01000000
#define BFG_INTERNAL_START 0b10000000

char bfg_playerInput;

// returns 0 if SDL_EXIT event is received
int bfg_pollEvents();

void bfg_drawScreen(SDL_Renderer* renderer, char* data);

#endif