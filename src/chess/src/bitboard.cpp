//
// Created by marshallmallow on 5/25/26.
//

#include "../include/bitboard.h"

#include <iostream>

#include "../include/constant.h"
#include "../include/types.h"

using namespace rurichess;

BitBoard::BitBoard(const UInt64 bit_board) : bit_board_{bit_board} {}

BitBoard::BitBoard() { bit_board_ = ZERO; }

bool BitBoard::operator==(const BitBoard& other) const {
  return bit_board_ == other.bit_board_;
}

bool BitBoard::operator==(const UInt32 other) const {
  return bit_board_ == other;
}

UInt64 BitBoard::GetBit(const UInt64 index) const {
  return (this->bit_board_ >> index) & 1;
}

void BitBoard::SetBit(const UInt64 index) { bit_board_ |= (1 << index); }

void BitBoard::RemoveBit(const UInt64 index) {
  bit_board_ ^= GetBit(index) ? 1 << index : 0;
}

int BitBoard::CountToZero() const {
  if (bit_board_ == 0) return 64;
  Int32 count = 0;
  while (GetBit(count) == 0) {
    count++;
  }
  return count - 1;
}

void BitBoard::PrintBitBoard() const {
  std::cout << "    A B C D E F G H\n";
  std::cout << "    ---------------";

  for (Int32 i = 0; i < SIZE_BOARD; i++) {
    if (i % 8 == 0) std::cout << "\n" << (i / 8) + 1 << " | ";
    if (GetBit(i) == 1)
      std::cout << "1 ";
    else
      std::cout << ". ";
  }
}