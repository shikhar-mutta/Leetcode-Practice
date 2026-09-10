#!/usr/bin/env python3
"""
One-command environment setup, identical on Windows and Linux.

    python -m lcagent.bootstrap          install what is missing, ask first
    python -m lcagent.bootstrap --check  diagnose only, change nothing
    python -m lcagent.bootstrap --yes    install what is missing, ask nothing

Five things have to be true before the system works. This script checks each,
fixes what it can, and prints the exact command for what it cannot:

    1. Python 3.11+          (tomllib, used to read config.toml)
    2. a C++ compiler with <bits/stdc++.h>   — MinGW-w64 on Windows, not MSVC
    3. openpyxl              (the one third-party package; tracker only)
    4. launchers             `lc` / `lc.bat` with the right line endings
    5. a model provider key  (optional — every offline agent works without one)

Nothing here is silent: each step prints what it will run before running it,
and `--check` never modifies anything.
"""

from __future__ import annotations

import os
import platform
import shutil
import subprocess
import sys
from pathlib import Path

MIN_PY = (3, 11)
IS_WIN = os.name == "nt"
IS_MAC = sys.platform == "darwin"

OK, WARN, BAD, INFO = "  ok  ", " warn ", " FAIL ", " .... "

# Package managers we know how to drive, in preference order.
_LINUX_INSTALL = (
    ("apt-get", ["sudo", "apt-get", "install", "-y", "g++"]),
    ("dnf", ["sudo", "dnf", "install", "-y", "gcc-c++"]),
    ("pacman", ["sudo", "pacman", "-S", "--noconfirm", "gcc"]),
    ("zypper", ["sudo", "zypper", "install", "-y", "gcc-c++"]),
    ("apk", ["sudo", "apk", "add", "g++"]),
)

MANUAL_COMPILER = {
    "win": (
        "Install MSYS2, then the UCRT64 g++:\n"
        "    winget install --id MSYS2.MSYS2 -e\n"
        '    C:\\msys64\\usr\\bin\\bash.exe -lc "pacman -S --noconfirm mingw-w64-ucrt-x86_64-gcc"\n'
        "  then add this to PATH:  C:\\msys64\\ucrt64\\bin\n"
        "  Portable alternative (no installer): https://winlibs.com — unzip and\n"
        "  add its bin\\ to PATH.\n"
        "  MSVC (cl.exe) will NOT work: it has no <bits/stdc++.h>."),
    "mac": ("    xcode-select --install        # clang, may lack bits/stdc++.h\n"
            "    brew install gcc              # real g++, recommended"),
    "linux": "    sudo apt install g++          # or dnf/pacman/zypper equivalent",
}


class Console:
    def __init__(self) -> None:
        self.colour = sys.stdout.isatty() and not os.environ.get("NO_COLOR")
        if IS_WIN and self.colour:
            try:                       # opt into ANSI on Windows 10+
                import ctypes
                k = ctypes.windll.kernel32
                k.SetConsoleMode(k.GetStdHandle(-11), 7)
            except Exception:          # noqa: BLE001
                self.colour = False

    def _c(self, s: str, code: str) -> str:
        return f"\033[{code}m{s}\033[0m" if self.colour else s

    def step(self, tag: str, title: str, detail: str = "") -> None:
        colour = {OK: "32", WARN: "33", BAD: "31", INFO: "36"}[tag]
        print(f"[{self._c(tag, colour)}] {title}")
        for ln in (detail or "").splitlines():
            print(f"         {ln}")

    def head(self, s: str) -> None:
        print("\n" + self._c(s, "1;36"))
        print(self._c("─" * min(len(s), 66), "36"))

    def run_note(self, cmd: list[str]) -> None:
        print(f"         $ {self._c(' '.join(cmd), '35')}")


