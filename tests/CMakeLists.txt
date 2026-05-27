add_executable(
        TestBitBoard
        TestBitBoard.cpp
        ../src/chess/bitboard.cpp
        ../src/chess/bitboard.h
)

target_link_libraries(TestBitBoard PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(TestBitBoard)