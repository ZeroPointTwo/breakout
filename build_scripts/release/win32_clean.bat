
if exist ..\..\build (
	pushd ..\..\build
	if exist release (
		rmdir release /s /q
	)
	popd
)



