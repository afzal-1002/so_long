#!/bin/bash
echo "========================================="
echo "Testing so_long Map Validation"
echo "========================================="
echo ""

echo "--- TESTING INVALID MAPS (should show errors) ---"
for map in maps/invalid_*.ber; do
    echo "Testing: $(basename $map)"
    ./so_long "$map" 2>&1 | grep "Error" | head -2
    echo ""
done

echo "--- TESTING VALID MAPS (will fail at MLX init without X server) ---"
for map in maps/valid_*.ber; do
    echo "Testing: $(basename $map)"
    # Valid maps pass validation but fail at MLX init without X
    ./so_long "$map" 2>&1 | head -3
    echo ""
done

echo "========================================="
echo "Testing Complete!"
echo "========================================="
