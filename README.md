# Breakout
Implement the game Breakout in multiple ways as a learning exercise.

## Requirements
The following tools are required and should be added to your PATH environment variable:
* [Python](https://www.python.org/downloads/windows/)
* [Conan](https://conan.io/downloads.html)
* [CMake](https://cmake.org/download/)
* [Clang](http://releases.llvm.org/download.html)/[GCC](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe)/MSVC

Also, add the Bincrafters remote to Conan:
> conan remote add bincrafters conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan

## Build Scripts
There are several build scripts for convenience in the _build_scripts_ folder. There is a script for each aspect of the build.

* _win32_install.bat_: This will download the Conan dependencies and generate CMake files to help find the packages in the CMakeLists.txt file. This only needs to be done if the Conan generated files have not been built, they have been deleted, or the dependencies need to be updated.
* _win32_configure.bat_: This will run CMake and generate a Visual Studio solution. It only needs to be run if CMake has not been run yet, the CMake files were deleted, or you added/removed files to the solution.
* _win32_build.bat_: This will build the project. It only needs to be run if you didn't compile from the IDE.
* _win32_clean.bat_: **Not implemented**
* _win32_rebuild.bat_: **Not implemented**
