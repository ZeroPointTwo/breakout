pushd ..\..\build\debug
conan install --build=missing -s build_type=Debug -if ./conan ../..
conan imports -imf . -if ./conan ../..
popd

pushd ..\..\build\release
conan install --build=missing -s build_type=Release -if ./conan ../..
conan imports -imf . -if ./conan ../..
popd
