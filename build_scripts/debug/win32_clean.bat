
if exist ..\..\build (
	pushd ..\..\build
	if exist debug (
		rmdir debug /s /q
	)
	popd
)



