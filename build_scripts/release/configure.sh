#!/usr/bin/env bash

pushd ../..
mkdir -p build/release
cd build/release
conan install --build=missing -s build_type=Release ../..
conan imports -imf . -if . ../..
cmake ../.. -DCMAKE_BUILD_TYPE=Release
popd

