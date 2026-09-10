#!/bin/sh
# lcagent setup for Linux / macOS.
#   ./setup.sh          install what is missing, ask first
#   ./setup.sh --check  diagnose only, change nothing
#   ./setup.sh --yes    install what is missing, ask nothing
cd "$(dirname "$0")" || exit 1

PY=""
for c in python3.13 python3.12 python3.11 python3 python; do
    if command -v "$c" >/dev/null 2>&1; then
        if "$c" -c 'import sys; sys.exit(0 if sys.version_info[:2] >= (3,11) else 1)' 2>/dev/null; then
            PY="$c"; break
        fi
    fi
done

if [ -z "$PY" ]; then
    echo "Python 3.11+ is required and was not found."
    echo
    if command -v apt-get >/dev/null 2>&1;   then echo "    sudo apt install python3"
    elif command -v dnf   >/dev/null 2>&1;   then echo "    sudo dnf install python3"
    elif command -v pacman >/dev/null 2>&1;  then echo "    sudo pacman -S python"
    elif command -v brew  >/dev/null 2>&1;   then echo "    brew install python"
    else echo "    install Python 3.11+ from https://www.python.org/downloads/"
    fi
    echo
    echo "Then run ./setup.sh again."
    exit 1
fi

exec "$PY" -m lcagent.bootstrap "$@"
