pushd ..\..\build\debug
conan install --build=missing -s build_type=Debug ../..
conan imports -imf . -if . ../..
popd

pushd ..\..\build\release
conan install --build=missing -s build_type=Release ../..
conan imports -imf . -if . ../..
popd
