//
// Created by marshallmallow on 5/27/26.
//
#include "../include/pieces.h"

#include <stdexcept>

using namespace rurichess;

constexpr std::array<UInt64, kPIECE_ARRAY_LEN> kPIECES_POSITIONS_ARRAY = {
    0xff00, 0xff000000000000,   0x81, 0x8100000000000000,
    0x42,   0x4200000000000000, 0x24, 0x2400000000000000,
    0x8,    0x800000000000000,  0x10, 0x1000000000000000,
};

constexpr std::array kPIECES_REPRESENTATIONS_ARRAY = {
    'P', 'p', 'R', 'r', 'N', 'n', 'B', 'b', 'Q', 'q', 'K', 'k'};

Piece::Piece() : Piece(PieceNames::Wpawn) {}

Piece::Piece(const PieceNames name)
    : name_{kPIECES_REPRESENTATIONS_ARRAY[static_cast<Int32>(name)]} {
  const auto n = static_cast<Int32>(name);
  suit_ = ((n + 1) % 2 == 0) ? Color::Black : Color::White;
  position_ = BitBoard(kPIECES_POSITIONS_ARRAY[n]);
}

Piece::Piece(const Int32 name) : name_{kPIECES_REPRESENTATIONS_ARRAY[name]} {
  if (name >= kPIECE_ARRAY_LEN)
    throw std::invalid_argument("The name of the piece is invalid.");

  suit_ = ((name + 1) % 2 == 0) ? Color::Black : Color::White;
  position_ = BitBoard(kPIECES_POSITIONS_ARRAY[name]);
}

Piece& Piece::operator=(Piece other) noexcept {
  using std::swap;
  swap(position_, other.position_);
  swap(name_, other.name_);
  swap(suit_, other.suit_);
  return *this;
}

BitBoard& Piece::position() { return position_; }

const BitBoard& Piece::position() const { return position_; }

char Piece::name() const { return name_; }

Color Piece::suit() const { return suit_; }