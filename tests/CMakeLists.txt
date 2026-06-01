add_executable(
        Test
        TestBitBoard.cpp
        TestPiece.cpp
        ../src/chess/src/bitboard.cpp
        ../src/chess/include/bitboard.h
        ../src/chess/src/pieces.cpp
        ../src/chess/include/pieces.h
)

target_link_libraries(Test PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(Test)