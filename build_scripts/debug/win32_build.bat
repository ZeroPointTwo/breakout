
if not exist ..\..\build\debug (
	mkdir ..\..\build\debug
)

pushd ..\..\build\debug
cmake --build . --config Debug
popd
