# virus
## ooga booga how work?
- to build: `make`
- to run: `make run`

on vscode you just have to install [codelldb](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) (and [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) if you want completions) and press `F5`

## where are the images?
images end up in the `out` directory.

## how do i add a module?
look into `include/modules` and `src/modules`: suppose you want to create a module named `banana`, you should create:
- `include/banana.h` that includes `settings.h`, `types.h` and any other header you need, and defines the default settings for your module,. Here you should only put the declaration of a function `run_banana` that takes `ìnt map[MAP_X][MAP_Y]` as an argument, and only that
- `src/banana.c` where you implement such function, and any other function you need for it to work. do not print stuff!

in general a module is a function that moves around the matrix and substitutes the numbers for a `flag` that is given by the `run_*` function. it should be pretty straightforward if you look at the examples.

## I am using neovim and clangd does not pick up the includes
Create a file called .clangd with
```yaml
CompileFlags:
  Add: -I/absolute/path/to/the/project/include
```
