# CUB3D

## Table of Contents

1. [Instalation](#instalation)
3. [Map](#map)
2. [Errors](#errors)

## Instalation 

```bash
git clone https://github.com/eliaszanotti/cub3D.git --recursive
```

To install cub3D you just have to clone the project and run the following command:

```c
make
```

## Map

0 is for an empty space
1 is for a wall
3 is for a door
N,E,S,W is for orientation of the player

## Errors

**[ERROR:2]** Wrong amount of arguments (only one is expected in .cub format)

**[ERROR:3]** File not found

**[ERROR:4]** Incorrect file extension (.cub expected)

**[ERROR:5]** Can't open file

**[ERROR:6]** Invalid map

**[ERROR:7]** Invalid map (map not surrounded by walls)

**[ERROR:8]** Invalid color format (R,G,B)

**[ERROR:9]** Invalid texture path

**[ERROR:10]** Invalid map (wrong character)