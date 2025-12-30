# so_long Project - Quick Start Guide

## ✅ Project Created Successfully!

Your complete so_long project structure has been generated with:
- **Mandatory features** (src/)
- **Bonus features** (src_bonus/)
- **Test maps** (maps/)
- **Sample textures** (textures/)
- **Build system** (Makefile)

## 🚀 Quick Setup (3 Steps)

### Step 1: Setup Dependencies

Run the automated setup script:
```bash
./setup.sh
```

Or manually:
```bash
# Clone your libft
git clone <your-libft-repo-url> libft
cd libft && make && cd ..

# Clone MiniLibX
git clone https://github.com/42Paris/minilibx-linux.git minilibx
cd minilibx && make && cd ..
```

### Step 2: Build the Project

```bash
# Build mandatory version
make

# OR build bonus version
make bonus
```

### Step 3: Test It!

```bash
# Test mandatory version
./so_long maps/valid_small.ber

# Test bonus version (with enemies and animations)
./so_long_bonus maps/valid_bonus.ber
```

## 📋 What's Included

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

### Bonus Files (src_bonus/)
All mandatory files PLUS:
- ✅ `animation_bonus.c` - Animation loop system
- ✅ `enemy_bonus.c` - Enemy AI and collision
- ✅ `render_bonus.c` - Enhanced rendering with move counter

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

### Textures (textures/)
Basic XPM sprite files (64x64):
- `wall.xpm` - Brown wall
- `floor.xpm` - Gray floor
- `player.xpm` - Red/Yellow player
- `collectible.xpm` - Gold coin
- `exit.xpm` - Green door
- `enemy.xpm` - Red enemy
- Animation frames: `player_0-3.xpm`, `collectible_0-3.xpm`

**Note:** These are placeholder sprites. Feel free to replace with your own designs!

## 🎮 Controls

- **W / ↑** - Move up
- **S / ↓** - Move down  
- **A / ←** - Move left
- **D / →** - Move right
- **ESC** - Exit game

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

## 🛠️ Common Issues & Solutions

### Issue: "libft not found"
**Solution:**
```bash
# Make sure libft is in the project root
ls libft/libft.a  # Should exist
# If not, run: cd libft && make && cd ..
```

### Issue: "mlx not found"
**Solution:**
```bash
# Install X11 dependencies
sudo apt-get install xorg libxext-dev libbsd-dev

# Clone and build MiniLibX
git clone https://github.com/42Paris/minilibx-linux.git minilibx
cd minilibx && make && cd ..
```

### Issue: "undefined reference to get_next_line"
**Solution:**
Make sure your libft includes `get_next_line.c` or add it separately to the Makefile.

### Issue: Textures not loading
**Solution:**
- Ensure XPM files are in `textures/` directory
- Check file names match exactly: `wall.xpm`, `floor.xpm`, etc.
- Verify XPM format is correct (see `textures/README.md`)

## 📦 Project Structure

```
so_long/
├── .github/
│   └── copilot-instructions.md    # AI agent guidance
├── includes/
│   ├── so_long.h                  # Mandatory header
│   └── so_long_bonus.h            # Bonus header
├── src/                           # Mandatory source files (10 files)
├── src_bonus/                     # Bonus source files (12 files)
├── maps/                          # Test maps (9 files)
├── textures/                      # XPM sprite files
├── libft/                         # Your 42 C library (to be added)
├── minilibx/                      # Graphics library (to be added)
├── Makefile                       # Build configuration
├── README.md                      # Project documentation
├── setup.sh                       # Automated setup script
└── .gitignore                     # Git ignore rules
```

## 🎯 Next Steps

1. **Customize Textures**: Replace the placeholder XPM files with your own pixel art
2. **Test Thoroughly**: Run all maps and check for memory leaks
3. **Add Features**: Consider additional bonus features like sound, more enemy types
4. **Optimize**: Profile and optimize rendering if needed
5. **Document**: Add comments and update README with your changes

## 📚 Resources

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [42 Docs - so_long](https://harm-smits.github.io/42docs/projects/so_long)
- [Pixel Art Resources](https://opengameart.org/)
- [XPM Format Guide](https://en.wikipedia.org/wiki/X_PixMap)

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

## 🏆 Evaluation Tips

1. **Norminette**: Run before every commit
2. **Memory Leaks**: Test with valgrind on all maps
3. **Error Handling**: Test all invalid maps
4. **Edge Cases**: Test 1x1 map, huge maps, special characters
5. **Bonus**: Clearly separate mandatory and bonus code

Good luck with your so_long project! 🎮
