

link libraries 
---

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/abuCXC3t6eQ/0.jpg)](http://www.youtube.com/watch?v=abuCXC3t6eQ)

Use in Vscode with extention cmake
---

can convert `*.sln` project from MSVC to cmake via `cmake-convert` [git-repos][cmake-converter]

might need some [special flags] when coming from MSVC 
```
add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)
```

[Settings][vscode-settings]

argument
---
In the `CMakeLists.txt` file, create a cache variable, as documented here:
```
SET(MY_VARIABLE "option_value" CACHE STRING "Some user-specified option")
```
Then, either use the GUI (ccmake or cmake-gui) to set the cache variable, or specify the value of the variable on the cmake command line with -D:
```
cmake -DMY_VARIABLE:STRING=option_value2
```

Degug
---

Printing cmake variable can help a lot in debuging process
```
include(CMakePrintHelpers)
cmake_print_variables(PROJECT_SOURCE_DIR)
```
or
```
message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
```
Run just one file
```
cmake -P file.cmake
```

[cmake-converter]: https://github.com/pavelliavonau/cmakeconverter
[special flags]: https://cmake.org/cmake/help/latest/variable/CMAKE_MFC_FLAG.html
[vscode-settings]: https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/cmake-settings.md
