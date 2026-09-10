@echo off
setlocal
pushd "%~dp0"
python -m lcagent %*
set EXITCODE=%ERRORLEVEL%
popd
exit /b %EXITCODE%