class Setup:
    def __init__(self, check_only: bool, assume_yes: bool) -> None:
        self.check_only = check_only
        self.yes = assume_yes
        self.c = Console()
        self.root = Path(__file__).resolve().parent.parent
        self.results: list[tuple[str, str, str]] = []

    # ── helpers ──
    def ask(self, question: str) -> bool:
        if self.check_only:
            return False
        if self.yes:
            return True
        try:
            return input(f"         {question} [y/N] ").strip().lower() in ("y", "yes")
        except (EOFError, KeyboardInterrupt):
            print()
            return False

    def run(self, cmd: list[str], why: str) -> bool:
        self.c.run_note(cmd)
        try:
            p = subprocess.run(cmd, timeout=1800)
            if p.returncode == 0:
                return True
            self.c.step(BAD, f"{why} failed (exit {p.returncode})")
        except FileNotFoundError:
            self.c.step(BAD, f"{why} failed", f"{cmd[0]} is not on PATH")
        except subprocess.TimeoutExpired:
            self.c.step(BAD, f"{why} timed out")
        return False

    def record(self, name: str, state: str, detail: str = "") -> None:
        self.results.append((name, state, detail))

    # ── 1. python ──
    def check_python(self) -> None:
        self.c.head("1. Python")
        v = sys.version_info
        vs = f"{v.major}.{v.minor}.{v.micro}"
        if v[:2] >= MIN_PY:
            self.c.step(OK, f"Python {vs}", f"{sys.executable}")
            self.record("Python", "ok", vs)
        else:
            self.c.step(BAD, f"Python {vs} is too old — 3.11+ required",
                        "config.toml is read with tomllib, added in 3.11.\n"
                        "  Windows: winget install Python.Python.3.12\n"
                        "  Linux  : sudo apt install python3.12")
            self.record("Python", "FAIL", f"{vs} < 3.11")

    # ── 2. compiler ──
    def check_compiler(self) -> None:
        self.c.head("2. C++ compiler")
        cxx = self._find_cxx()
        if cxx is None and not self.check_only:
            if self._offer_compiler_install():
                cxx = self._find_cxx(refresh=True)
        if cxx is None:
            key = "win" if IS_WIN else ("mac" if IS_MAC else "linux")
            self.c.step(BAD, "no C++ compiler found", MANUAL_COMPILER[key])
            self.record("C++ compiler", "FAIL", "not found")
            return

        ver = self._version(cxx)
        self.c.step(OK, f"found {cxx.name}", f"{cxx}\n{ver}")
        if self._bits_stdcpp(cxx):
            self.c.step(OK, "<bits/stdc++.h> compiles")
            self.record("C++ compiler", "ok", f"{cxx.name} {ver.split()[-1] if ver else ''}".strip())
        else:
            self.c.step(BAD, "compiler works but <bits/stdc++.h> is missing",
                        "Every solution in this repo includes it.\n"
                        + MANUAL_COMPILER["win" if IS_WIN else ("mac" if IS_MAC else "linux")])
            self.record("C++ compiler", "FAIL", "no bits/stdc++.h")

    def _find_cxx(self, refresh: bool = False):
        sys.path.insert(0, str(self.root))
        try:
            from lcagent.core import compiler
            return compiler.find_compiler(refresh=refresh)
        except FileNotFoundError:
            return None
        except Exception as e:                       # noqa: BLE001
            self.c.step(WARN, "compiler probe raised", f"{type(e).__name__}: {e}")
            return None

    @staticmethod
    def _version(cxx: Path) -> str:
        try:
            out = subprocess.run([str(cxx), "--version"], capture_output=True, text=True,
                                 timeout=30).stdout.strip().splitlines()
            return out[0] if out else ""
        except Exception:                            # noqa: BLE001
            return ""

    def _bits_stdcpp(self, cxx: Path) -> bool:
        """The real test: this repo's solutions do not build without it."""
        import tempfile
        src = "#include <bits/stdc++.h>\nint main(){std::vector<int> v{1};return v[0]-1;}\n"
        with tempfile.TemporaryDirectory() as d:
            f = Path(d) / "probe.cpp"
            f.write_text(src, encoding="utf-8")
            exe = Path(d) / ("probe.exe" if IS_WIN else "probe")
            try:
                p = subprocess.run([str(cxx), "-std=c++17", str(f), "-o", str(exe)],
                                   capture_output=True, text=True, timeout=180)
                return p.returncode == 0 and exe.is_file()
            except Exception:                        # noqa: BLE001
                return False

    def _offer_compiler_install(self) -> bool:
        if IS_WIN:
            return self._install_windows_compiler()
        if IS_MAC:
            if shutil.which("brew"):
                self.c.step(INFO, "g++ can be installed with Homebrew")
                if self.ask("run `brew install gcc`?"):
                    return self.run(["brew", "install", "gcc"], "brew install")
            return False
        for tool, cmd in _LINUX_INSTALL:
            if shutil.which(tool):
                self.c.step(INFO, f"{tool} is available — g++ can be installed",
                            "this needs your sudo password")
                if self.ask(f"run `{' '.join(cmd)}`?"):
                    return self.run(cmd, "package install")
                return False
        self.c.step(WARN, "no known package manager found (apt/dnf/pacman/zypper/apk)")
        return False

    def _install_windows_compiler(self) -> bool:
        """
        MSYS2 via winget, then g++ via pacman.

        Untested: this code path has never run on a Windows machine. It prints
        every command before running it so a failure is diagnosable, and the
        manual instructions are always shown as a fallback.
        """
        if not shutil.which("winget"):
            self.c.step(WARN, "winget not found — cannot install automatically",
                        "winget ships with Windows 10 21H2+ / Windows 11.")
            return False
        self.c.step(INFO, "MSYS2 can be installed with winget",
                    "this downloads roughly 100 MB, then ~300 MB of toolchain")
        if not self.ask("install MSYS2 + mingw-w64 g++ now?"):
            return False
        if not self.run(["winget", "install", "--id", "MSYS2.MSYS2", "-e",
                         "--accept-package-agreements", "--accept-source-agreements"],
                        "winget install MSYS2"):
            return False
        bash = Path(r"C:\msys64\usr\bin\bash.exe")
        if not bash.is_file():
            self.c.step(WARN, "MSYS2 installed but bash.exe is not where expected",
                        f"looked for {bash}")
            return False
        ok = self.run([str(bash), "-lc",
                       "pacman -S --noconfirm --needed mingw-w64-ucrt-x86_64-gcc"],
                      "pacman install g++")
        if ok:
            binpath = r"C:\msys64\ucrt64\bin"
            os.environ["PATH"] = binpath + os.pathsep + os.environ.get("PATH", "")
            self.c.step(WARN, "add this to your PATH permanently",
                        f"  setx PATH \"%PATH%;{binpath}\"\n"
                        "  (lcagent also finds it automatically at that location)")
        return ok

    # ── 3. openpyxl ──
    def check_openpyxl(self) -> None:
        self.c.head("3. openpyxl  (tracker only)")
        try:
            import openpyxl
            self.c.step(OK, f"openpyxl {openpyxl.__version__}")
            self.record("openpyxl", "ok", openpyxl.__version__)
            return
        except ImportError:
            pass
        self.c.step(WARN, "openpyxl is not installed",
                    "Needed only by `finish` and `report`. Everything else works without it.")
        if self.check_only or not self.ask("install it with pip?"):
            self.record("openpyxl", "missing", "pip install openpyxl")
            return
        for extra in ([], ["--break-system-packages"], ["--user"]):
            if self.run([sys.executable, "-m", "pip", "install", "openpyxl", *extra],
                        "pip install"):
                self.record("openpyxl", "ok", "installed")
                return
        self.record("openpyxl", "FAIL", "pip install failed")

    # ── 4. launchers ──
    def check_launchers(self) -> None:
        self.c.head("4. Launchers")
        sh, bat = self.root / "lc", self.root / "lc.bat"
        want_sh = ("#!/bin/sh\n"
                   "# lcagent launcher — cd so the package is importable, paths resolve absolutely\n"
                   'cd "$(dirname "$0")" || exit 1\n'
                   'exec python3 -m lcagent "$@"\n')
        want_bat = ("@echo off\r\n"
                    "setlocal\r\n"
                    'pushd "%~dp0"\r\n'
                    "python -m lcagent %*\r\n"
                    "set EXITCODE=%ERRORLEVEL%\r\n"
                    "popd\r\n"
                    "exit /b %EXITCODE%\r\n")
        # Line endings are the whole point: a CRLF `lc` fails on Linux with a
        # confusing "bad interpreter" error, and an LF .bat misbehaves on cmd.
        for path, want, binary in ((sh, want_sh, False), (bat, want_bat, True)):
            cur = path.read_bytes() if path.is_file() else None
            target = want.encode("utf-8")
            if cur == target:
                self.c.step(OK, f"{path.name} is correct")
            elif self.check_only:
                self.c.step(WARN, f"{path.name} differs from the expected content")
            else:
                path.write_bytes(target)
                self.c.step(OK, f"{path.name} written",
                            "CRLF line endings" if binary else "LF line endings")
        if not IS_WIN:
            try:
                sh.chmod(0o755)
                self.c.step(OK, "lc is executable", "./lc")
            except OSError as e:
                self.c.step(WARN, f"could not chmod lc: {e}")
        self.record("Launchers", "ok", "lc + lc.bat")

    # ── 5. optional extras ──
    def check_extras(self) -> None:
        self.c.head("5. Optional")
        git = shutil.which("git")
        if git:
            self.c.step(OK, "git found", f"{git}  — `finish --commit` will work")
            self.record("git", "ok", "")
        else:
            self.c.step(WARN, "git not found", "only `finish --commit` needs it")
            self.record("git", "missing", "")

        keys = {"GROQ_API_KEY": "groq", "GEMINI_API_KEY": "gemini",
                "CEREBRAS_API_KEY": "cerebras", "OPENROUTER_API_KEY": "openrouter",
                "ANTHROPIC_API_KEY": "anthropic (paid)"}
        found = [n for k, n in keys.items() if os.environ.get(k)]
        if found:
            self.c.step(OK, f"model provider configured: {', '.join(found)}")
            self.record("Model provider", "ok", ", ".join(found))
        else:
            setcmd = ('setx GROQ_API_KEY "gsk_..."' if IS_WIN
                      else 'echo \'export GROQ_API_KEY="gsk_..."\' >> ~/.bashrc')
            off, mod = self._agent_split()
            self.c.step(WARN, "no model provider key set",
                        f"{off} of {off + mod} agents are offline and need no key at all.\n"
                        f"A free Groq key unlocks the other {mod}:\n"
                        "  1. sign up at https://console.groq.com  (free, no card)\n"
                        f"  2. {setcmd}\n"
                        "  3. reopen the terminal")
            self.record("Model provider", "none", "offline agents still work")

        if shutil.which("ollama"):
            self.c.step(OK, "ollama found", "fully local models, no key needed")

    def _agent_split(self) -> tuple[int, int]:
        """(offline, model-backed) agent counts, read from the roster itself."""
        try:
            sys.path.insert(0, str(self.root))
            from lcagent.agents.master import MasterAgent
            m = MasterAgent()
            agents = [v for v in vars(m).values() if hasattr(v, "requires_llm")] + [m]
            mod = sum(1 for a in agents if a.requires_llm)
            return len(agents) - mod, mod
        except Exception:                            # noqa: BLE001
            return 0, 0

    # ── report ──
    def report(self) -> int:
        self.c.head("Summary")
        width = max(len(n) for n, _, _ in self.results) + 2
        failed = 0
        for name, state, detail in self.results:
            tag = {"ok": OK, "missing": WARN, "none": WARN, "FAIL": BAD}.get(state, INFO)
            if state == "FAIL":
                failed += 1
            self.c.step(tag, f"{name.ljust(width)}{detail}")
        print()
        if failed:
            print("  Setup incomplete — fix the FAIL lines above, then run this again.")
            return 1
        print("  Ready. Start the system with:")
        print(f"     {'lc.bat' if IS_WIN else './lc'}        " + "or   python -m lcagent")
        return 0

    def main(self) -> int:
        mode = "checking only, nothing will be changed" if self.check_only else \
               ("installing without prompts" if self.yes else "will ask before installing")
        print(f"\n  lcagent setup — {platform.system()} {platform.release()} ({mode})")
        print(f"  repo: {self.root}")
        self.check_python()
        self.check_compiler()
        self.check_openpyxl()
        self.check_launchers()
        self.check_extras()
        return self.report()


def main(argv: list[str] | None = None) -> int:
    argv = sys.argv[1:] if argv is None else argv
    if "-h" in argv or "--help" in argv:
        print(__doc__)
        return 0
    return Setup("--check" in argv or "--dry-run" in argv,
                 "--yes" in argv or "-y" in argv).main()


if __name__ == "__main__":
    raise SystemExit(main())
