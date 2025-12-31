# so_long - 2D Game Project 🎮

A 2D game built in C using the MiniLibX graphics library following 42 School curriculum standards.

##  Project Overview

The player navigates through a map, collects all collectibles, and reaches the exit. The game includes:
- **Mandatory features** (src/)
- **Bonus features** (src_bonus/)
- **Test maps** (maps/)
- **Sprite textures** (Resources/)
- **Build system** (Makefile)

---

##  Quick Setup (3 Steps)

### Step 1: Setup Dependencies

```bash
# Install required libraries (Ubuntu/Debian)
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### Step 2: Build the Project

```bash
# Build mandatory version
make

# OR build bonus version
make bonus

# Clean and rebuild
make re
```

### Step 3: Test It!

```bash
# Test mandatory version
./so_long maps/valid_small.ber

# Test bonus version (with enemies and animations)
./so_long_bonus maps/valid_bonus.ber
```

---

##  What's Included

### Source Files (src/)
- ✅ `main.c` - Entry point and initialization
- ✅ `init_game.c` - Game and MLX initialization
- ✅ `parse_map.c` - Map file reading
- ✅ `validate_map.c` - Map validation (walls, elements)
- ✅ `check_path.c` - Flood fill path validation
- ✅ `map_utils.c` - Helper functions for maps
- ✅ `render.c` - Rendering system
- ✅ `movement.c` - Player movement and controls
- ✅ `exit.c` - Cleanup and exit handling
- ✅ `utils.c` - General utilities
- ✅ `textures.c` - Texture loading

### Bonus Files (src_bonus/)
All mandatory files PLUS:
- ✅ `animation_bonus.c` - Animation loop system
- ✅ `enemy_bonus.c` - Enemy AI and collision
- ✅ `render_bonus.c` - Enhanced rendering with move counter
- ✅ `textures_bonus.c` - Bonus texture loading

### Test Maps (maps/)
**Valid maps:**
- `valid_small.ber` - Small test map
- `valid_medium.ber` - Medium complexity map
- `valid_large.ber` - Large exploration map
- `valid_bonus.ber` - Map with enemy (N character)

**Invalid maps (for error testing):**
- `invalid_not_rectangular.ber`
- `invalid_no_walls.ber`
- `invalid_no_collectibles.ber`
- `invalid_multiple_players.ber`
- `invalid_no_path.ber`
- `invalid_blocked_path.ber`

### Resources (Textures)
XPM sprite files in `Resources/`:
- `wall.xpm` - Wall tile
- `empty.xpm` - Floor/background
- `Estrellita.xpm` - Collectible star
- `door.xpm` - Exit door
- `enemy.xpm` - Enemy sprite
- Player sprites: `right-1-40.xpm`, `right-2-40.xpm`, `left-1-40.xpm`, `left-2-40.xpm`, etc.

---

## 🎮 Controls

| Key | Action |
|-----|--------|
| **W / ↑** | Move up |
| **S / ↓** | Move down |
| **A / ←** | Move left |
| **D / →** | Move right |
| **ESC** | Exit game |

---

## 🗺️ Map Format

Maps are `.ber` files with the following characters:

| Character | Description |
|-----------|-------------|
| `0` | Empty space (floor) |
| `1` | Wall |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player starting position |
| `N` | Enemy (bonus only) |

### Map Requirements
- Rectangular shape
- Surrounded by walls (`1`)
- Exactly one exit (`E`) and one player (`P`)
- At least one collectible (`C`)
- Valid path from player to all collectibles and exit

---

## 🧪 Testing Commands

```bash
# Check norminette compliance
norminette src/ includes/
norminette src_bonus/ includes/

# Check memory leaks
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/valid_small.ber

# Test all valid maps
for map in maps/valid_*.ber; do ./so_long "$map"; done

# Test error handling
for map in maps/invalid_*.ber; do ./so_long "$map" 2>&1; done
```

---

## 🛠️ Common Issues & Solutions

### Issue: "libft not found"
```bash
# Make sure libft is compiled
cd libft && make && cd ..
ls libft/libft.a  # Should exist
```

### Issue: "mlx not found"
```bash
# Install X11 dependencies
sudo apt-get install xorg libxext-dev libbsd-dev

# Build MiniLibX
cd minilibx-linux && make && cd ..
```

### Issue: Textures not loading
- Ensure XPM files are in `Resources/` directory
- Check file names match exactly
- Verify XPM format is correct

---

##  Project Structure
```
so_long/
├── includes/
│   ├── so_long.h                  # Mandatory header
│   └── so_long_bonus.h            # Bonus header
├── src/                           # Mandatory source files
├── src_bonus/                     # Bonus source files
├── maps/                          # Test maps (.ber files)
├── Resources/                     # XPM sprite files
├── libft/                         # Custom C library
├── minilibx-linux/                # MiniLibX graphics library
├── Makefile                       # Build configuration
└── README.md                      # This file
```

---

## ✨ Features Checklist

### Mandatory
- ✅ Map parsing from .ber file
- ✅ Map validation (rectangular, walls, elements, path)
- ✅ Window creation with MiniLibX
- ✅ Texture loading (wall, floor, player, collectible, exit)
- ✅ Player movement (WASD/Arrows)
- ✅ Collectible system
- ✅ Exit condition
- ✅ Move counter (terminal output)
- ✅ ESC and window close handling
- ✅ Error handling
- ✅ Memory management (no leaks)

### Bonus
- ✅ Enemy patrol system with collision
- ✅ Animated sprites (4 frames)
- ✅ On-screen move counter
- ✅ Enemy character 'N' in maps
- ✅ Separate bonus executable

---

## Evaluation

1. **Norminette**: Run before every commit
2. **Memory Leaks**: Test with valgrind on all maps
3. **Error Handling**: Test all invalid maps
4. **Edge Cases**: Test various map sizes and special characters
5. **Bonus**: Clearly separate mandatory and bonus code

---

##  Resources

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [42 Docs - so_long](https://harm-smits.github.io/42docs/projects/so_long)
- [XPM Format Guide](https://en.wikipedia.org/wiki/X_PixMap)

---

## Author

**Muhammad Afzal**
Made with ❤️ for 42 School


