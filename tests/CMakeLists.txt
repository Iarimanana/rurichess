add_executable(
        TestBitBoard
        TestBitBoard.cpp
        ../src/chess/src/bitboard.cpp
        ../src/chess/include/bitboard.h
        ../src/chess/src/pieces.cpp
        ../src/chess/include/pieces.h
)

target_link_libraries(TestBitBoard PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(TestBitBoard)