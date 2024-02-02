# Project Cub3D

Cub3D is a 3D graphics project that explores the raycasting technique to create a simple game engine with a Wolfenstein 3D-like visual style.

## Installation

To install and use Cub3D, follow these steps:

1. Clone the Cub3D repository from GitHub:
   ```
   git clone https://github.com/username/cub3D.git
   ```

2. Change into the project directory:
   ```
   cd cub3D
   ```

3. Compile the Cub3D program using the provided Makefile:
   ```
   make
   ```

4. The `cub3D` executable will be generated. You can now start using Cub3D.

Note: Cub3D requires a Unix-like operating system and a C compiler (e.g., GCC) to be installed on your system.

## Usage

To use Cub3D, follow the syntax:

```
./cub3D path/to/map.cub
```

## Map Configuration

The map is configured in a `.cub` file. Example configuration:

```plaintext
R 1920 1080
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
S ./textures/sprite.xpm
F 255,255,255
C 0,0,0
111111
100001
1001N1
100001
111111
```

## Documentation

Cub3D has the following key features and considerations:

- The project implements raycasting for rendering a 3D environment.
- Texture mapping is used to enhance the visual representation of walls and sprites.
- The map is configured through a `.cub` file, specifying resolution, textures, colors, and the map layout.
- Basic first-person controls allow users to navigate the 3D environment.

## Credits

Cub3D is the result of the collective effort of several individuals:

- [Thibault GIRAUDON (tgiraudo)](https://github.com/Thib1708)
- [Elias ZANOTTI (ezanotti)](https://github.com/eliaszanotti)
