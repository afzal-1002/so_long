# so_long Testing Guide

## Quick Start Testing

### 1. Compile the Project
```bash
make          # Build mandatory version (so_long)
make bonus    # Build bonus version (so_long_bonus)
make re       # Rebuild from scratch
```

### 2. Run Automated Tests
```bash
./test_all.sh    # Comprehensive test suite
```

## Manual Testing

### Test Map Validation

**Test Invalid Maps (should show specific errors):**
```bash
# Not rectangular
./so_long maps/invalid_not_rectangular.ber
# Expected: "Error\nMap is not rectangular"

# No walls
./so_long maps/invalid_no_walls.ber
# Expected: "Error\nMap is not surrounded by walls"

# Multiple players
./so_long maps/invalid_multiple_players.ber
# Expected: "Error\nInvalid map elements"

# No collectibles
./so_long maps/invalid_no_collectibles.ber
# Expected: "Error\nInvalid map elements"

# Blocked path (unreachable collectible or exit)
./so_long maps/invalid_blocked_path.ber
# Expected: "Error\nNo valid path in map"
```

**Test Valid Maps:**
```bash
# Small test map
./so_long maps/valid_small.ber

# Medium complexity
./so_long maps/valid_medium.ber

# Large map
./so_long maps/valid_large.ber

# Bonus with enemies
./so_long_bonus maps/valid_bonus.ber
```

### Test Gameplay (Requires X Server)

On a Linux desktop with GUI:
```bash
./so_long maps/valid_small.ber
```

**Controls:**
- `W` or `↑` - Move up
- `A` or `←` - Move left  
- `S` or `↓` - Move down
- `D` or `→` - Move right
- `ESC` - Exit game
- Click X button - Close window

**Gameplay Rules:**
1. Collect all collectibles (yellow coins)
2. Reach the exit (green door) to win
3. Move counter displayed in terminal (and on-screen in bonus)
4. In bonus: Avoid red enemies or game over

### Test Memory Leaks

```bash
# Install valgrind if not present
sudo apt install valgrind

# Test with invalid map (quick exit)
valgrind --leak-check=full --show-leak-kinds=all \
  ./so_long maps/invalid_not_rectangular.ber

# Test with valid map (will fail at MLX without X, but memory should be clean)
valgrind --leak-check=full --show-leak-kinds=all \
  ./so_long maps/valid_small.ber
```

**Expected Result:** 
```
HEAP SUMMARY:
    in use at exit: 0 bytes in 0 blocks
  total heap usage: X allocs, X frees, Y bytes allocated

All heap blocks were freed -- no leaks are possible
```

## Code Quality Checks

### Norminette (42 Coding Standard)

```bash
# Install norminette (42 students)
pip install norminette

# Check all source files
norminette src/*.c src_bonus/*.c

# Check all header files
norminette includes/*.h

# Full project check
norminette
```

**Expected:** All files should show `OK!` with no errors.

### Compilation Warnings

The project compiles with strict flags:
```bash
-Wall -Wextra -Werror
```

**Expected:** Zero warnings, zero errors.

## Test Results Checklist

- [ ] ✅ Mandatory version compiles without errors
- [ ] ✅ Bonus version compiles without errors
- [ ] ✅ Invalid rectangular map rejected
- [ ] ✅ Invalid walls map rejected
- [ ] ✅ Invalid elements map rejected
- [ ] ✅ Invalid path map rejected
- [ ] ✅ Valid maps pass all validation
- [ ] ✅ No memory leaks (valgrind clean)
- [ ] ✅ All files pass norminette
- [ ] ⏸️ Game window opens (requires X server)
- [ ] ⏸️ Player moves with keyboard
- [ ] ⏸️ Collectibles can be gathered
- [ ] ⏸️ Exit opens after all collectibles
- [ ] ⏸️ Move counter updates
- [ ] ⏸️ ESC and X button close game
- [ ] ⏸️ Bonus: Enemies move
- [ ] ⏸️ Bonus: On-screen move counter

**Legend:**
- ✅ Tested and working
- ⏸️ Requires Linux desktop with X server

## Creating Custom Test Maps

Map file format (`.ber`):
```
1111111111
1P00000C01
1000111101
1C00000E01
1111111111
```

**Required characters:**
- `0` - Empty space (floor)
- `1` - Wall
- `P` - Player starting position (exactly one)
- `E` - Exit (exactly one)
- `C` - Collectible (at least one)
- `N` - Enemy (bonus only, optional)

**Validation rules:**
- Rectangular shape
- Surrounded by walls (`1`)
- Exactly one player (`P`)
- Exactly one exit (`E`)
- At least one collectible (`C`)
- Valid path from player to all collectibles and exit

## Troubleshooting

**"Error\nFailed to load textures"**
- This is normal in headless environments (no X server)
- Map validation still works
- Test on Linux desktop with GUI for full gameplay

**Segmentation fault**
- Check map file exists and is readable
- Verify map is properly formatted
- Check with valgrind for memory issues

**"Error\nNo valid path in map"**
- Use flood fill mentally: can you reach ALL collectibles AND the exit?
- Walls must not block essential paths
- Test with simpler maps first

## Performance Testing

```bash
# Time how long validation takes on large map
time ./so_long maps/valid_large.ber

# Should be nearly instant (< 0.1 seconds)
```

## CI/CD Integration

For automated testing in GitHub Actions or similar:

```yaml
- name: Test so_long
  run: |
    make
    make bonus
    ./so_long maps/invalid_not_rectangular.ber 2>&1 | grep "Map is not rectangular"
    ./so_long maps/invalid_blocked_path.ber 2>&1 | grep "No valid path"
```

## Debugging Tips

**Add debug output:**
```c
// In check_path.c after flood_fill
ft_putnbr_fd(game->map.collected, 1);
ft_putstr_fd(" collectibles found out of ", 1);
ft_putnbr_fd(game->map.collectibles, 1);
ft_putstr_fd("\n", 1);
```

**Print map grid:**
```c
// In parse_map.c
int i = 0;
while (game->map.grid[i])
{
    ft_putstr_fd(game->map.grid[i], 1);
    ft_putstr_fd("\n", 1);
    i++;
}
```

## Complete Test Sequence

Run this for final validation:

```bash
# Clean build
make fclean
make
make bonus

# Test all invalid maps
for map in maps/invalid_*.ber; do
    echo "Testing $map"
    ./so_long "$map" 2>&1 | grep "Error"
done

# Test all valid maps
for map in maps/valid_small.ber maps/valid_medium.ber maps/valid_large.ber; do
    echo "Testing $map"
    ./so_long "$map" 2>&1 | head -2
done

# Test bonus
./so_long_bonus maps/valid_bonus.ber 2>&1 | head -2

# Memory check (if valgrind installed)
valgrind --leak-check=full ./so_long maps/invalid_not_rectangular.ber 2>&1 | grep "no leaks"

# Code style (if norminette installed)
norminette | grep -c "OK"

echo "All tests complete!"
```

---

**Ready to submit to 42 when all mandatory tests pass!** 🎮
