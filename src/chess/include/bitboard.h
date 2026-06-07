//
// Created by marshallmallow on 5/25/26.
//

#ifndef RURICHESS_BITBOARD_H
#define RURICHESS_BITBOARD_H
#include "types.h"

namespace rurichess {

class BitBoard {
  U64 bit_board_;

 public:
  explicit BitBoard(U64 bit_board);
  BitBoard();
  BitBoard(const BitBoard& other) = default;

  bool operator==(const BitBoard& other) const;
  bool operator==(const U64& other) const;

  BitBoard operator|(const BitBoard& other) const;
  BitBoard operator|(const U64& other) const;

  BitBoard operator&(const BitBoard& other) const noexcept;
  BitBoard operator&(U64 other) const noexcept;

  BitBoard operator>>(const BitBoard& other) const noexcept;
  BitBoard operator>>(U64 other) const noexcept;

  BitBoard operator<<(const BitBoard& other) const noexcept;
  BitBoard operator<<(U64 other) const noexcept;

  BitBoard operator~() const noexcept;

  BitBoard operator^(const BitBoard& other) const noexcept;
  BitBoard operator^(U64 other) const noexcept;

  BitBoard& operator=(const BitBoard& other) noexcept;
  BitBoard& operator=(U64 other) noexcept;

  BitBoard operator*(const BitBoard& other) const;
  BitBoard operator*(U64 other) const;

  [[nodiscard]] const U64& bit_board() const;
  [[nodiscard]] U64 GetBit(I32 index) const;
  [[nodiscard]] I32 CountTrailingZero() const;
  void SetBit(I32 index);
  void RemoveBit(I32 index);
  void PrintBitBoard() const;
};

}  // namespace rurichess

#endif  // RURICHESS_BITBOARD_H
