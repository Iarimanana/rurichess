//
// Created by marshallmallow on 5/31/26.
//

#include <gtest/gtest.h>

#include "../src/chess/include/pieces.h"

namespace {

using namespace rurichess;

class TestPiece : public testing::Test {
 protected:
  void SetUp() override { p = Pieces(); }

  void TearDown() override { p.position().PrintBitBoard(); }

  Pieces p;
};

TEST_F(TestPiece, TestPostion) {
  const BitBoard b = p.position();
  const auto wp = BitBoard(0);
  ASSERT_EQ(b == wp, true);
}

}  // namespace