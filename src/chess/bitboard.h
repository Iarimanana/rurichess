//
// Created by marshallmallow on 5/25/26.
//

#ifndef RURICHESS_BITBOARD_H
#define RURICHESS_BITBOARD_H
#include "types.h"

class BitBoard {
  u64 bit_board {};

public:
  explicit BitBoard(u64 bit_board);
  [[nodiscard]] u64 get_bit(u64 index) const;
  void set_bit(u64 index);
  void remove_bit(u64 index);
  [[nodiscard]] int ctz() const;
  void print_bit_board() const;
};

#endif //RURICHESS_BITBOARD_H
