# SO_LONG

## Table of Contents
- [About](#about)
- [Installation](#installation)
- [Usage](#usage)
- [Key Concepts Learned](#key-concepts-learned)
- [Skills Developed](#skills-developed)
- [Project Overview](#project-overview)
- [Game Mechanics](#game-mechanics)
- [Map Format](#map-format)
- [Controls](#controls)
- [Technical Highlights](#technical-highlights)
- [42 School Standards](#42-school-standards)


## About

This repository contains my implementation of the **so_long** project at 42 School.  
So_long is a 2D side-view(or top-view) game project that serves as an introduction to **graphics programming** and **game development** fundamentals.  
Built using **MinilibX** (42's custom graphics library), this project demonstrates core game development concepts including sprite animation, collision detection, map parsing, and event-driven programming.

The player must collect all collectibles scattered throughout the map and escape through the exit, navigating through a maze-like environment while avoiding obstacles.
This project bridges the gap between console applications and interactive graphical programs.


## Installation

### Prerequisites
- **MinilibX library** (42's graphics library)
- **GCC compiler** with C99 standard support
- **Make** utility
- **X11 development libraries** (Linux) or **AppKit framework** (macOS)

### Compilation
```bash
# Clone the repository
git clone https://github.com/TuroTheReal/so_long.git
cd so_long

# Compile the game
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```


## Usage

### Running the Game
```bash
# Run with a map file
./so_long maps/map.ber

# Example with different maps
./so_long maps/simple.ber
./so_long maps/medium.ber
./so_long maps/complex.ber
```

### Game Objective
1. **Collect** all collectible items (coins/gems) on the map
2. **Navigate** to the exit door once all items are collected
3. **Complete** the level in the minimum number of moves possible


## Key Concepts Learned

### Graphics Programming Fundamentals
- **MinilibX Mastery**: Window management, pixel manipulation, and image rendering
- **Sprite Management**: Loading, displaying, and animating 2D sprites and textures
- **Event Handling**: Keyboard input processing and real-time user interaction
- **Double Buffering**: Smooth rendering techniques to prevent screen flickering

### Game Development Core Concepts
- **Game Loop Architecture**: Implementing the classic update-render cycle
- **Collision Detection**: 2D tile-based collision system for walls and boundaries
- **State Management**: Tracking game state, player position, and collectible counts
- **Map-based Design**: Grid-based level design and tile-based rendering system

### File Processing and Validation
- **Map Parsing**: Reading and validating `.ber` format map files
- **Error Handling**: Comprehensive input validation and graceful error recovery
- **Memory Management**: Dynamic allocation for maps and sprite data
- **Path Finding Validation**: Ensuring all collectibles and exits are reachable

### Real-time Programming
- **Event-Driven Architecture**: Responsive input handling and immediate feedback
- **Performance Optimization**: Efficient rendering for smooth gameplay
- **Resource Management**: Loading and managing multiple texture assets
- **Frame Rate Control**: Maintaining consistent game performance


## Skills Developed

- **2D Graphics Programming**: Professional-level understanding of 2D rendering pipelines
- **Game Engine Architecture**: Building modular, maintainable game systems
- **Interactive Software Design**: Creating responsive, user-friendly applications
- **Asset Management**: Organizing and efficiently loading game resources
- **Problem Solving**: Implementing algorithms for pathfinding and collision detection
- **Cross-platform Development**: Working with graphics libraries across different systems
- **Performance Optimization**: Writing efficient code for real-time applications


## Project Overview

So_long implements a classic 2D adventure game where the player navigates through various levels, collecting items and solving spatial puzzles.
The game features a clean, tile-based aesthetic with smooth character movement and intuitive controls.

### Core Components

**Game Engine**: Central game loop managing update cycles, rendering, and event processing with consistent frame timing.
**Map System**: Comprehensive map loading and validation system supporting custom level design through `.ber` files.
**Player Controller**: Smooth character movement with grid-based positioning and collision detection against walls and boundaries.
**Collectible System**: Dynamic tracking of collectible items with visual feedback and completion validation.
**Rendering Pipeline**: Efficient sprite rendering system with support for multiple textures and smooth animations.
**Input Manager**: Real-time keyboard input processing with support for movement, game exit, and window management.


## Game Mechanics

### Core Gameplay Loop
1. **Exploration**: Navigate through the maze using WASD
2. **Collection**: Gather all collectible items scattered throughout the level
3. **Exit Strategy**: Reach the exit door after collecting all required items
4. **Move Optimization**: Complete levels with minimal movement for better scores

### Visual Elements
- **Player Sprite**: Animated character with directional movement
- **Wall Tiles**: Impassable barriers defining the maze structure
- **Floor Tiles**: Walkable surfaces with varied textures
- **Collectibles**: Items that must be gathered (coins, gems, keys)
- **Exit Door**: Level completion point (only accessible after collecting all items)

### Game Rules
- Player cannot move through walls or outside map boundaries
- All collectibles must be collected before the exit becomes accessible
- Movement counter tracks total number of moves taken
- Game displays real-time feedback for collections and completions


## Map Format

Maps use the `.ber` format with the following specifications:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

### Map Elements
- **`1`**: Wall (impassable)
- **`0`**: Empty space (walkable floor)
- **`P`**: Player starting position (must be unique)
- **`C`**: Collectible item (at least one required)
- **`E`**: Exit door (must be unique)

### Validation Rules
- Map must be rectangular and enclosed by walls
- Must contain exactly one player start position (`P`)
- Must contain exactly one exit (`E`)
- Must contain at least one collectible (`C`)
- All collectibles and exit must be reachable from player start
- Only valid characters allowed (`0`, `1`, `P`, `C`, `E`)

### Example Maps
```bash
# Simple 5x5 map
maps/simple.ber

# Medium complexity with multiple paths
maps/medium.ber

# Complex maze with strategic collectible placement
maps/complex.ber
```


## Controls

- **W / ↑**: Move up
- **A / ←**: Move left  
- **S / ↓**: Move down
- **D / →**: Move right
- **ESC**: Exit game
- **Red Cross (X)**: Close window


## Technical Highlights

### Performance Features
- **Efficient Rendering**: Optimized sprite rendering with minimal overdraw
- **Memory Management**: Careful allocation and cleanup of graphics resources
- **Event Optimization**: Responsive input handling with minimal latency

### Code Architecture
- **Modular Design**: Clean separation between game logic, rendering, and input
- **Error Resilience**: Comprehensive error handling for invalid maps and system failures
- **Resource Management**: Automatic cleanup of textures and allocated memory

### Advanced Features
- **Map Validation**: Sophisticated pathfinding to ensure map completability
- **Move Counter**: Real-time tracking and display of player moves
- **Smooth Animations**: Frame-based movement for fluid character motion
- **Cross-platform Compatibility**: Works on both Linux and macOS systems


## 42 School Standards

### Norm Requirements
- ✅ Maximum 25 lines per function
- ✅ Maximum 5 functions per file
- ✅ Proper indentation and formatting
- ✅ No forbidden functions usage
- ✅ Compilation without warnings (-Wall -Wextra -Werror)

### Project Standards
- ✅ Smooth window management (minimize, resize, close)
- ✅ Comprehensive map validation and error handling
- ✅ Efficient memory management with no leaks
- ✅ Proper sprite and texture loading
- ✅ Real-time move counter display
- ✅ Clean game termination and resource cleanup

### Game Requirements
- ✅ Player movement in 4 directions (W/A/S/D)
- ✅ Collision detection with walls
- ✅ Collectible gathering mechanism
- ✅ Exit accessibility after collecting all items
- ✅ Move counter visible and functional
- ✅ Proper ESC and window close handling

### Bonus Features (Optional)
- ✅ Sprite animations for character movement
- ✅ Enhanced visual effects and particle systems
- ✅ Additional collectible types with different behaviors
- ✅ Enemy AI with pathfinding algorithms
- ✅ Multiple level progression system


## Contact

- **GitHub**: [@TuroTheReal](https://github.com/TuroTheReal)
- **Email**: arthurbernard.dev@gmail.com
- **LinkedIn**: [Arthur Bernard](https://www.linkedin.com/in/arthurbernard92/)

---

<p align="center">
  <img src="https://img.shields.io/badge/Made%20with-C-blue.svg"/>
  <img src="https://img.shields.io/badge/Graphics-MinilibX-green.svg"/>
  <img src="https://img.shields.io/badge/Game%20Dev-2D-red.svg"/>
</p>
