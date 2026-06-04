//
// Created by marshallmallow on 5/25/26.
//

#ifndef RURICHESS_BOARD_H
#define RURICHESS_BOARD_H

#include <array>
#include <string>

#include "bitboard.h"
#include "pieces.h"
#include "types.h"

namespace rurichess {

class Board {
  std::array<Piece, kPieceArrayLen> board_;
  BitBoard initial_position_;
  BitBoard whites_;
  BitBoard blacks_;

 public:
  static constexpr UInt64 kBlackPosition = 0xffff000000000000;
  static constexpr UInt64 kWhitePosition = 0xffff;
  static constexpr UInt64 kInitialPosition = 0xffff00000000ffff;

  Board();
  Int32 Move(Piece p, std::string square);
  const BitBoard& whites() const;
  const BitBoard& blacks() const;
  void PrintBoard() const;
};

}  // namespace rurichess

#endif  // RURICHESS_BOARD_H
