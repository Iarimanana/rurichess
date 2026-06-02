//
// Created by marshallmallow on 5/31/26.
//

#include <gtest/gtest.h>

#include "../src/chess/include/pieces.h"

namespace {

using namespace rurichess;

class TestPiece : public testing::Test {
 protected:
  TestPiece() : p{Piece()} {}
  void SetUp() override { p = Piece(PieceNames::Wpawn); }

  void TearDown() override { p.position().PrintBitBoard(); }

  Piece p;
};

TEST_F(TestPiece, TestPostion) {
  const BitBoard b = p.position();
  const auto wp = BitBoard(kPIECES_POSITIONS_ARRAY[0]);
  ASSERT_EQ(b == wp, true);
}

}  // namespace