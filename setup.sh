#!/bin/bash

ARCHIVE="./mlx-lib.tar.gz"
EXTRACTED_DIR="./MLX42"

if [ -f "$ARCHIVE" ]; then
    echo "🔎 Checking if mlx-lib is extracted..."
    if [ -d "$EXTRACTED_DIR" ]; then
        echo "✅ mlx-lib is already extracted."
    else
        echo "📦 Extracting mlx-lib..."
        mkdir -p "$EXTRACTED_DIR"
        tar -xzvf "$ARCHIVE" -C "$EXTRACTED_DIR" --strip-components=1
        echo "✅ Extraction completed."
    fi
else
    echo "❌ Archive file not found: $ARCHIVE"
    exit 1
fi
