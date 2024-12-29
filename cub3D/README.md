# cub3d

![](.media/00.png)
![](.media/01.png)
![](.media/02.png)
![](.media/03.png)

### Description

The **cub3d** project is a basic 3D game inspired by Wolfenstein 3D, where the player navigates through a maze-like map using raycasting to simulate 3D rendering. This project serves as an introduction to graphics programming, user interaction, and game development. 

The project is built using the **MLX42** library, a modern implementation of the classic MinilibX, which requires **GLFW** to be installed on your system.

Through this project, you will learn:
- **Raycasting**: Simulating 3D environments in a 2D plane.
- **Graphics Programming**: Rendering walls, textures, and sprites in real-time.
- **Input Handling**: Managing keyboard and mouse inputs for player interaction.
- **Memory Management**: Loading and managing assets and ensuring proper cleanup.

### Features

#### Mandatory Version

1. Basic raycasting for 3D visualization.
2. Wall collision detection to restrict player movement.
3. Maps are loaded from `.cub` files.
4. Textures and colors are defined for walls, floor, and ceiling.
5. Simple keyboard controls for movement and rotation.

#### Bonus Version

1. **Minimap**:
   - Displays the map layout and tracks the player’s position in real-time.

2. **Weapons**:
   - Three weapons: fist, pistol, and shotgun.
   - Switch weapons using the `1`, `2`, and `3` keys.
   - Use the **right mouse button** to attack (punch or shoot).

3. **Player Movement**:
   - Sprinting is enabled by holding the `Shift` key, doubling the player’s movement speed.

4. **Camera Control**:
   - Rotate the camera with the mouse.
   - Adjust camera sensitivity by scrolling the mouse wheel up (increase sensitivity) or down (decrease sensitivity).

5. **Doors**:
   - Interactive doors can be opened by pressing a designated key.

### Map Rules

1. **File Format**:
   - Maps must be stored in `.cub` files.
   - The map must be closed (surrounded by walls) to prevent visual bugs or crashes.

2. **Map Layout**:
   - Walls are represented by the digit `1`.
   - Empty spaces are represented by `0`.
   - The player’s starting position is marked with `N`, `S`, `E`, or `W` to indicate the direction the player faces.

3. **Floor and Ceiling Colors**:
   - Colors for the floor and ceiling must be defined in RGB format in the map file.
   - Example: `F 220,100,0` (floor color) and `C 0,100,220` (ceiling color).

4. **Textures**:
   - Textures must be provided as `.png` files for walls, doors, and sprites.

#### Example of a Valid Map

