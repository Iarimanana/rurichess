//
// Created by marshallmallow on 5/27/26.
//
#include "../include/pieces.h"

#include <stdexcept>

#include "constant.h"

using namespace rurichess;

Piece::Piece() : Piece(PieceNames::Wpawn) {}

Piece::Piece(const PieceNames name)
    : name_{kPiecesRepresentationsArray[static_cast<Int32>(name)]} {
  const auto n = static_cast<Int32>(name);
  suit_ = ((n + 1) % 2 == 0) ? Color::Black : Color::White;
  position_ = BitBoard(kPiecesPositionsArray[n]);
}

Piece::Piece(const Int32 name) : name_{kPiecesRepresentationsArray[name]} {
  if (name >= kPieceArrayLen)
    throw std::invalid_argument("The name of the piece is invalid.");

  suit_ = ((name + 1) % 2 == 0) ? Color::Black : Color::White;
  position_ = BitBoard(kPiecesPositionsArray[name]);
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