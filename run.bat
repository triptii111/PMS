@echo off
cd /d "%~dp0"
set PATH=C:\msys64\mingw64\bin;%PATH%

echo Compiling Parking Management System...
echo.

g++ Vehicle.cpp ParkingSystem.cpp main.cpp -o ParkingManagement.exe 2>&1

if %errorlevel% neq 0 (
    echo.
    echo *** Compilation FAILED. Fix the errors above and try again. ***
    pause
    exit /b 1
)

echo Compilation successful!
echo.
echo ============================================================
.\ParkingManagement.exe

echo.
echo Program finished. Press any key to close this window.
pause > nul
