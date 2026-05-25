//
// Created by marshallmallow on 5/25/26.
//

#include "bitboard.h"
#include "constant.h"
#include <iostream>
#include "types.h"

BitBoard::BitBoard(const u64 bit_board) : bit_board {bit_board} {}

u64 BitBoard::get_bit(const u64 index) const {
  return (this->bit_board >> index) & 1;
}

void BitBoard::set_bit(const u64 index) {
  bit_board |= (1 << index);
}

void BitBoard::remove_bit(const u64 index) {
  bit_board ^= get_bit(index) ? 1 << index : 0;
}

int BitBoard::ctz() const {
  if (bit_board == 0) return 64;
  int count = 0;
  while (get_bit(count) == 0) {
    count++;
  }
  return count;
}

void BitBoard::print_bit_board() const {
  std::cout << "    A B C D E F G H\n";
  std::cout << "    ---------------";

  for (int i = 0; i < SIZE_BOARD; i++) {
    if (i % 8 == 0) std::cout << "\n" << (i / 8) + 1 << " | ";
    if (get_bit(i) == 1)
      std::cout << "1 ";
    else
      std::cout << ". ";
  }
}

int main() {
  const auto board = BitBoard(0xfabc333);
  board.print_bit_board();
  return 0;
}