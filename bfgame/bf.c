#include "bf.h"

bfg_interpreter* bfg_interpreterCreate(char* program) {
	bfg_interpreter* interpreter = malloc(sizeof(bfg_interpreter));
	if (interpreter) {
		// create and clear memory buffer for bf interpreter
		interpreter->data = calloc(BFG_STACK_SIZE, sizeof(char) * BFG_STACK_SIZE);
		interpreter->dataPtr = interpreter->data;
		// setup program counter
		interpreter->program = program;
		interpreter->pc = 0;
		return interpreter;
	}
	return 0;
}

void bfg_interpreterDestroy(bfg_interpreter* interpreter)
{
	free(interpreter->data);
	free(interpreter);
}

void bfg_interpreterStep(bfg_interpreter* interpreter, SDL_Renderer* renderer, char input) {
	switch (interpreter->program[interpreter->pc]) {
		case '>':
			++interpreter->dataPtr;
			break;

		case '<':
			--interpreter->dataPtr;
			break;

		case '+':
			++*interpreter->dataPtr;
			break;

		case '-':
			--*interpreter->dataPtr;
			break;

		case '.':
			bfg_drawScreen(renderer, interpreter->data);
			break;

		case ',':
			*interpreter->dataPtr = input;
			break;

		case '[':
			if (!*interpreter->dataPtr) {
				while (interpreter->program[interpreter->pc] != ']')
					interpreter->pc++;
			}
			break;

		case ']':
			while (interpreter->program[interpreter->pc] != '[')
				interpreter->pc--;
			break;

		default:
			break;
	}

	interpreter->pc++;
}