
if not exist ..\..\build\debug (
	mkdir ..\..\build\debug
)

if not exist ..\..\build\makefiles (
	mkdir ..\..\build\makefiles
)

pushd ..\..\build\debug
cmake -G"Visual Studio 14 2015 Win64" ../..
popd

pushd ..\..\build\makefiles
cmake -G"Unix Makefiles" ../..
popd
