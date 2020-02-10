@echo off
mkdir build
cd build
cmake ..\src\ "-DCMAKE_TOOLCHAIN_FILE=C:\Users\Reda_Kerouicha\Documents\Visual_Studio_2019\Librairies\vcpkg\scripts\buildsystems\vcpkg.cmake"