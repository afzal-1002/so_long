#!/bin/bash

# Setup script for so_long project

echo "================================"
echo "so_long Project Setup"
echo "================================"
echo ""

# Check for required system packages
echo "[1/4] Checking system dependencies..."
if ! command -v gcc &> /dev/null; then
    echo "❌ gcc not found. Please install: sudo apt-get install gcc"
    exit 1
fi

if ! dpkg -l | grep -q libxext-dev; then
    echo "⚠️  libxext-dev not found. Installing..."
    sudo apt-get update
    sudo apt-get install -y xorg libxext-dev libbsd-dev
fi
echo "✓ System dependencies OK"
echo ""

# Setup libft
echo "[2/4] Setting up libft..."
if [ ! -d "libft" ]; then
    echo "⚠️  libft directory not found!"
    echo "Please clone your libft repository:"
    echo "  git clone <your-libft-repo> libft"
    echo ""
    read -p "Enter your libft git URL (or press Enter to skip): " LIBFT_URL
    if [ ! -z "$LIBFT_URL" ]; then
        git clone "$LIBFT_URL" libft
        cd libft && make && cd ..
        echo "✓ libft built successfully"
    else
        echo "⚠️  Skipping libft setup. You'll need to add it manually."
    fi
else
    echo "✓ libft directory exists"
    cd libft && make && cd ..
    echo "✓ libft built successfully"
fi
echo ""

# Setup MiniLibX
echo "[3/4] Setting up MiniLibX..."
if [ ! -d "minilibx" ]; then
    echo "Cloning MiniLibX for Linux..."
    git clone https://github.com/42Paris/minilibx-linux.git minilibx
    cd minilibx && make && cd ..
    echo "✓ MiniLibX built successfully"
else
    echo "✓ MiniLibX directory exists"
    cd minilibx && make && cd ..
    echo "✓ MiniLibX built successfully"
fi
echo ""

# Check textures
echo "[4/4] Checking textures..."
TEXTURE_COUNT=$(ls -1 textures/*.xpm 2>/dev/null | wc -l)
if [ "$TEXTURE_COUNT" -eq 0 ]; then
    echo "⚠️  No XPM textures found in textures/ directory"
    echo "Please add your sprite files. See textures/README.md for details."
else
    echo "✓ Found $TEXTURE_COUNT XPM texture file(s)"
fi
echo ""

echo "================================"
echo "Setup Complete!"
echo "================================"
echo ""
echo "Next steps:"
echo "1. Add your XPM texture files to textures/ directory"
echo "2. Run 'make' to build the mandatory version"
echo "3. Run 'make bonus' to build the bonus version"
echo "4. Test with: ./so_long maps/valid_small.ber"
echo ""
echo "For more information, see README.md"
