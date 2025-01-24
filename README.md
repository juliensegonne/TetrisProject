# Tetris 2023

This project aims to build a Tetris game using, in C, SDL2 and SDL2_mixer for graphics and sound, respectively.

## Features

- Classic Tetris gameplay
- Hard mode for an extra challenge
- Score tracking
- Game over detection
- Background music

## Getting Started

### Prerequisites

Make sure you have the following installed:

- SDL2
- SDL2_mixer
- SDL2_ttf
- SDL2_gfx

### Building the Project

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/Tetris2023.git
    cd Tetris2023
    ```

2. Compile the project:
    ```sh
    make
    ```

### Running the Game

After building the project, you can run the game with:
```sh
./tetris
```

## Controls

- `Arrow Keys` - Move the tetromino
- `Space` - Toggle hard mode
- `R` - Restart the game
- `Escape` - Quit the game

## Project Structure

- `src/` - Contains all source code files
- `include/` - Contains all header files
- `assets/` - Contains game assets like fonts and music

## Contributing

Feel free to fork this project and submit pull requests. For major changes.

## Acknowledgements

- SDL2: [https://www.libsdl.org/](https://www.libsdl.org/)
- SDL2_mixer: [https://www.libsdl.org/projects/SDL_mixer/](https://www.libsdl.org/projects/SDL_mixer/)
- SDL2_ttf: [https://www.libsdl.org/projects/SDL_ttf/](https://www.libsdl.org/projects/SDL_ttf/)
- SDL2_gfx: [http://www.ferzkopp.net/Software/SDL2_gfx/](http://www.ferzkopp.net/Software/SDL2_gfx/)

## Additional Information

The playfield and the score are displayed in a window created with SDL. A random tetromino (shape and color) is generated at the top of the playfield and must be placed at the bottom. It is falling and can be controlled with the keyboard.

The program can be compiled in Tetris2023 by the command `make` and then you can execute the file `tetris_toy` to launch the game (requires SDL library).

Don't forget to put the sound up !