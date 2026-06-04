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
  bool operator==(const UInt64& other) const;
  BitBoard operator|(const BitBoard& other) const;
  BitBoard operator|(const UInt64& other) const;

  [[nodiscard]] Int32 GetBit(Int32 index) const;
  [[nodiscard]] Int32 CountTrailingZero() const;
  void SetBit(Int32 index);
  void RemoveBit(Int32 index);
  void PrintBitBoard() const;
};

}  // namespace rurichess

#endif  // RURICHESS_BITBOARD_H
