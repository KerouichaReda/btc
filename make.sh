#!/bin/bash

mkdir build
cd build 

cmake ../src/ -G "CodeLite - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=/home/RedaKerouicha/Development/C++/libraries/vcpkg/scripts/buildsystems/vcpkg.cmake
