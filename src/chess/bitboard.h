//
// Created by marshallmallow on 5/25/26.
//

#ifndef RURICHESS_BITBOARD_H
#define RURICHESS_BITBOARD_H
#include "types.h"

class BitBoard {
  UInt64 bit_board_ {};

public:
  explicit BitBoard(UInt64 bit_board);
  BitBoard();
 [[nodiscard]] UInt64 GetBit(UInt64 index) const;
  void SetBit(UInt64 index);
  void RemoveBit(UInt64 index);
  [[nodiscard]] int CountToZero() const;
  void PrintBitBoard() const;
};

#endif //RURICHESS_BITBOARD_H
