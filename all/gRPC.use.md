# Protobuf 

## creat your cmake

```
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS foo.proto)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS EXPORT_MACRO DLL_EXPORT foo.proto)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS DESCRIPTORS PROTO_DESCS foo.proto)
protobuf_generate_python(PROTO_PY foo.proto)
add_executable(bar bar.cc ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(bar ${Protobuf_LIBRARIES})
```
[found here](https://cmake.org/cmake/help/latest/module/FindProtobuf.html)

## Tutorials

* [gRPC](https://grpc.io/docs/languages/cpp/basics/)
* [google](https://developers.google.com/protocol-buffers/docs/cpptutorial)

## trouble shoot

### Msbuild (specific to windows)

`CMake MSBUILD : error MSB1009: Project file does not exist`
`[cpptools] The build configurations generated do not contain the active build configuration.`
If you use VSC change Debug to Release in lower left corner tab

### config

`find_package(protobuf CONFIG REQUIRED)`
```
protobufConfig.cmake
protobuf-config.cmake
```

Do not bowser with config and use conan

otherwise try cmake hints
```
find_package(protobuf REQUIRED
    HINTS
       "C:/Program Files/protobuf")
```

### Include

`fatal error C1083: Cannot open include file: 'google/protobuf/port_def.inc'`

add protobuf in conan requierement
```
conan_cmake_configure(
    REQUIRES

    grpc/1.39.1
GENERATORS cmake_find_package
)
```
find curent version at [conan protobuf](https://conan.io/center/protobuf)

[More](https://cmake.org/cmake/help/v3.0/module/FindProtobuf.html)


### Links 

```
[build] main.obj : error LNK2019: unresolved external symbol "private: static class tutorial::Person * __cdecl google::protobuf::Arena::CreateMaybeMessage<class tutorial::Person>(class google::protobuf::Arena *)" (??$CreateMaybeMessage@VPerson@tutorial@@$$V@Arena@protobuf@google@@CAPEAVPerson@tutorial@@PEAV012@@Z) referenced in function "protected: class tutorial::Person * __cdecl google::protobuf::internal::RepeatedPtrFieldBase::Add<class google::protobuf::RepeatedPtrField<class tutorial::Person>::TypeHandler>(class tutorial::Person *)" (??$Add@VTypeHandler@?$RepeatedPtrField@VPerson@tutorial@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IEAAPEAVPerson@tutorial@@PEAV45@@Z) [C:\Users\Loiodice\Downloads\ttroy50 cmake-examples master 03-code-generation-protobuf\build\protobuf_example.vcxproj]
[build] main.obj : error LNK2019: unresolved external symbol "private: static class tutorial::Person_PhoneNumber * __cdecl google::protobuf::Arena::CreateMaybeMessage<class tutorial::Person_PhoneNumber>(class google::protobuf::Arena *)" (??$CreateMaybeMessage@VPerson_PhoneNumber@tutorial@@$$V@Arena@protobuf@google@@CAPEAVPerson_PhoneNumber@tutorial@@PEAV012@@Z) referenced in function "protected: class tutorial::Person_PhoneNumber * __cdecl google::protobuf::internal::RepeatedPtrFieldBase::Add<class google::protobuf::RepeatedPtrField<class tutorial::Person_PhoneNumber>::TypeHandler>(class tutorial::Person_PhoneNumber *)" (??$Add@VTypeHandler@?$RepeatedPtrField@VPerson_PhoneNumber@tutorial@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IEAAPEAVPerson_PhoneNumber@tutorial@@PEAV45@@Z) [C:\Users\Loiodice\Downloads\ttroy50 cmake-examples master 03-code-generation-protobuf\build\protobuf_example.vcxproj]
[build] main.obj : error LNK2019: unresolved external symbol "public: virtual __cdecl tutorial::AddressBook::~AddressBook(void)" (??1AddressBook@tutorial@@UEAA@XZ) referenced in function main [C:\Users\Loiodice\Downloads\ttroy50 cmake-examples master 03-code-generation-protobuf\build\protobuf_example.vcxproj]
[build] main.obj : error LNK2019: unresolved external symbol "protected: __cdecl tutorial::AddressBook::AddressBook(class google::protobuf::Arena *,bool)" (??0AddressBook@tutorial@@IEAA@PEAVArena@protobuf@google@@_N@Z) referenced in function main [C:\Users\Loiodice\Downloads\ttroy50 cmake-examples master 03-code-generation-protobuf\build\protobuf_example.vcxproj]
[build] main.obj : error LNK2019: unresolved external symbol "const tutorial::AddressBook::`vftable'" (??_7AddressBook@tutorial@@6B@) referenced in function main [C:\Users\Loiodice\Downloads\ttroy50 cmake-examples master 03-code-generation-protobuf\build\protobuf_example.vcxproj]
[build] C:\Users\Loiodice\Downloads\ttroy50 cmake-examples master 03-code-generation-protobuf\build\Release\protobuf_example.exe : fatal error LNK1120: 5 unresolved externals [C:\Users\Loiodice\Downloads\ttroy50 cmake-examples master 03-code-generation-protobuf\build\protobuf_example.vcxproj]
[build] Build finished with exit code 1
```
