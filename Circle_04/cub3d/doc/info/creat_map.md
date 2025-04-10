
<p align="center">
  <img src="../pic/Fig8_FOV_Rays.png" alt="Example of the game view">
</p>

# Creating Maps for Cub3D

In Cub3D, you’ll need to create maps that define the maze-like environment for the game. This guide will help you understand the structure of map files and how to create your own maps for the Cub3D project.

## Map File Format

A Cub3D map file is a plain text file that uses a specific format to define the maze. The map is represented as a 2D grid where different characters represent various elements of the environment. Here’s a breakdown of the format:

### Basic Structure

```
NO <path_to_north_texture>
SO <path_to_south_texture>
WE <path_to_west_texture>
EA <path_to_east_texture>
F <floor_color>
C <ceiling_color>
Map Lines
```

- **NO <path_to_north_texture>**: Path to the texture for the north wall.
- **SO <path_to_south_texture>**: Path to the texture for the south wall.
- **WE <path_to_west_texture>**: Path to the texture for the west wall.
- **EA <path_to_east_texture>**: Path to the texture for the east wall.
- **F <floor_color>**: RGB color for the floor.
- **C <ceiling_color>**: RGB color for the ceiling.
- **Map Lines**: The actual map layout where each character represents a different element of the environment.

### Map Characters

- `1`: Wall
- `0`: Empty space
- `N`, `S`, `E`, `W`: Player's starting position and direction (North, South, East, West)

### Example Map File

Here is an example of a simple map file:

```
NO textures/north.png
SO textures/south.png
WE textures/west.png
EA textures/east.png

F 100,100,100
C 50,50,50

1111111111
1000000001
1000N00001
1000000001
1000000001
1000000001
1000000001
1000000001
1000000001
1111111111
```

In this example:

- Four textures are specified for the walls.
- The floor color is a light gray (`100,100,100`).
- The ceiling color is a dark gray (`50,50,50`).
- `N` indicates the player's starting position facing North.

### Creating Your Map

1. **Choose a Text Editor**: Use a plain text editor like [Visual Studio Code](https://code.visualstudio.com/), [Notepad++](https://notepad-plus-plus.org/), or even a simple text editor like [Notepad](https://www.microsoft.com/en-us/p/notepad/9msmlrh6lzf3) for Windows.

3. **Add Textures**: Provide the paths to the textures for the different walls (North, South, East, West).

4. **Set Colors**: Define the floor and ceiling colors in RGB format.

5. **Draw the Map**: Create the 2D grid for the maze. Use `1` for walls, `0` for empty spaces, and `N`, `S`, `E`, `W` to specify the starting position and direction of the player.

6. **Save the File**: Save the file with a `.cub` extension, e.g., `my_map.cub`.

### Validating Your Map

Ensure that:
- Your map is surrounded by walls (`1`).
- There is exactly one player start position (`N`, `S`, `E`, or `W`).
- There are no invalid characters.
- Textures and colors are correctly specified.

### Example Map Files

You can find example maps in the `maps` directory of this repository:

- [Example Map 1](../../maps/good/0_map.cub)
- [Example Map 2](../../maps/good/4_library.cub)

Feel free to use or modify these maps to suit your needs.

---

<p align="center">
  <img src="../pic/Fig0_head.png" alt="Example of the game view">
</p>
