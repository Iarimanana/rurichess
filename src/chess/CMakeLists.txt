add_library(chess STATIC)

target_sources(
        chess
        PRIVATE
            src/board.cpp
            src/bitboard.cpp
            src/pieces.cpp
)

target_include_directories(chess PUBLIC include/)