@echo off
rem lcagent setup for Windows.
rem   setup.bat          install what is missing, ask first
rem   setup.bat --check  diagnose only, change nothing
rem   setup.bat --yes    install what is missing, ask nothing
setlocal enabledelayedexpansion
pushd "%~dp0"

set "PY="
rem The py launcher knows about every installed version; prefer it.
for %%V in (3.13 3.12 3.11) do (
    if not defined PY (
        py -%%V -c "import sys" >nul 2>&1 && set "PY=py -%%V"
    )
)
if not defined PY (
    python -c "import sys; sys.exit(0 if sys.version_info[:2]>=(3,11) else 1)" >nul 2>&1 && set "PY=python"
)

if not defined PY (
    echo Python 3.11+ is required and was not found.
    echo.
    where winget >nul 2>&1
    if errorlevel 1 (
        echo     Download it from https://www.python.org/downloads/
        echo     Tick "Add python.exe to PATH" during install.
    ) else (
        echo     winget install Python.Python.3.12
        echo.
        set /p ANS="Install Python 3.12 with winget now? [y/N] "
        if /i "!ANS!"=="y" (
            winget install --id Python.Python.3.12 -e --accept-package-agreements --accept-source-agreements
            echo.
            echo Python installed. CLOSE this window, open a new one, and run setup.bat again.
        )
    )
    popd
    exit /b 1
)

%PY% -m lcagent.bootstrap %*
set EXITCODE=%ERRORLEVEL%
popd
exit /b %EXITCODE%
