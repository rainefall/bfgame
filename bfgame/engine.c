#include "engine.h"

int bfg_pollEvents() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return 0;
		}
		else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
			switch (e.key.keysym.scancode) {
				case SDL_SCANCODE_UP:
					bfg_playerInput = bfg_playerInput ^ BFG_INTERNAL_UP;
					break;
				case SDL_SCANCODE_DOWN:
					bfg_playerInput = bfg_playerInput ^ BFG_INTERNAL_DOWN;
					break;
				case SDL_SCANCODE_LEFT:
					bfg_playerInput = bfg_playerInput ^ BFG_INTERNAL_LEFT;
					break;
				case SDL_SCANCODE_RIGHT:
					bfg_playerInput = bfg_playerInput ^ BFG_INTERNAL_RIGHT;
					break;
				case SDL_SCANCODE_Z:
					bfg_playerInput = bfg_playerInput ^ BFG_INTERNAL_A;
					break;
				case SDL_SCANCODE_X:
					bfg_playerInput = bfg_playerInput ^ BFG_INTERNAL_B;
					break;
				case SDL_SCANCODE_C:
					bfg_playerInput = bfg_playerInput ^ BFG_INTERNAL_C;
					break;
				case SDL_SCANCODE_RETURN:
					bfg_playerInput = bfg_playerInput ^ BFG_INTERNAL_START;
					break;
				default:
					break;
			}
		}
	}
	return 1;
}

void bfg_drawScreen(SDL_Renderer* renderer, char* data) {
	// setup values for drawing "pixels"
	SDL_Rect dstrect;
	dstrect.w = 10; // todo calculate this based on screen size
	dstrect.h = 10; // todo calculate this based on screen size

	// clear screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// begin drawing pixels
	SDL_SetRenderDrawColor(renderer, 255, 0, 128, 255);
	// loop through "VRAM" in the bf interpreter
	// 512 derived from the screen size 64x64 pixels at 1bpp
	for (unsigned int i = 0; i < 4096; i++) {
		if (data[i / 8u] & (unsigned char)pow(2u, i % 8u)) {
			dstrect.x = (i % 64) * 10;
			dstrect.y = (i / 64) * 10;
			SDL_RenderFillRect(renderer, &dstrect);
		}
	}

	// present rendered image
	SDL_RenderPresent(renderer);
}