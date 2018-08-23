
if not exist ..\..\build\debug (
	mkdir ..\..\build\debug
)

pushd ..\..\build\debug
cmake -G"Visual Studio 14 2015 Win64" ../..
popd
