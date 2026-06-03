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
  void SetUp() override { bit_b = BitBoard(kPIECES_POSITIONS_ARRAY[1]); }

  void TearDown() override { bit_b.PrintBitBoard(); }

  BitBoard bit_b;
  static constexpr UInt64 kWHITE_PAWN{0xff00};
  static constexpr UInt64 kBLACK_PAWN{0xff000000000000};
};

TEST_F(TestBitBoard, TestGetBit) {
  for (const Int32 i : std::views::iota(48, 56)) {
    ASSERT_EQ(bit_b.GetBit(i), 1);
  }
}

TEST_F(TestBitBoard, TestSetBit) {
  ASSERT_EQ(bit_b.GetBit(0), 0);
  bit_b.SetBit(0);
  ASSERT_EQ(bit_b.GetBit(0), 1);
}

TEST_F(TestBitBoard, TestRemoveBit) {
  const BitBoard b = bit_b;
  ASSERT_EQ(bit_b.GetBit(48), 1);
  bit_b.RemoveBit(48);
  ASSERT_EQ(bit_b.GetBit(48), 0);
  b.PrintBitBoard();
  bit_b.PrintBitBoard();
}

TEST_F(TestBitBoard, TestCountToZero) {
  ASSERT_EQ(bit_b.CountTrailingZero(), 48);
}

TEST_F(TestBitBoard, TestEQOpeartor) {
  const auto tmp = BitBoard(kBLACK_PAWN);
  ASSERT_EQ(bit_b, tmp);
  ASSERT_EQ(bit_b, kBLACK_PAWN);
}

}  // namespace

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}