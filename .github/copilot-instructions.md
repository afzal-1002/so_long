# so_long Project - AI Agent Instructions

## Project Overview
This is a **so_long** project: a 2D game built in C using the MiniLibX graphics library. The player navigates a map, collects items, and reaches an exit. This follows 42 School curriculum standards.

## Code Standards & Conventions

### Norminette Compliance
- **All code must pass norminette** (42's strict coding standard)
- Max 25 lines per function, 5 functions per file
- Max 80 characters per line
- No multiple declarations on same line
- Variable declarations at function start only
- No `for` loops allowed (use `while` instead)
- Check with: `norminette *.c *.h`

### File Structure Pattern
```
so_long/
├── src/           # Game logic, map parsing, player movement
├── src_bonus/     # Bonus features: enemies, animations, on-screen counter
├── includes/      # Header files (*.h)
├── maps/          # Valid and invalid test maps (*.ber)
├── textures/      # XPM sprite files (wall, player, collectible, exit, floor)
├── libft/         # Custom C library (REQUIRED - link with -L./libft -lft)
├── minilibx/      # MiniLibX graphics library (Linux X11 version)
└── Makefile       # Build rules: 'all', 'bonus', 'clean', 'fclean', 're'
```

**Platform:** Linux (X11) - use `-lmlx -lXext -lX11 -lm` for linking

## Core Components

### Map Parsing (`src/map_*.c`)
- Maps are `.ber` files with characters: `0` (floor), `1` (wall), `C` (collectible), `E` (exit), `P` (player)
- **Validation requirements:**
  - Rectangular shape
  - Surrounded by walls (`1`)
  - Exactly one exit (`E`) and one player start (`P`)
  - At least one collectible (`C`)
  - Valid path from player to all collectibles and exit
- Use flood fill algorithm for path validation
- Store map as 2D array (`char **`)

### Graphics with MiniLibX
- Initialize with `mlx_init()`, create window with `mlx_new_window()`
- Load textures: `mlx_xpm_file_to_image()` for each sprite
- Render: `mlx_put_image_to_window()` in a render function
- Hook keyboard: `mlx_key_hook()` or `mlx_hook()` for key events
- Main loop: `mlx_loop()` keeps game running
- Tile size typically 32x32 or 64x64 pixels

### Game Loop Architecture
```c
// Typical flow:
// 1. Parse and validate map
// 2. Initialize MLX and load textures
// 3. Setup key hooks
// 4. Enter MLX loop
// 5. On keypress: update state → render → check win condition
```

### Player Movement
- Arrow keys or WASD for movement
- ESC to exit game
- Validate moves: check if next tile is walkable (not `1`)
- Track move count and print to terminal
- After collecting all `C`, player can exit via `E`

## Memory Management
- **Every malloc needs a corresponding free**
- Free map array: loop through rows, free each, then free array pointer
- Destroy images: `mlx_destroy_image()` for each texture
- Destroy window: `mlx_destroy_window()`
- Exit cleanly on ESC or window close (X button)
- Handle errors: free allocated memory before returning error

## Build System
```makefile
# Required Makefile targets:
all:      # Compile executable 'so_long' (mandatory part)
bonus:    # Compile 'so_long_bonus' with bonus features
clean:    # Remove object files (*.o)
fclean:   # Remove objects + executables
re:       # Recompile from scratch (fclean + all)
```
- **Must compile libft first:** Add libft as dependency, run `make -C libft`
- **Linux linking flags:** `-L./libft -lft -L./minilibx -lmlx -lXext -lX11 -lm`
- Separate compilation for bonus: use `src_bonus/` files for bonus target

## Common Patterns

### Error Handling
```c
// Always return meaningful error messages to stderr
ft_putstr_fd("Error\n", 2);
ft_putstr_fd("Description of error\n", 2);
exit(1);
```

### Hook Functions
- Use `mlx_hook()` with event codes (KeyPress=2, DestroyNotify=17)
- Or simpler `mlx_key_hook()` for basic key handling
- Red cross (close window): hook event 17 to exit function

### Rendering Strategy
- Re-render entire map on each move (simple approach)
- OR optimize: only redraw changed tiles
- Render order: floor → walls → collectibles → exit → player

## Testing Checklist
- Valid maps with different layouts
- Invalid maps: not rectangular, no walls, multiple players, no collectibles, impossible paths
- Memory leaks: `valgrind --leak-check=full ./so_long maps/valid.ber`
- Norminette: `norminette -R CheckForbiddenSourceHeader`
- Edge cases: 1x1 map, very large maps, special characters

## Key Files to Review
- `main.c` - Entry point, initialization
- `map_parser.c` / `map_validator.c` - Map validation logic
- `game.c` / `player.c` - Game state and movement
- `render.c` - Drawing functions
- `utils.c` - Helper functions
- `exit.c` / `cleanup.c` - Memory cleanup

## Quick Commands
```bash
make                          # Build project
./so_long maps/test.ber      # Run with map file
norminette                    # Check code style
valgrind ./so_long maps/*.ber # Check memory leaks
```

## Bonus Features (src_bonus/)
- **Enemy patrol:** Add `N` (enemy) character, implement patrol logic, collision detection
- **Sprite animation:** Cycle through multiple XPM frames (player walk cycle, collectible spin)
- **On-screen move counter:** Use `mlx_string_put()` to display moves on window (not just terminal)
- **Separate executable:** Compile as `so_long_bonus` from `src_bonus/` directory
- All bonus code must also pass norminette and handle memory correctly

## Libft Integration
- **Use libft functions:** `ft_split()` for map parsing, `ft_strlen()`, `ft_strdup()`, `ft_putstr_fd()` for errors
- **Compile libft first:** Makefile should build libft before so_long
- Include libft header: `#include "libft.h"` in your headers
- Example: `map = ft_split(file_content, '\n');` for parsing map lines

## Important Notes
- **Platform:** Linux X11 - use X11 event codes and Linux-specific MiniLibX calls
- Test with `valgrind` on Linux to catch all memory leaks
- Bonus and mandatory must be separate compilations (don't mix `src/` and `src_bonus/`)
