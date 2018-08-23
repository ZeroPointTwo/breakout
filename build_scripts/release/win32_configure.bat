
if not exist ..\..\build\release (
	mkdir ..\..\build\release
)

pushd ..\..\build\release
cmake -G"Visual Studio 14 2015 Win64" ../..
popd
