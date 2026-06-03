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
  const BitBoard& b = p.position();
  const auto wp = BitBoard(kPIECES_POSITIONS_ARRAY[0]);
  ASSERT_EQ(b, wp);
  ASSERT_EQ(&b, &wp);
}

TEST_F(TestPiece, TestPieceConstructor) {
  const auto p_one = Piece();
  const auto p_two = Piece(PieceNames::Wpawn);
  const auto p_three = Piece(0);

  ASSERT_EQ(p_one.name(), kPIECES_REPRESENTATIONS_ARRAY[0]);
  ASSERT_EQ(p_two.name(), kPIECES_REPRESENTATIONS_ARRAY[0]);
  ASSERT_EQ(p_three.name(), kPIECES_REPRESENTATIONS_ARRAY[0]);

  ASSERT_EQ(p_one.suit(), Color::White);
  ASSERT_EQ(p_two.suit(), Color::White);
  ASSERT_EQ(p_three.suit(), Color::White);

  ASSERT_EQ(p_one.position(), BitBoard(kPIECES_POSITIONS_ARRAY[0]));
  ASSERT_EQ(p_two.position(), BitBoard(kPIECES_POSITIONS_ARRAY[0]));
  ASSERT_EQ(p_two.position(), BitBoard(kPIECES_POSITIONS_ARRAY[0]));
}

TEST_F(TestPiece, TestEQOperator) {
  const auto p_one = Piece(PieceNames::Bpawn);
  ASSERT_FALSE(p_one.name() == p.name() && p_one.suit() == p.suit() &&
               p_one.position() == p.position());
  p = p_one;
  ASSERT_TRUE(p_one.name() == p.name() || p_one.suit() == p.suit() ||
              p_one.position() == p.position());
}

}  // namespace