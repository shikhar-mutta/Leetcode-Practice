#!/bin/bash

# Usage: ./rename.sh <new_number>
# Auto-detects current number from existing *_driver.cpp and renames all 4 files

if [ -z "$1" ]; then
    echo "Usage: ./rename.sh <new_number>"
    echo "Example: ./rename.sh 10"
    exit 1
fi

NEW="$1"

DRIVER=$(ls *_driver.cpp 2>/dev/null | head -1)
if [ -z "$DRIVER" ]; then
    echo "ERROR: No *_driver.cpp found"
    exit 1
fi

OLD="${DRIVER%_driver.cpp}"

REQUIRED=("${OLD}.cpp" "${OLD}_driver.cpp" "${OLD}_input.txt" "${OLD}_expected.txt")
OPTIONAL=("${OLD}_debug.txt")

for f in "${REQUIRED[@]}"; do
    if [ ! -f "$f" ]; then
        echo "ERROR: $f not found"
        exit 1
    fi
done

for f in "${REQUIRED[@]}"; do
    newname="${f/$OLD/$NEW}"
    mv "$f" "$newname"
    echo "Renamed: $f -> $newname"
done

for f in "${OPTIONAL[@]}"; do
    if [ -f "$f" ]; then
        newname="${f/$OLD/$NEW}"
        mv "$f" "$newname"
        echo "Renamed: $f -> $newname"
    fi
done
