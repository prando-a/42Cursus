# so_long

![](.media/00.png)
![](.media/01.png)

### Description

The **so_long** project is a simple 2D game where a player must navigate through a map, collect all the collectible items, and reach the exit to win. This project is designed to teach essential skills in graphics programming, event handling, and game development using the [**MLX42**](https://github.com/codam-coding-college/MLX42) graphics library. The **MLX42** library, which is a modern implementation of the classic MinilibX, which requires **GLFW** to be installed on your system. On Linux, it can be installed with the following command:
```bash
sudo apt-get install libglfw3-dev
```

Through this project, skills acquired are:
- **Graphics programming**: Drawing images, handling sprites, and creating animations.
- **Event handling**: Responding to user input through keyboard events.
- **Basic game mechanics**: Implementing collectibles, player movement, and win/lose conditions.
- **Memory management**: Ensuring proper allocation and deallocation of resources.

### Features

1. The game starts with a player sprite on a map defined in a `.ber` file.
2. The player can move using keyboard inputs (WASD or arrow keys).
3. The objective is to collect all collectibles and reach the exit without breaking the rules of the map.
4. The program tracks and displays the number of moves made by the player.
5. Errors in the map format or invalid inputs are handled gracefully with appropriate messages.

### Bonus Features

In the bonus version of **so_long**, additional features are implemented:
- **Enemies**: Enemies are added to the map, and the player loses if they collide with an enemy.
- **Sprite Animation**: Player and enemies are animated (too simply).
- **Total moves count display on screen** instead of standard output.

### Map Requirements

- The map must be rectangular and surrounded by walls (`1`), then also completely closed.
- It must contain:
  - Only one exit (`E`).
  - At least one collectible (`C`).
  - Exactly one starting position (`P`).
- It must be possible to complete the level. The program is smart enough to know if all collectibles and exit are accessible and no walls are impeding it.
- The map is parsed from a `.ber` file.
- No empty lines are allowed in the file, including above, under, and within the map content.
- The only characters allowed are:
  - `0` for empty space.
  - `1` for walls.
  - `C` for collectibles.
  - `E` for the exit.
  - `P` for the player’s starting position.
  - `M` (optional, in the bonus version) for enemies.

Example of a valid map (`map_bonus.ber`):
```
1111111111111111111111
11C1010000000000000001
1101M1010M011111010101
10001C01M000001101M101
1011111110111011011C01
100000000C1M1C1MC1C101
1111111111111111110101
1C00E000000000000000P1
1111111111111111111111
```

### Usage

This program is compiled with a Makefile located in the `so_long` directory. Type `make` or `make all` to compile the regular version, or `make bonus` to compile the bonus version. <br>

Once compiled, a `so_long` executable will be generated. Execution is as follows:

```bash
./so_long [map.ber]
```

### Controls

- **Move Up**: `W` or `UP`
- **Move Down**: `S` or `DOWN`
- **Move Left**: `A` or `LEFT`
- **Move Right**: `D` or `RIGHT`
- **Exit the Game**: `ESC`