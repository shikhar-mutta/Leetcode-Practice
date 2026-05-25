#!/bin/bash

# Usage:
#   ./debug.sh <N>        — run N_debug.txt (edit this file with your test case)
#   ./debug.sh <N> -a     — run full N_input.txt and compare against N_expected.txt
#
# To see debug prints in your .cpp, wrap them in:
#   #ifdef DEBUG
#   cerr << "windowSum = " << windowSum << "\n";
#   #endif

if [ -z "$1" ]; then
    echo "Usage: ./debug.sh <problem_number> [-a]"
    echo "  ./debug.sh 1838      # run 1838_debug.txt (your custom debug input)"
    echo "  ./debug.sh 1838 -a   # run all cases from 1838_input.txt"
    exit 1
fi

N="$1"
BINARY="./dbg_${N}"

# --- Detect source file: prefer N_*.cpp over N.cpp ---
GLOB_MATCHES=( ${N}_*.cpp )
if [ -e "${GLOB_MATCHES[0]}" ]; then
    SRC="${GLOB_MATCHES[0]}"
elif [ -f "${N}.cpp" ]; then
    SRC="${N}.cpp"
else
    echo "ERROR: No source file found for problem $N (looked for ${N}_*.cpp and ${N}.cpp)"
    exit 1
fi
echo "Using source: $SRC"

# --- Compile with DEBUG flag ---
echo "Compiling problem $N (DEBUG mode)..."
g++ -g -DDEBUG -o "$BINARY" "$SRC" 2>&1
if [ $? -ne 0 ]; then
    echo "COMPILE ERROR"
    exit 1
fi
echo "Compile OK"
echo ""

run_with_input() {
    local INPUT_FILE="$1"
    echo "=== Input ($INPUT_FILE) ==="
    cat "$INPUT_FILE"
    echo ""
    echo "=== Debug Output (cerr) ==="
    ACTUAL=$("$BINARY" < "$INPUT_FILE" 2>/tmp/dbg_stderr_${N})
    cat /tmp/dbg_stderr_${N}
    echo ""
    echo "=== Program Output ==="
    echo "$ACTUAL"
}

if [ "$2" = "-a" ]; then
    # Run full input file and diff against expected
    INPUT="${N}_input.txt"
    EXPECTED="${N}_expected.txt"
    if [ ! -f "$INPUT" ]; then
        echo "ERROR: $INPUT not found"
        rm -f "$BINARY"
        exit 1
    fi
    run_with_input "$INPUT"
    if [ -f "$EXPECTED" ]; then
        echo ""
        echo "=== Expected ==="
        cat "$EXPECTED"
        echo ""
        if [ "$ACTUAL" = "$(cat "$EXPECTED")" ]; then
            echo "RESULT: ALL PASS"
        else
            echo "RESULT: MISMATCH"
            diff <(echo "$ACTUAL") "$EXPECTED" | sed 's/^< /GOT:      /; s/^> /EXPECTED: /'
        fi
    fi
else
    # Run debug input file
    DEBUG_INPUT="${N}_debug.txt"
    if [ ! -f "$DEBUG_INPUT" ]; then
        echo "ERROR: $DEBUG_INPUT not found"
        echo "Create it with your single test case, e.g.:"
        echo "  1"
        echo "  3 5"
        echo "  1 2 4"
        rm -f "$BINARY"
        exit 1
    fi
    run_with_input "$DEBUG_INPUT"
fi

rm -f "$BINARY" /tmp/dbg_stderr_${N}
