//
// Created by marshallmallow on 6/4/26.
//

#include "movement.h"

using namespace rurichess;

namespace {

bool WPawn(const BitBoard& begin, const BitBoard& end) {
  BitBoard legal_position = begin;

  return true;
}

bool BPawn(const BitBoard& begin, const BitBoard& end) {
  BitBoard legal_position = begin;
  return true;
}

}  // namespace

bool CheckIllegalMove(const PieceNames p, Square initial_square,
                      const BitBoard& ending_square) {
  auto begin = BitBoard();
  begin.SetBit(static_cast<I32>(initial_square));

  using enum PieceNames;
  switch (p) {
    case Wpawn:
      return WPawn(begin, ending_square);
    case Bpawn:
      return BPawn(begin, ending_square);
    default:
      return false;
  }
}
