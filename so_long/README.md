# so_long

![](.media/00.png)
![](.media/01.png)

### Description

The **so_long** project is a simple 2D game where a player must navigate through a map, collect all the collectible items, and reach the exit to win. This project is designed to teach essential skills in graphics programming, event handling, and game development using the **MinilibX** graphics library.

Through this project, you will learn:
- **Graphics programming**: Drawing images, handling sprites, and creating animations.
- **Event handling**: Responding to user input through keyboard events.
- **Basic game mechanics**: Implementing collectibles, player movement, and win/lose conditions.
- **Memory management**: Ensuring proper allocation and deallocation of resources.

### Features

1. The game starts with a player sprite on a map defined in a `.ber` file.
2. The player can move using keyboard inputs (e.g., `W`, `A`, `S`, `D` keys).
3. The objective is to collect all collectibles and reach the exit without breaking the rules of the map.
4. The program tracks and displays the number of moves made by the player.
5. Errors in the map format or invalid inputs are handled gracefully with appropriate messages.

### Bonus Features

In the bonus version of **so_long**, additional features are implemented:
- **Enemy AI**: Enemies are added to the map, and the player loses if they collide with an enemy.
- **Sprite Animation**: Player, collectibles, and enemies have animated sprites for smoother visuals.
- **Multiple Map Support**: Ability to load and play different maps.

### Map Requirements

- The map must be rectangular and surrounded by walls (`1`).
- It must contain:
  - At least one exit (`E`).
  - At least one collectible (`C`).
  - Exactly one starting position (`P`).
- The map is parsed from a `.ber` file.

Example of a valid map (`map.ber`):
```
111111
1P0C01
100001
1C0E01
111111
```

### Usage

This program is compiled with a Makefile located in the `so_long` directory. Type `make` or `make all` to compile the regular version, or `make bonus` to compile the bonus version. <br>

Once compiled, a `so_long` executable will be generated. Execution is as follows:

```bash
./so_long [map.ber]
```

### Examples of Execution

1. **Basic Execution**:
   ```bash
   ./so_long maps/map.ber
   ```
   This starts the game with the specified map.

2. **Bonus Execution**:
   ```bash
   ./so_long maps/bonus_map.ber
   ```
   Starts the game with bonus features enabled.

### Controls

- **Move Up**: `W`
- **Move Down**: `S`
- **Move Left**: `A`
- **Move Right**: `D`
- **Exit the Game**: `ESC`

### Notes

- Ensure that the map files are valid and comply with the specified requirements.
- The program will display an error message and exit if the map is invalid or if there are any issues with the `.ber` file.
- Bonus features provide enhanced gameplay and visuals but require additional resources and testing.

### Dependencies

- **MinilibX**: Ensure MinilibX is installed and properly linked during compilation.
- **X11 Libraries**: Required for graphics handling on Linux. Install using:
  ```bash
  sudo apt-get install libx11-dev libxext-dev
  ```