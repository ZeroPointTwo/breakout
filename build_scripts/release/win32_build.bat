
if not exist ..\..\build\release (
	mkdir ..\..\build\release
)

pushd ..\..\build\release
cmake --build . --config release
popd
