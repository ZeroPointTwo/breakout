
pushd ..\..\build\debug
cmake --build . --config Debug
popd

pushd ..\..\build\release
cmake --build . --config Release
popd
