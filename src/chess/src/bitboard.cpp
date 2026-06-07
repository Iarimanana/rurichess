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

BitBoard::BitBoard(const U64 bit_board) : bit_board_{bit_board} {}

BitBoard::BitBoard() { bit_board_ = kZero; }

bool BitBoard::operator==(const BitBoard& other) const {
  return bit_board_ == other.bit_board_;
}

bool BitBoard::operator==(const U64& other) const {
  return bit_board_ == other;
}

BitBoard BitBoard::operator|(const BitBoard& other) const {
  return BitBoard(bit_board_ | other.bit_board_);
}

BitBoard BitBoard::operator|(const U64& other) const {
  return BitBoard(bit_board_ | other);
}

BitBoard BitBoard::operator<<(const BitBoard& other) const noexcept {
  return BitBoard(bit_board_ << other.bit_board_);
}

BitBoard BitBoard::operator<<(const U64 other) const noexcept {
  return BitBoard(bit_board_ << other);
}

BitBoard BitBoard::operator>>(const BitBoard& other) const noexcept {
  return BitBoard(bit_board_ >> other.bit_board_);
}

BitBoard BitBoard::operator>>(const U64 other) const noexcept {
  return BitBoard(bit_board_ >> other);
}
BitBoard BitBoard::operator&(const BitBoard& other) const noexcept {
  return BitBoard(bit_board_ & other.bit_board_);
}

BitBoard BitBoard::operator&(const U64 other) const noexcept {
  return BitBoard(bit_board_ & other);
}

BitBoard BitBoard::operator*(const BitBoard& other) const {
  return BitBoard(bit_board_ * other.bit_board_);
}

BitBoard BitBoard::operator*(const U64 other) const {
  return BitBoard(bit_board_ * other);
}

BitBoard BitBoard::operator~() const noexcept { return BitBoard(~bit_board_); }

BitBoard BitBoard::operator^(const BitBoard& other) const noexcept {
  return BitBoard(bit_board_ ^ other.bit_board_);
}

BitBoard BitBoard::operator^(const U64 other) const noexcept {
  return BitBoard(bit_board_ ^ other);
}

BitBoard& BitBoard::operator=(const BitBoard& other) noexcept {
  if (this == &other) return *this;
  bit_board_ = other.bit_board_;
  return *this;
}

BitBoard& BitBoard::operator=(const U64 other) noexcept {
  bit_board_ = other;
  return *this;
}

const U64& BitBoard::bit_board() const { return bit_board_; }

U64 BitBoard::GetBit(const I32 index) const {
  if (index >= kSizeBoard)
    throw std::invalid_argument(std::format(
        "The index of size {} exceed the size of the board", index));
  return (this->bit_board_ >> index) & 1ULL;
}

void BitBoard::SetBit(const I32 index) {
  if (index >= kSizeBoard)
    throw std::invalid_argument(std::format(
        "The index of size {} exceed the size of the board", index));
  bit_board_ |= (1ULL << index);
}

void BitBoard::RemoveBit(const I32 index) {
  if (index >= kSizeBoard)
    throw std::invalid_argument(std::format(
        "The index of size {} exceed the size of the board", index));
  bit_board_ &= ~(1ULL << index);
}

I32 BitBoard::CountTrailingZero() const { return std::countr_zero(bit_board_); }

void BitBoard::PrintBitBoard() const {
  std::cout << "    A B C D E F G H\n";
  std::cout << "    ---------------";
  for (I32 i = 0; i < kSizeBoard; i++) {
    if (i % 8 == 0) std::cout << "\n" << (i / 8) + 1 << " | ";
    if (GetBit(i) == 1)
      std::cout << "1 ";
    else
      std::cout << ". ";
  }
}