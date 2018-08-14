
pushd ..\..\build\debug
cmake -G"Visual Studio 14 2015 Win64" ../..
popd

pushd ..\..\build\release
cmake -G"Visual Studio 14 2015 Win64" ../..
popd
