#!/usr/bin/env bash

pushd ../..
mkdir -p build/debug
cd build/debug
conan install --build=missing -s build_type=Debug ../..
conan imports -imf . -if . ../..
cmake ../.. -DCMAKE_BUILD_TYPE=Debug
popd

