add_library(display STATIC)

target_sources(
        display
        PRIVATE
            src/window.cpp
)

target_include_directories(display PUBLIC include/)