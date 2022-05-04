

Use in Vscode with extention cmake

can convert `*.sln` project from MSVC to cmake via `cmake-convert` [git-repos][cmake-converter]

might need some [special flags] when coming from MSVC 
```
add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)
```



[cmake-converter]: https://github.com/pavelliavonau/cmakeconverter
[special flags]: https://cmake.org/cmake/help/latest/variable/CMAKE_MFC_FLAG.html
