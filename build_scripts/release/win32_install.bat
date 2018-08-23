if not exist ..\..\build\release (
	mkdir ..\..\build\release
)

pushd ..\..\build\release
conan install --build=missing -s build_type=Release -if ./conan ../..
conan imports -imf . -if ./conan ../..
popd
