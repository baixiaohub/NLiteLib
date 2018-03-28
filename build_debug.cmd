@echo off

if not exist "build" (
    mkdir build
)

pushd build
    cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Debug ..
    cmake --build .
popd
