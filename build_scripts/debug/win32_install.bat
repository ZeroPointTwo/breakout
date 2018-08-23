if not exist ..\..\build\debug (
	mkdir ..\..\build\debug
)

pushd ..\..\build\debug
conan install --build=missing -s build_type=Debug -if ./conan ../..
conan imports -imf . -if ./conan ../..
popd
