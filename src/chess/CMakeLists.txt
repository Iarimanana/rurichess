add_library(chess STATIC
        src/movement.cpp
        include/movement.h
        src/piece_movement/utils.cpp
        include/piece_movement/utils.h
        include/piece_movement/rook.h
        src/piece_movement/rook.cpp
        src/piece_movement/bishop.cpp
        include/piece_movement/bishop.h
        include/setup.h
        src/setup.cpp
        include/error_code.h)

target_sources(
        chess
        PRIVATE
        src/board.cpp
        src/bitboard.cpp
        src/pieces.cpp
)

target_include_directories(chess PUBLIC include/)