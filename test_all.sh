#!/bin/bash
echo "========================================="
echo "TESTING SO_LONG - MANDATORY VERSION"
echo "========================================="
echo ""

echo "1. Invalid Map Tests:"
echo "---------------------"
./so_long maps/invalid_not_rectangular.ber 2>&1 | grep -A1 "^Error$" | head -2
./so_long maps/invalid_no_walls.ber 2>&1 | grep -A1 "^Error$" | head -2
./so_long maps/invalid_multiple_players.ber 2>&1 | grep -A1 "^Error$" | head -2
./so_long maps/invalid_no_collectibles.ber 2>&1 | grep -A1 "^Error$" | head -2
./so_long maps/invalid_blocked_path.ber 2>&1 | grep -A1 "^Error$" | head -2

echo ""
echo "2. Valid Map Tests (pass validation, fail at MLX without X):"
echo "------------------------------------------------------------"
./so_long maps/valid_small.ber 2>&1 | head -2
./so_long maps/valid_medium.ber 2>&1 | head -2

echo ""
echo "========================================="
echo "TESTING SO_LONG - BONUS VERSION"
echo "========================================="
echo ""

echo "1. Bonus Map with Enemy (should pass validation):"
echo "-------------------------------------------------"
./so_long_bonus maps/valid_bonus.ber 2>&1 | head -2

echo ""
echo "2. Regular maps also work in bonus:"
echo "-----------------------------------"
./so_long_bonus maps/valid_small.ber 2>&1 | head -2

echo ""
echo "========================================="
echo "3. Memory Leak Check (with valgrind):"
echo "========================================="
echo "Testing invalid map (should have no leaks):"
valgrind --leak-check=summary --show-leak-kinds=all ./so_long maps/invalid_not_rectangular.ber 2>&1 | grep -E "(ERROR SUMMARY|definitely lost|indirectly lost)"

echo ""
echo "========================================="
echo "4. Norminette Check:"
echo "========================================="
if command -v norminette &> /dev/null; then
    norminette src/*.c includes/*.h | grep -E "(Error|OK)" | head -5
else
    echo "Norminette not installed (install from 42 to check code style)"
fi

echo ""
echo "========================================="
echo "ALL TESTS COMPLETE!"
echo "========================================="
echo ""
echo "Note: To test actual gameplay, run on a Linux system with X server:"
echo "  ./so_long maps/valid_small.ber"
echo "  Use WASD or arrow keys to move, ESC to exit"
