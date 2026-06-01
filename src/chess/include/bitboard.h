//
// Created by marshallmallow on 5/25/26.
//

#ifndef RURICHESS_BITBOARD_H
#define RURICHESS_BITBOARD_H
#include "types.h"

namespace rurichess {

class BitBoard {
  UInt64 bit_board_;

 public:
  explicit BitBoard(UInt64 bit_board);
  BitBoard();
  bool operator==(const BitBoard& other) const;
  bool operator==(UInt32 other) const;

  [[nodiscard]] UInt64 GetBit(UInt64 index) const;
  void SetBit(UInt64 index);
  void RemoveBit(UInt64 index);
  [[nodiscard]] Int32 CountToZero() const;

  void PrintBitBoard() const;
};

}  // namespace rurichess

#endif  // RURICHESS_BITBOARD_H
