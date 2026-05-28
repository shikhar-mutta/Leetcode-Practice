#!/bin/bash

# Usage: ./run.sh <problem_number>
# Files needed:  <N>_driver.cpp  <N>_input.txt  <N>_expected.txt
#
# The driver includes <N>.cpp (your Solution class) and provides main().

if [ -z "$1" ]; then
    echo "Usage: ./run.sh <problem_number>"
    echo "Example: ./run.sh 1"
    exit 1
fi

N="$1"
INPUT="${N}_input.txt"
EXPECTED="${N}_expected.txt"
BINARY="./sol_${N}"

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

# --- Check files ---
for f in "$INPUT" "$EXPECTED"; do
    if [ ! -f "$f" ]; then
        echo "ERROR: $f not found"
        exit 1
    fi
done

# --- Compile ---
echo "Compiling problem $N..."
g++ -O2 -o "$BINARY" "$SRC" 2>&1
if [ $? -ne 0 ]; then
    echo "COMPILE ERROR"
    exit 1
fi

# --- Run ---
TMPSTDERR=$(mktemp)
ACTUAL=$("$BINARY" < "$INPUT" 2>"$TMPSTDERR")
EXIT_CODE=$?
rm -f "$BINARY"

if [ $EXIT_CODE -ne 0 ]; then
    echo "RUNTIME ERROR (exit code $EXIT_CODE)"
    echo "$ACTUAL"
    rm -f "$TMPSTDERR"
    exit 1
fi

# --- Parse stderr into per-test-case input blocks (split by "---") ---
declare -a TEST_INPUTS
_cur=""
while IFS= read -r _line; do
    if [ "$_line" = "---" ]; then
        # Strip trailing blank lines before storing
        TEST_INPUTS+=("$(printf '%s' "$_cur" | sed -e 's/[[:space:]]*$//')")
        _cur=""
    else
        [ -n "$_cur" ] && _cur+=$'\n'"$_line" || _cur="$_line"
    fi
done < "$TMPSTDERR"
rm -f "$TMPSTDERR"

# --- Compare line by line ---
mapfile -t EXPECTED_LINES < "$EXPECTED"
mapfile -t ACTUAL_LINES <<< "$ACTUAL"

TOTAL=${#EXPECTED_LINES[@]}
PASSED=0

echo ""
for ((i = 0; i < TOTAL; i++)); do
    EXP="${EXPECTED_LINES[$i]}"
    GOT="${ACTUAL_LINES[$i]}"
    CASE=$((i + 1))
    if [ "$EXP" = "$GOT" ]; then
        echo "Test $CASE: PASS  (output: $GOT)"
        ((PASSED++))
    else
        echo "Test $CASE: FAIL  (expected: $EXP  |  got: $GOT)"
        if [ $i -lt ${#TEST_INPUTS[@]} ] && [ -n "${TEST_INPUTS[$i]}" ]; then
            _first_line=true
            while IFS= read -r _iline; do
                if [ "$_first_line" = true ]; then
                    echo "         input: $_iline"
                    _first_line=false
                else
                    echo "                $_iline"
                fi
            done <<< "${TEST_INPUTS[$i]}"
        fi
    fi
done

echo ""
echo "Result: $PASSED / $TOTAL passed"
