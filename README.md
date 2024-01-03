# Virus
## Ooga booga how work?
- to build: `make`
- to run: `make run`

## Where are the images?
images end up in the `out` directory.

## How do i add a module?
Look into `src/modules`: you have to do something along those lines. Suppose you want to create a module named `banana`, you should create a folder `banana` containing:
- `banana.h` where you should only put the declaration of a function `run_banana` that takes `ìnt map[MAP_X][MAP_Y]` as an argument. It should probably also include `settings.h` and `types.h`. Any setting for your module should be defined here.
- `banana.c` where you implement such function, and any other function you need for it to work. do not print stuff!

In general a module is a function that moves around the matrix and substitutes the numbers for a `flag` that is given by the `run_{modulename}` function.
If you want LSP completions for the project, `clangd` should work out of the box (as long as it works on your editor).
