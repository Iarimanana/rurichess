cmake_minimum_required(VERSION 3.10)
project(rurichess LANGUAGES CXX)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         main
)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
)

FetchContent_MakeAvailable(raylib)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src/app)
add_subdirectory(src/chess)
add_subdirectory(src/display)
add_subdirectory(tests)