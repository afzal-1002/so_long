# so_long - 2D Game Project

A 2D game built in C using the MiniLibX graphics library following 42 School curriculum standards.

## Description

The player navigates through a map, collects all collectibles, and reaches the exit. The game includes:
- Map parsing and validation
- Player movement with WASD/Arrow keys
- Collectible system
- Move counter
- **Bonus features**: Enemies, animated sprites, on-screen move counter

## Requirements

### System Dependencies
```bash
# Install required libraries (Ubuntu/Debian)
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### Project Dependencies
1. **libft** - Your 42 custom C library
2. **MiniLibX** - Graphics library for X11

## Setup

### 1. Clone your libft
```bash
# Clone your libft repository into this directory
git clone <your-libft-repo> libft
cd libft
make
cd ..
```

### 2. Clone MiniLibX
```bash
# Clone MiniLibX for Linux
git clone https://github.com/42Paris/minilibx-linux.git minilibx
cd minilibx
make
cd ..
```

### 3. Add Textures
Create 64x64 pixel XPM images in the `textures/` directory:
- `wall.xpm` - Wall tile
- `floor.xpm` - Floor tile
- `collectible.xpm` - Collectible item
- `exit.xpm` - Exit door
- `player.xpm` - Player sprite

**For bonus (animated sprites):**
- `player_0.xpm` to `player_3.xpm` - Player animation frames
- `collectible_0.xpm` to `collectible_3.xpm` - Collectible animation frames
- `enemy.xpm` - Enemy sprite

## Build

```bash
# Compile mandatory part
make

# Compile bonus part
make bonus

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

## Usage

```bash
# Run mandatory version
./so_long maps/valid_small.ber

# Run bonus version with enemies
./so_long_bonus maps/valid_bonus.ber
```

## Controls

- **W/↑** - Move up
- **S/↓** - Move down
- **A/←** - Move left
- **D/→** - Move right
- **ESC** - Exit game

## Map Format

Maps are `.ber` files with the following characters:
- `0` - Empty space (floor)
- `1` - Wall
- `C` - Collectible
- `E` - Exit
- `P` - Player starting position
- `N` - Enemy (bonus only)

### Map Requirements
- Rectangular shape
- Surrounded by walls (`1`)
- Exactly one exit (`E`) and one player (`P`)
- At least one collectible (`C`)
- Valid path from player to all collectibles and exit

## Testing

```bash
# Test with valid maps
./so_long maps/valid_small.ber
./so_long maps/valid_medium.ber
./so_long maps/valid_large.ber

# Test with invalid maps (should display error)
./so_long maps/invalid_not_rectangular.ber
./so_long maps/invalid_no_walls.ber
./so_long maps/invalid_no_collectibles.ber

# Check for memory leaks
valgrind --leak-check=full ./so_long maps/valid_small.ber

# Check norminette compliance
norminette src/ includes/
norminette src_bonus/ includes/
```

## Project Structure

```
so_long/
├── src/              # Mandatory source files
├── src_bonus/        # Bonus source files
├── includes/         # Header files
├── maps/             # Test maps (.ber files)
├── textures/         # XPM sprite files
├── libft/            # Custom C library
├── minilibx/         # MiniLibX graphics library
├── Makefile          # Build configuration
└── README.md         # This file
```

## Features

### Mandatory
✅ Map parsing and validation  
✅ Player movement (WASD/Arrows)  
✅ Collectible system  
✅ Move counter (printed to terminal)  
✅ Exit condition (collect all items)  
✅ ESC key and window close handling  
✅ Error handling with messages  
✅ Memory leak free  

### Bonus
✅ Enemy patrol with collision detection  
✅ Animated sprites (player and collectibles)  
✅ On-screen move counter  
✅ Separate bonus executable  

## Author
MUhammad Afzal
Made with ❤️ for 42 School


