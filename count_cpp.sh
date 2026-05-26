#!/bin/bash
count=$(find "All Codes" -maxdepth 1 -name "*.cpp" | wc -l)
echo "CPP files in All Codes/: $count"
