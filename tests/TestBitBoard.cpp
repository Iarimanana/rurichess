//
// Created by marshallmallow on 5/25/26.
//

#include <gtest/gtest.h>

#include <ranges>

#include "../src/chess/include/bitboard.h"
#include "../src/chess/include/pieces.h"
#include "../src/chess/include/types.h"

namespace {

using namespace rurichess;

class TestBitBoard : public testing::Test {
 protected:
  TestBitBoard() {}

  void SetUp() override { bit_b = BitBoard(kPIECES_POSITIONS_ARRAY[0]); }

  void TearDown() override { bit_b.PrintBitBoard(); }

  BitBoard bit_b;
  static constexpr UInt64 kWHITE_PAWN{0xff00};
};

TEST_F(TestBitBoard, TestGetBit) {
  for (const Int32 i : std::views::iota(8, 16)) {
    ASSERT_EQ(bit_b.GetBit(i), 1);
  }
}

TEST_F(TestBitBoard, TestSetBit) {
  ASSERT_EQ(bit_b.GetBit(0), 0);
  bit_b.SetBit(0);
  ASSERT_EQ(bit_b.GetBit(0), 1);
}

TEST_F(TestBitBoard, TestRemoveBit) {
  ASSERT_EQ(bit_b.GetBit(8), 1);
  bit_b.RemoveBit(8);
  ASSERT_EQ(bit_b.GetBit(8), 0);
}

TEST_F(TestBitBoard, TestCountToZero) { ASSERT_EQ(bit_b.CountToZero(), 7); }

TEST_F(TestBitBoard, TestEQOpeartor) {
  const auto tmp = BitBoard(kWHITE_PAWN);
  ASSERT_EQ(bit_b == tmp, true);
  ASSERT_EQ(bit_b == Pieces().position(), true);
}

}  // namespace

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}