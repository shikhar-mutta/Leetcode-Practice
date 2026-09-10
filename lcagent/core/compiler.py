#!/usr/bin/env python3
"""
Locating a C++ compiler and driving it, identically on Windows and Linux.

The solutions in this repo `#include <bits/stdc++.h>`, which is a libstdc++
extension — MSVC cannot build them at all. So the requirement on Windows is
MinGW-w64 g++ (MSYS2, WinLibs or TDM-GCC), not the Visual Studio toolchain.
"""

from __future__ import annotations

import hashlib
import os
import shutil
import subprocess
import time
from dataclasses import dataclass, field
from pathlib import Path

from . import paths

# ─── compiler discovery ──────────────────────────────────────────────────────

# Tried in order. clang++ is last: it works against libstdc++ on Linux, but on
# Windows it usually has no bits/stdc++.h to find.
_CANDIDATES = ("g++", "g++.exe", "clang++", "clang++.exe")

# Default MinGW-w64 install locations, for the common case where the user
# installed a toolchain but never added it to PATH.
_WINDOWS_HINTS = (
    r"C:\msys64\ucrt64\bin",
    r"C:\msys64\mingw64\bin",
    r"C:\mingw64\bin",
    r"C:\MinGW\bin",
    r"C:\TDM-GCC-64\bin",
    r"C:\Strawberry\c\bin",
)

_INSTALL_HINT = (
    "No C++ compiler found.\n"
    "  Linux : sudo apt install g++\n"
    "  Windows: install MSYS2 (https://www.msys2.org) then\n"
    "           pacman -S mingw-w64-ucrt-x86_64-gcc\n"
    "           and add C:\\msys64\\ucrt64\\bin to PATH.\n"
    "  MSVC will not work — the solutions need <bits/stdc++.h>.\n"
    "  Override with the CXX environment variable."
)

_cached_cxx: Path | None = None


def find_compiler(refresh: bool = False) -> Path:
    """Locate g++ (or a workable clang++). Raises with install guidance."""
    global _cached_cxx
    if _cached_cxx is not None and not refresh:
        return _cached_cxx

    override = os.environ.get("CXX")
    if override:
        found = shutil.which(override)
        if not found:
            raise FileNotFoundError(f"CXX={override!r} is set but not executable.")
        _cached_cxx = Path(found)
        return _cached_cxx

    for name in _CANDIDATES:
        found = shutil.which(name)
        if found:
            _cached_cxx = Path(found)
            return _cached_cxx

    if os.name == "nt":
        for hint in _WINDOWS_HINTS:
            for name in ("g++.exe", "g++"):
                cand = Path(hint) / name
                if cand.is_file():
                    _cached_cxx = cand
                    return _cached_cxx

    raise FileNotFoundError(_INSTALL_HINT)


def compiler_version(cxx: Path | None = None) -> str:
    """First line of `g++ --version`, for diagnostics."""
    cxx = cxx or find_compiler()
    try:
        out = subprocess.run(
            [str(cxx), "--version"],
            capture_output=True, text=True, errors="replace", timeout=15,
        )
        return (out.stdout or out.stderr).splitlines()[0].strip()
    except Exception as e:                                  # noqa: BLE001
        return f"<unknown: {e}>"


# ─── precompiled header ──────────────────────────────────────────────────────
# Every solution in this repo opens with `#include <bits/stdc++.h>`, and parsing
# that one header is ~4.5s of a ~5s build — the optimisation level barely
# matters. Precompiling it once per (compiler, flag-set) drops a rebuild to a
# fraction of that, which is what makes the watch loop and the debug retry loop
# usable. The .gch is large (~100 MB), so it lives in the temp build area
# rather than the repo, and is rebuilt on demand.

_PCH_INCLUDE = "bits/stdc++.h"

# A .gch is ~139 MB and is only valid for the exact flags that built it, so the
# cache is deliberately limited to the one flag set the verify path uses.
# Anything else (debug builds, custom flags) compiles without a PCH rather than
# spawning another copy.
_PCH_FLAGS = ("-O2",)


def _locate_stdcpp(cxx: Path) -> Path | None:
    """
    Resolve <bits/stdc++.h> by asking the preprocessor where it came from.

    Portable across distributions and MinGW, where the header sits under a
    target-specific directory that no fixed path would find.
    """
    try:
        proc = subprocess.run(
            [str(cxx), "-std=gnu++20", "-E", "-x", "c++", "-"],
            input=f"#include <{_PCH_INCLUDE}>\n",
            capture_output=True, text=True, errors="replace", timeout=60,
        )
    except (OSError, subprocess.TimeoutExpired):
        return None
    for line in proc.stdout.splitlines():
        if line.startswith("# ") and "stdc++.h" in line:
            parts = line.split('"')
            if len(parts) > 1:
                cand = Path(parts[1])
                if cand.is_file():
                    return cand
    return None


