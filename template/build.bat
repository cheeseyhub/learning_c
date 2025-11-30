@echo off
echo Building for Windows...
mingw64\bin\mingw32-make.exe windows
if %errorlevel% equ 0 (
    echo Build successful! Run main.exe to execute.
) else (
    echo Build failed!
)
pause
