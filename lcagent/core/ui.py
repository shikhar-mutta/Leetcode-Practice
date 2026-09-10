#!/usr/bin/env python3
"""
Terminal presentation, kept honest on cmd.exe.

Windows consoles do not interpret ANSI escapes until virtual-terminal
processing is switched on, so colour is enabled explicitly there rather than
assumed. Everything degrades to plain text when the output is redirected, when
NO_COLOR is set, or when the console refuses.
"""

from __future__ import annotations

import os
import sys


def _enable() -> bool:
    if os.environ.get("NO_COLOR"):
        return False
    if not sys.stdout.isatty():
        return False
    if os.name != "nt":
        return True
    try:  # opt into VT100 on Windows 10+
        import ctypes

        k = ctypes.windll.kernel32
        h = k.GetStdHandle(-11)
        mode = ctypes.c_uint32()
        if not k.GetConsoleMode(h, ctypes.byref(mode)):
            return False
        return bool(k.SetConsoleMode(h, mode.value | 0x0004))
    except Exception:  # noqa: BLE001
        return False


COLOR = _enable()


def _c(code: str):
    def wrap(s: object) -> str:
        return f"\033[{code}m{s}\033[0m" if COLOR else str(s)
    return wrap


bold = _c("1")
dim = _c("2")
red = _c("31")
green = _c("32")
yellow = _c("33")
blue = _c("34")
magenta = _c("35")
cyan = _c("36")


def rule(char: str = "─", width: int = 66) -> str:
    return dim(char * width)


def banner(text: str) -> str:
    return f"{bold(cyan(text))}"


def ok(text: str) -> str:
    return green("✓ ") + text


def bad(text: str) -> str:
    return red("✗ ") + text


def warn(text: str) -> str:
    return yellow("! ") + text


def info(text: str) -> str:
    return dim("· ") + text
