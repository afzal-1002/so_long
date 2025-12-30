# Texture Files Required

This directory should contain XPM image files for the game sprites.

## Required Files (64x64 pixels recommended)

### Mandatory Part
- `wall.xpm` - Wall tile (solid obstacle)
- `floor.xpm` - Floor tile (walkable space)
- `collectible.xpm` - Collectible item
- `exit.xpm` - Exit door
- `player.xpm` - Player character

### Bonus Part (Animated Sprites)
- `player_0.xpm` to `player_3.xpm` - Player animation frames (4 frames)
- `collectible_0.xpm` to `collectible_3.xpm` - Collectible animation (4 frames)
- `enemy.xpm` - Enemy character

## How to Create XPM Files

### Option 1: Use GIMP
1. Create a 64x64 pixel image
2. Draw your sprite
3. Export as "X PixMap image (.xpm)"

### Option 2: Use Online Tools
- https://www.pixilart.com/draw (draw and export as PNG, then convert)
- Use ImageMagick to convert: `convert sprite.png sprite.xpm`

### Option 3: Use Simple Text XPM
Create a basic XPM file manually. Example `floor.xpm`:
```c
/* XPM */
static char *floor[] = {
"64 64 2 1",
". c #333333",
"  c #666666",
"................................................................",
"................................................................",
"................................................................",
// ... (repeat for 64 lines)
};
```

## Example Resources

You can find free pixel art sprites at:
- https://opengameart.org/
- https://itch.io/game-assets/free
- https://kenney.nl/assets

**Important**: Make sure sprites are:
- 64x64 pixels (or adjust TILE_SIZE in headers)
- In XPM format
- Have transparent backgrounds if needed
- Match the game's aesthetic

## Quick Test Sprites

For quick testing, you can use solid color blocks:
- Wall: Gray/Brown block
- Floor: Light gray block
- Collectible: Yellow/Gold coin
- Exit: Green door
- Player: Blue/Red character
- Enemy: Red/Purple character
