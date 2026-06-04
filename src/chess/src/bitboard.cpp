//
// Created by marshallmallow on 5/25/26.
//

#include "../include/bitboard.h"

#include <format>
#include <iostream>
#include <stdexcept>

#include "../include/constant.h"
#include "../include/types.h"

using namespace rurichess;

BitBoard::BitBoard(const UInt64 bit_board) : bit_board_{bit_board} {}

BitBoard::BitBoard() { bit_board_ = kZero; }

bool BitBoard::operator==(const BitBoard& other) const {
  return bit_board_ == other.bit_board_;
}

bool BitBoard::operator==(const UInt64& other) const {
  return bit_board_ == other;
}

BitBoard BitBoard::operator|(const BitBoard& other) const {
  return BitBoard(bit_board_ | other.bit_board_);
}

BitBoard BitBoard::operator|(const UInt64& other) const {
  return BitBoard(bit_board_ | other);
}

Int32 BitBoard::GetBit(const Int32 index) const {
  if (index >= kSizeBoard)
    throw std::invalid_argument(std::format(
        "The index of size {} exceed the size of the board", index));
  return (this->bit_board_ >> index) & 1ULL;
}

void BitBoard::SetBit(const Int32 index) {
  if (index >= kSizeBoard)
    throw std::invalid_argument(std::format(
        "The index of size {} exceed the size of the board", index));
  bit_board_ |= (1ULL << index);
}

void BitBoard::RemoveBit(const Int32 index) {
  if (index >= kSizeBoard)
    throw std::invalid_argument(std::format(
        "The index of size {} exceed the size of the board", index));
  bit_board_ &= ~(1ULL << index);
}

Int32 BitBoard::CountTrailingZero() const {
  return std::countr_zero(bit_board_);
}

void BitBoard::PrintBitBoard() const {
  std::cout << "    A B C D E F G H\n";
  std::cout << "    ---------------";
  for (Int32 i = 0; i < kSizeBoard; i++) {
    if (i % 8 == 0) std::cout << "\n" << (i / 8) + 1 << " | ";
    if (GetBit(i) == 1)
      std::cout << "1 ";
    else
      std::cout << ". ";
  }
}