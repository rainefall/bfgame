#ifndef BF_H
#define BF_H

#define BFG_STACK_SIZE 30000

#include "engine.h"

typedef struct bfg_interpreter {
	char* data;
	char* dataPtr;
	char* program;
	unsigned int pc;
} bfg_interpreter;

// create and return an interpreter for the given program string
bfg_interpreter* bfg_interpreterCreate(char* program);

void bfg_interpreterDestroy(bfg_interpreter* interpreter);

// accepts 1 byte of input containing input on which buttons were pressed
void bfg_interpreterStep(bfg_interpreter* interpreter, SDL_Renderer* renderer, unsigned char input);

#endif