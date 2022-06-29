# bfgame
a (and i use this term very lightly) """"game engine"""" written in C designed specifically to use the esoteric programming language brainfuck.

you can set pixels on a 64x64 grid on or off, and accept player input from the arrow keys, z, x, c, and the return key. that's all you need to make a game right?

## why
because its funny

## usage
i cannot possibly fathom why you'd want to use this but 
- brainfuck in this environment is a programming language with 8 commands: `>` (increment data pointer), `<` (decrement data pointer), `+` (increment data at pointer), `-` (decrement data at pointer), `.` (render screen), `,` (get button input), then `[` and `]` that essentially function as a while loop (there are better brainfuck guides out there that will explain this better than me). if you are having second thoughts about writing a game with this its okay to quit
- there is a configurable "stack size" representing the amount of memory assigned to the brainfuck interpreter. you can change this if you start running out of memory
- speaking of memory, the first 512 bytes of the interpreter's memory is dedicated to "VRAM". this is where you will be doing all your pixel drawing. each byte represents 8 pixels, left to right then top to bottom.
- when you use `,` the interpreter will copy 1 byte into the its memory at the position of the data pointer. this byte is a bit field representing 8 boolean values for the 8 player input keys, they are as follows (from LSB): Up, Down, Left, Right, Z, X, C, Return
- there is currently no error checking so writing a broken program may result in what real programmers would refer to as "undocumented behaviour" and i would refer to as "nightmare"

## requirements
- visual studio 2022
- sdl2 (install with vcpkg and you also need an environment variable called VCPKG that points to your VCPKG root directory if you want it to "just work")