def _pch_key(cxx: Path, std: str, flags: tuple[str, ...]) -> str:
    """A PCH is only valid for the exact flags it was built with."""
    raw = "|".join([compiler_version(cxx), str(cxx), std, *flags])
    return hashlib.sha1(raw.encode()).hexdigest()[:12]


def ensure_pch(cxx: Path, std: str, flags: tuple[str, ...]) -> Path | None:
    """
    Build (or reuse) a precompiled bits/stdc++.h; return the -I directory.

    Returns None on any failure — a missing PCH must never break compilation,
    it only makes it slower.
    """
    header = _locate_stdcpp(cxx)
    if header is None:
        return None

    root = paths.build_dir() / "pch" / _pch_key(cxx, std, flags)
    bits = root / "bits"
    gch = bits / "stdc++.h.gch"
    if gch.is_file():
        return root

    try:
        bits.mkdir(parents=True, exist_ok=True)
        # GCC only looks for <header>.gch beside the header it resolved, so the
        # real header is copied in and this directory is put first on -I.
        local = bits / "stdc++.h"
        if not local.is_file():
            shutil.copy2(header, local)
        cmd = [str(cxx), f"-std={std}", *flags, "-x", "c++-header",
               str(local), "-o", str(gch)]
        proc = subprocess.run(cmd, capture_output=True, text=True,
                              errors="replace", timeout=300)
        if proc.returncode != 0 or not gch.is_file():
            shutil.rmtree(root, ignore_errors=True)
            return None
        return root
    except (OSError, subprocess.TimeoutExpired):
        shutil.rmtree(root, ignore_errors=True)
        return None


# ─── compilation ─────────────────────────────────────────────────────────────

@dataclass
class CompileResult:
    ok: bool
    binary: Path | None
    stderr: str
    seconds: float
    command: list[str] = field(default_factory=list)

    def first_error(self, limit: int = 12) -> str:
        """Trimmed diagnostics — g++ template spew is unreadable in full."""
        lines = [ln for ln in self.stderr.splitlines() if ln.strip()]
        head = lines[:limit]
        if len(lines) > limit:
            head.append(f"... ({len(lines) - limit} more lines)")
        return "\n".join(head)


def compile_cpp(
    src: Path,
    out_name: str,
    *,
    std: str = "gnu++20",
    optimize: bool = True,
    debug: bool = False,
    extra_flags: tuple[str, ...] = (),
    timeout: float = 120.0,
    use_pch: bool = True,
) -> CompileResult:
    """
    Compile `src` into paths.build_dir()/out_name.

    Defaults match run.sh (`-O2 -std=gnu++20`). `debug=True` matches debug.sh's
    intent (`-g -DDEBUG`) but keeps the explicit -std flag, which debug.sh omits
    — without it GCC falls back to gnu++17 and any C++20 solution that runs
    fine under run.sh fails to build under debug.sh.
    """
    cxx = find_compiler()
    binary = paths.build_dir() / (out_name + paths.EXE_SUFFIX)

    flags: list[str] = []
    if debug:
        flags += ["-g", "-DDEBUG"]
    if optimize:
        flags.append("-O2")
    flags += list(extra_flags)

    cmd = [str(cxx), f"-std={std}", *flags]
    if use_pch and tuple(flags) == _PCH_FLAGS:
        pch_dir = ensure_pch(cxx, std, tuple(flags))
        if pch_dir is not None:
            cmd += ["-I", str(pch_dir)]
    cmd += ["-o", str(binary), str(src)]

    started = time.perf_counter()
    try:
        proc = subprocess.run(
            cmd, capture_output=True, text=True, errors="replace", timeout=timeout
        )
        stderr, ok = proc.stderr, proc.returncode == 0
    except subprocess.TimeoutExpired:
        return CompileResult(False, None, f"compile timed out after {timeout:.0f}s",
                             time.perf_counter() - started, cmd)

    elapsed = time.perf_counter() - started
    if not ok:
        return CompileResult(False, None, stderr, elapsed, cmd)
    return CompileResult(True, binary, stderr, elapsed, cmd)
