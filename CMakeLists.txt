cmake_minimum_required(VERSION 4.2)
project(rurichess)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         main
)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        master
)

FetchContent_MakeAvailable(raylib)
FetchContent_MakeAvailable(googletest)

add_executable(main main.cpp)
target_link_libraries(main raylib)

add_subdirectory(src)
add_subdirectory(tests)