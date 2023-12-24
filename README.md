# ooga booga how work?
create a directory named "build" and one named "out"

- to build: `make`
- to run: `make run`

or use vscode and just press `F5` i think

# where are the images?
images end up in the `out` directory. enjoy!

# how do i add a module?
look into `include/modules` and `src/modules``: suppose you want to create a module named `banana`, you should create:
- `include/banana.h` that includes `settings.h`, `types.h` and any other header you need, and defines the default settings for your module,. Here you should only put the declaration of a function `run_banana` that takes `ìnt map[MAP_X][MAP_Y]` as an argument, and only that
- `src/banana.c` where you implement such function, and any other function you need for it to work. do not print stuff!

in general a module is a function that moves around the matrix and substitutes the numbers for a `flag` that is given by the `run_*` function. it should be pretty straightforward if you look at the examples.